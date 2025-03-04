# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -O2
TARGET = main
TEST_TARGET = test_runner

# Source and object files
SRCS = main.c functions.c
OBJS = $(SRCS:.c=.o)

# Test files
TEST_SRCS = test.c functions.c munit/munit.c
TEST_OBJS = $(TEST_SRCS:.c=.o)

# Default rule
all: $(TARGET)

# Link object files to create the main executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile .c files into .o files
%.o: %.c functions.h
	$(CC) $(CFLAGS) -c $< -o $@

# Compile and run tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Build test executable
$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(CFLAGS) -I munit -o $(TEST_TARGET) $(TEST_OBJS)

# Clean up all object files and executables
clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)

# Clean test-related files only
clean_test:
	rm -f $(TEST_OBJS) $(TEST_TARGET)
