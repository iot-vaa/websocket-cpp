CXX = clang++
CXXFLAGS = -std=c++11 -I/usr/local/Cellar/nlohmann-json/3.7.3/include
LDFLAGS = -lcurl

all: main

main: main.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $< -o $@

clean:
	rm -f main
