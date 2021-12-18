# Compiler / Linker configs
CC        := gcc
CC_FLAGS  := -c         \
             -W         \

# Directories
SRC_DIR      := src
INCLUDE_DIR  := include
LIB_DIR      := lib
BIN_DIR      := bin
OBJ_DIR      := build
TESTS_DIR    := tests
TEMPLATE_DIR := templates
PREFIX       := /usr/local

# Filenames
TARGET       := main
TEST_TARGET  := main_tests
SRC          := $(wildcard $(SRC_DIR)/*.c)
H_SRC        := $(wildcard $(INCLUDE_DIR)/*.h)
OBJ          := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#
# Compilation and linking
#
all: binFolder objFolder $(TARGET)

$(TARGET): $(OBJ)
	@echo "🚀 Building binary \"$@\" using GCC linker..."
	@$(CC) $^ -o $(BIN_DIR)/$@
	@echo "🎇 Build complete!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "🪛  Compiling object file: $@..."
	@$(CC) $(CC_FLAGS) $< -I $(INCLUDE_DIR)/ -o $@

objFolder:
	@mkdir -p $(OBJ_DIR)

binFolder:
	@mkdir -p $(BIN_DIR)

# Cleaning binaries and static libraries (object files)
clean:
	@echo "🧹 Cleaning..."
	@rm -r $(OBJ_DIR)
	@rm -r $(BIN_DIR)
	@echo "🧹 Done!"

# Running the project
run:
	@./$(BIN_DIR)/$(TARGET)

.PHONY: all clean run
