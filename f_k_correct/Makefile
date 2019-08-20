CC=g++

all: dfa DFA_minimizer

dfa: dfa.hpp dfa.cpp
	$(CC) -Wall -std=c++17 -O3 dfa.cpp -o dfa

DFA_minimizer: DFA_minimizer.cc
	$(CC) -Wall -std=c++11 DFA_minimizer.cc -o DFA_minimizer

clean:
	rm -f dfa
	rm -f DFA_minimizer

.PHONY: all clean
