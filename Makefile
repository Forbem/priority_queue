CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = test-queue
SRC = test-queue.cpp
HEADERS = priority-queue.h

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
