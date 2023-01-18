CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -Werror -pedantic # -save-temps

OBJ=main.o

TARGET=main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

check: ${TARGET}
	./${TARGET}

prof:
	g++ -DNDEBUG -O5 -std=c++17 -lpthread -W *.cc

clean:
	$(RM) $(TARGET) $(OBJ) a.out
