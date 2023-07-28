// topsort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <cassert>
#include <fstream>
#include <iostream>
#include "DALGraph.h"
#include "queue.h"
#include "Stack.h"

using namespace std;


int main()
{
	cout << "20192628 임지혁" << endl;
	// read graph from a file
	// first entry is size of graph
	const char * inFileName = "graph.dat";
	ifstream ifs(inFileName);
	assert(ifs); 
	// make sure graph exists
	int n;
	ifs >> n;
	DALGraph G(n);
	cout << "Created graph; n = " << G.vertexSize() << endl;
	// now read in the edges and add to the graph
	int u, v;
	while ( ifs >> u ) 
	{
		ifs >> v;
		G.addEdge(u,v); //g생성
	}
	cout << "Edges in graph: m = " << G.edgeSize() << endl; 
	// count the number of in-edges for each vertex
	int * vertices(new int[n]); //vertices는 inedge의 갯수
	assert(vertices);

	for (u = 0; u < n; u++)
		vertices[u] = 0; //초기화
	for (u = 0; u < n; u++)
	{
		NeighborIter ni(G,u); //g에서 u->v일때, u의 옆을 찾아
		while ((v = ++ni) != n)
			vertices[v]++; //u->v가 있으면, v의 inedge갯수 증가
	}
	//다찾음

	Stack < int > s; 
	for (u = 0; u < n; u++)
		if (vertices[u] == 0) //inedge가 없는 애들  찾아서 , 들어가!!s에!!
			s.push(u); 
	if (s.isEmpty()) //오잉? 아무도없네? 싸이클놈
	{ 
		cout << "graph has a cycle!\n"; 
		return 0; 
	}

	int count = 0; // 처리 완료된 vertex갯수
	Queue < int > sortedEdges; // 정렬완료된애들
	while (!s.isEmpty()) //뽑아올게 있으면 ,
	{
		count++; //한개 처리할거야~
		u = s.pop(); // 일단 inedge없는애를 찾아서 
		sortedEdges.enqueue(u); //그걸 넣어서
		// reduce in count for u's neighbors;
		// for each that goes to zero, put on stack
		NeighborIter ni(G,u); //그때, 없는애 기준으로 (u로 잡아) 서 v찾아
		while ((v = ++ni) != n) //다음꺼가 있어! u->v 일때, 
		{ 
			--vertices[v]; //축하해 v야, inedge가 줄었어.
			if (vertices[v] == 0) //근데 끝났어
				s.push(v); //inedge 0인 s에 들어가!!
		}
	}
	if (count < n)
		cout << "Couldn't complete top sort --cycle present.\n"; 
	cout << "Ordering for top sort: \n";
	while (!sortedEdges.isEmpty())
		cout << sortedEdges.dequeue() << '\t';
	cout << endl; 
	return n;
}
