CXX = c++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -O2

.PHONY: test clean

test: build/search_tests
	./build/search_tests

build/search_tests: tests/search_tests.cpp src/naive.cpp src/kmp.cpp src/search.hpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) -Isrc tests/search_tests.cpp src/naive.cpp src/kmp.cpp -o $@

clean:
	rm -rf build
