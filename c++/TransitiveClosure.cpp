﻿// TransitiveClosure.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <cassert>
#include <iostream>
#include "amGraph.h"
#include "graph.h"
#include "UAMGraph.h"
#include <fstream>

using namespace std;

int main()
{
	cout << "20192628 임지혁" << endl;
	const char* inFileName = "graph2.dat";// read graph from a file// first entry is size of graph
	ifstream ifs(inFileName);
	assert(ifs); 
	int n; 
	ifs >> n;
	uAMGraph G(n); 
	cout << "Created graph; n = " << G.vertexSize() << endl; 
	int u, v;
	while (ifs >> u) 
	{ 
		ifs >> v; G.addEdge(u, v); 
	}

	cout << "Edges in graph: m = " << G.edgeSize() << endl; 
	int step;
	for (step = 0; step < n; step++)
		for (u = 0; u < n; u++)
			for (v = 0; v < n; v++)
				if (G.edgeMember(u, step) && G.edgeMember(step, v))
					G.addEdge(u, v);// print results
	for (u=0; u < n; u++) 
	{
		cout << u << "\t: ";
		for (v = 0; v < n; v++)
			cout << (G.edgeMember(u,v)? "T " : "F ");
		cout << endl;
	}
	return 0;
}

