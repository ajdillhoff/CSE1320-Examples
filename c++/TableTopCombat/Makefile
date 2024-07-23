TARGET_EXEC := TableTopCombat
CXXFLAGS := -std=c++14

BUILD_DIR := ./build
SRC_DIR := ./src

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

RELEASE := $(BUILD_DIR)/$(TARGET_EXEC)

release: $(OBJS)
	mkdir -p $(dir $(RELEASE))
	$(CXX) $(OBJS) -o $(RELEASE)

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
