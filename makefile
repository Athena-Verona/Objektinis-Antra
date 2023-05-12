CXX = clang++
CXXFLAGS = -std=c++17 -O3 -pthread
LDFLAGS = -lgtest -lgtest_main

SRCS = main.cpp generatorius.cpp calculate.cpp
OBJS = $(SRCS:.cpp=.o)

TEST_SRCS = test.cpp generatorius.cpp calculate.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

.PHONY: all clean test

all: main test

main: $(OBJS)
	$(CXX) -o $@ $(OBJS) $(CXXFLAGS) $(LDFLAGS)

test: $(TEST_OBJS)
	$(CXX) -o $@ $(TEST_OBJS) $(CXXFLAGS) $(LDFLAGS)
	./test

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJS) $(TEST_OBJS) main test

.DEFAULT_GOAL := all
