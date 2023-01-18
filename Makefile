CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -Werror -pedantic # -save-temps

OBJ=main.o

TARGET=main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

check: ${TARGET}
	./${TARGET}

clean:
	$(RM) $(TARGET) $(OBJ)
