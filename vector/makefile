CXX = clang++
CXXFLAGS = -std=c++17 -O3

SRCS = main.cpp generatorius.cpp calculate.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

all: main

main: $(OBJS)
	$(CXX) -o $@ $(OBJS) $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJS)

.DEFAULT_GOAL := all

all: | clean
