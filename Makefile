CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

# Automatically find all .cpp source files in the current directory
SOURCES = $(wildcard *.cpp)

# List all your header file paths here
# INCLUDES = -I/path/to/your/header/files -I/another/header/path

# Generate object file names from source file names
OBJECTS = $(SOURCES:.cpp=.o)

vkcppApp: $(OBJECTS)
	g++ $(CFLAGS) -o vkcppApp $(OBJECTS) $(LDFLAGS)

.PHONY: test clean

test: vkcppApp
	./vkcppApp

clean:
	rm -f vkcppApp $(OBJECTS)
