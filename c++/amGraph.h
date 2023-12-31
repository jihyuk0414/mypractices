#include "graph.h"
#include <cassert>

#pragma once

class amGraph : public graph
{
public:
	amGraph(int size);
	virtual bool edgeMember(int fromV, int toV);
protected:
	int** am; // am points to pointers to int};#endif
};

amGraph::amGraph(int size) : graph(size) {
	int i;
	am = new int* [n]; // make an array of pointers to int
	assert(am);
	for (i = 0; i < n; i++) {
		am[i] = new int[n];  // make an array of ints
		assert(am[i]);
		int j;
		for (j = 0; j < n; j++) // initialize the array to 0
			am[i][j] = 0;
	}
};

bool amGraph::edgeMember(int fromV, int toV) 
{
	assert(fromV < n&& toV < n&& fromV >= 0 && toV >= 0); 
	return bool(am[fromV][toV] != 0);
}