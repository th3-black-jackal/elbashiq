# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -pthread -I./include

# Source and output directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Files and output
SOURCES = main.cpp $(SRC_DIR)/elbashiq_server.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = $(BUILD_DIR)/server

# Default target
all: $(TARGET)

# Build the target
$(TARGET): $(OBJECTS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(OBJECTS)

# Phony targets
.PHONY: all clean

