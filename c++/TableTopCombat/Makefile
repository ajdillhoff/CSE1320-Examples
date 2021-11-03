TARGET_EXEC := TableTopCombat

BUILD_DIR := ./build
SRC_DIR := ./src

SRCS = $(wildcard $(SRC_DIR)/*.cpp)

RELEASE := $(BUILD_DIR)/$(TARGET_EXEC)

release: $(SRCS)
	mkdir -p $(dir $(RELEASE))
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(RELEASE)

clean:
	rm -rf $(BUILD_DIR)
