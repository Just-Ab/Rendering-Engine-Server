CXX = g++
CXXFLAGS = -IInclude -I./Algebra/glm -g -std=c++17 -MMD -MP -fopenmp
LDFLAGS = -LLib -lglfw3dll -lgdi32 -lopengl32 -lassimp -fopenmp

SRC_DIRS = Src Src/Rendering Src/Window Src/Input Src/Physics Src/Rendering/Buffers Src/Rendering/Instances Src/Rendering/Resources Src/Rendering/OpenGl/glad Src/Game
SRCS_CPP = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))
SRCS_C = $(wildcard Src/Rendering/OpenGl/glad/glad.c)
SRCS = $(SRCS_CPP) $(SRCS_C)

BUILD_DIR = build
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)
OBJS := $(OBJS:%.c=$(BUILD_DIR)/%.o)

TARGET = Bin/app.exe

# Default target
all: $(TARGET)

# Link the binary from object files
$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Compile .cpp to .o and generate dependency files
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile .c to .o and generate dependency files
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependency files (ignore if they don’t exist yet)
-include $(OBJS:.o=.d)

# Run target
run: all
	./$(TARGET)

# Clean target
clean:
	rm -rf Bin build