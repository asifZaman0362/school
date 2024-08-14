CXX := g++
CXXFLAGS := -O2 -Wall -Iinc -std=c++17

ifeq ($(shell uname), Darwin)
	sysroot := $(shell xcrun --show-sdk-path)
else
	sysroot :=
endif

CXXFLAGS += -isysroot $(sysroot)

all: ds.o
	if [ ! -d build ]; then mkdir build; fi
	$(CXX) build/ds.o -o build/ds

utils: inc/util/result.hpp

ds.o: utils inc/ds/list.hpp src/ds/list.cc
	$(CXX) $(CXXFLAGS) -c src/ds/list.cc -o build/ds.o

clean:
	rm build/*
