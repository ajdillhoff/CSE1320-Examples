#include <iostream>
#include <unordered_map>

using namespace std;

class User {
    int id_;
    string name_;
    string email_;

    public:
        User(int id, string name, string email) : id_{id}, name_{name}, email_{email} {}
        User() {}

        auto & id() const { return id_; }
        auto & name() const { return name_; }
        auto & email() const { return email_; }

        friend ostream& operator<<(ostream& os, const User& u) {
            return os << "{ " << u.id() << ", \"" << u.name() << "\", \"" << u.email() << "\" }";
        }
};

namespace std {
    template<>
        struct hash<User> {
            size_t operator()(User const& u) const {
                return hash<string>()(u.email()) ^ hash<int>()(u.id());
            }
        };
}

int main() {
    // decltype returns a type given some expression
    unordered_map<string, User> user_map;
    user_map.emplace("Naomi Nagata", User{1, "Naomi Nagata", "naomi@rocinante.sp"});
    user_map.emplace("James Holden", User{2, "James Holden", "captain@rocinante.sp"});
    user_map.emplace("Amos Burton", User{3, "Amos Burton", "amos@rocinante.sp"});
    user_map.emplace("Alex Kamal", User{4, "Alex Kamal", "kamal@mcrn.mars"});
    user_map.emplace("Bobbie Draper", User{5, "Bobbie Draper", "draper@mcrn.mars"});

    // Using the [] will return 0 if no key is found.
    auto result = user_map["Chrisjen Avasarala"];
    cout << result << endl;

    try {
        result = user_map.at("Naomi Nagata");
        cout << result << endl;
    } catch(out_of_range& e) {
        cout << "Key not found!" << endl;
    }

    return 0;
}
