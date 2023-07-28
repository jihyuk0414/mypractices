#pragma once

class graph
{
public:
	graph(int size) : n(size), m(0) { }
	virtual int vertexSize() { return n; }
	virtual int edgeSize() { return m; }
	virtual void addEdge(int fromV, int toV) = 0; // 꼭 virtual // 있다정도만 얘기해ㅏ는것
protected:
	int n; // number of vertices
	int m; // number of edges
};


