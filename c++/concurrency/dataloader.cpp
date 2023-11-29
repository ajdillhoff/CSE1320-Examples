#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <atomic>

using namespace std;

class ThreadSafeQueue {
public:
    void push(const vector<string>& batch) {
        lock_guard<mutex> lock(m_mutex);
        m_queue.push(batch);
        m_cond.notify_one();
    }

    bool pop(vector<string>& batch) {
        unique_lock<mutex> lock(m_mutex);
        while (m_queue.empty() && !finished) {
            m_cond.wait(lock);
        }
        if (m_queue.empty() && finished) {
            return false;
        }
        batch = m_queue.front();
        m_queue.pop();
        return true;
    }

    void setFinished() {
        lock_guard<mutex> lock(m_mutex);
        finished = true;
        m_cond.notify_all();
    }

private:
    queue<vector<string>> m_queue;
    mutex m_mutex;
    condition_variable m_cond;
    bool finished = false;
};

void processBatch(const vector<string>& batch) {
    // Implement batch processing logic here
    for (const auto& line : batch) {
        cout << line << endl; // Example processing: print each line
    }
}

void worker(ThreadSafeQueue& queue) {
    while (true) {
        vector<string> batch;
        if (!queue.pop(batch)) {
            break; // No more batches to process
        }
        processBatch(batch);
    }
}

int main(int argc, char **argv) {
    ThreadSafeQueue queue;
    const string filename = argv[1]; // Replace with your file path
    const int batchSize = 10;
    const int numThreads = 4;

    // Start worker threads
    vector<thread> workers;
    for (int i = 0; i < numThreads; ++i) {
        workers.emplace_back(worker, ref(queue));
    }

    // Read file and prepare batches
    ifstream file(filename);
    string line;
    vector<string> batch;
    while (getline(file, line)) {
        batch.push_back(line);
        if (batch.size() == batchSize) {
            queue.push(batch);
            batch.clear();
        }
    }
    // Push any remaining lines as a final batch
    if (!batch.empty()) {
        queue.push(batch);
    }

    // Signal that no more batches will be added
    queue.setFinished();

    // Wait for all worker threads to finish
    for (auto& worker : workers) {
        worker.join();
    }

    return 0;
}
