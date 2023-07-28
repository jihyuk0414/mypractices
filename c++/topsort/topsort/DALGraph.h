#pragma once
#include "ALGraph.h"
#include <cassert>

class DALGraph : public ALGraph
{ 
public:
	DALGraph(int size) : ALGraph(size) { }
	virtual void addEdge(int fromV, int toV);  //디테일 한 있다 부분 
};

void DALGraph::addEdge(int fromV, int toV)
{ 
	assert(fromV < n&& fromV >= 0 && toV < n&& toV >= 0);
	vertexList[fromV].insert(toV); 
	m++;  
}
