# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Executable Name
TARGET = cgrep

# Source files
SRCS := $(SRC_DIR)/main.c \
        $(SRC_DIR)/search_file/search_file.c

# Object files
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Include directories
INC_DIRS := $(SRC_DIR) \
            $(SRC_DIR)/search_file

CFLAGS += $(foreach dir,$(INC_DIRS),-I$(dir))

# Default Target
all: directories $(TARGET)

# Create necessary directories
directories:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/search_file

# Print Variables for Debugging
debug:
	@echo "Source files:"
	@echo "$(SRCS)"
	@echo "\nObject files:"
	@echo "$(OBJS)"
	@echo "\nInclude directories:"
	@echo "$(INC_DIRS)"

# Build the Executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

# Compile Source Files into Object Files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Build Artifacts
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Phony Targets
.PHONY: all clean debug directories
