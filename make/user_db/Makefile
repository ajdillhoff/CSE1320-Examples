# # Makefile Version 1
# # Demonstrates a simple Makefile.

# # CFLAGS, CC, and VPATH are implicit variables.
# CFLAGS = -Wall -Wextra
# CC = gcc
# VPATH = src

# # Rule to build the executable, dependent on the object files.
# user_db : main.o user.o array_utils.o utils.o
# 	$(CC) $(CFLAGS) $^ -o $@

# # Rules to build the object files, dependent on the source files.
# main.o : main.c
# 	$(CC) $(CFLAGS) -c $? -o $@

# user.o : user.c
# 	$(CC) $(CFLAGS) -c $? -o $@

# array_utils.o : array_utils.c
# 	$(CC) $(CFLAGS) -c $? -o $@

# utils.o : utils.c
# 	$(CC) $(CFLAGS) -c $? -o $@


# # Makefile Version 2
# # Adds a build directory to keep the project directory organized.

# # CFLAGS, CC, and VPATH are implicit variables.
# CFLAGS = -Wall -Wextra
# CC = gcc
# VPATH = src:build

# # Rule to build the executable, dependent on the object files.
# build/bin/user_db : main.o user.o array_utils.o utils.o
# 	mkdir -p build/bin
# 	$(CC) $(CFLAGS) $^ -o $@

# # Rules to build the object files, dependent on the source files.
# build/main.o : main.c
# 	mkdir -p build
# 	$(CC) $(CFLAGS) -c $? -o $@

# build/user.o : user.c
# 	$(CC) $(CFLAGS) -c $? -o $@

# build/array_utils.o : array_utils.c
# 	$(CC) $(CFLAGS) -c $? -o $@

# build/utils.o : utils.c
# 	$(CC) $(CFLAGS) -c $? -o $@

# # Makefile Version 3
# # Adds rules to clean up the build directory.

# # CFLAGS, CC, and VPATH are implicit variables.
# CFLAGS = -Wall -Wextra
# CC = gcc
# VPATH = src:build

# # Rule to build the executable, dependent on the object files.
# build/bin/user_db : main.o user.o array_utils.o utils.o
# 	mkdir -p build/bin
# 	$(CC) $(CFLAGS) $^ -o $@

# # Rules to build the object files, dependent on the source files.
# build/main.o : main.c
# 	mkdir build
# 	$(CC) $(CFLAGS) -c $? -o $@

# build/user.o : user.c
# 	$(CC) $(CFLAGS) -c $? -o $@

# build/array_utils.o : array_utils.c
# 	$(CC) $(CFLAGS) -c $? -o $@

# build/utils.o : utils.c
# 	$(CC) $(CFLAGS) -c $? -o $@

# # PHONY indicates that the target is not a file.
# .PHONY = clean
# clean:
# 	rm -rf build

# .PHONY = run
# run: build/bin/user_db
# 	./build/bin/user_db

# Makefile Version 4
# Uses the wildcard function to automatically generate the object files.

# CFLAGS, CC, and VPATH are implicit variables.
CFLAGS = -Wall -Wextra
CC = gcc
SRC_DIR = src
BUILD_DIR = build

SRCS := $(wildcard $(SRC_DIR)/*.c)
# src/main.c
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
# build/src/main.c.o

RELEASE := $(BUILD_DIR)/bin/user_db
DEBUG := $(BUILD_DIR)/bin/user_db_debug

# Rule to build the executable, dependent on the object files.
$(RELEASE) : $(OBJS)
	mkdir -p $(BUILD_DIR)/bin
	$(CC) $(CFLAGS) $^ -o $@

$(DEBUG) : $(OBJS)
	mkdir -p $(BUILD_DIR)/bin
	$(CC) $(CFLAGS) -g -DDEBUG $^ -o $@

# Rules to build the object files, dependent on the source files.
$(BUILD_DIR)/%.c.o : %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# PHONY indicates that the target is not a file.
.PHONY = clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY = run
run: $(RELEASE)
	./$(RELEASE)