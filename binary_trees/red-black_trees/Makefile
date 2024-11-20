BUILD_DIR := ./build
SRC_DIR := ./src

TEST_SRC := $(SRC_DIR)/test_all.c $(SRC_DIR)/rb_utils.c ./libs/unity/src/unity.c
TEST_OBJS := $(TEST_SRC:%=$(BUILD_DIR)/%.o)

RUN_TESTS := $(BUILD_DIR)/run_tests

test: $(RUN_TESTS)
	$(RUN_TESTS)

$(RUN_TESTS): $(TEST_OBJS)
	$(CC) $(TEST_OBJS) -o $@

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -g -I./libs/unity/src -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)