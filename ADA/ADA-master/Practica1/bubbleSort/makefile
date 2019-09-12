OPTS = -Wall -O3 -std=c++0x

bubbleSort: bubbleSort.cc
	g++ ${OPTS} -o bubbleSort bubbleSort.cc	 

bubbleSort.CPUtimes: bubbleSort
	./bubbleSort > bubbleSort.CPUtimes

graphs: bubbleSort.CPUtimes bubbleSort.gnuplot
	gnuplot bubbleSort.gnuplot

all: bubbleSort bubbleSort.CPUtimes graphs
