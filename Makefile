# Makefile for 8-puzzle solver
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Object files
OBJS = main.o puzzle.o solver.o heuristics.o utils.o

# Output binary
TARGET = eight_puzzle

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)
