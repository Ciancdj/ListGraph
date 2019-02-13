#include "listGraph.h"


template<class VertexType, class EdgeType>
listGraph<class VertexType, class EdgeType>::listGraph(int verSize)
{
	verNum = verSize;
	edgeNum = 0;
	nodeList = new NodeList[verNum];
	visited = new bool[verNum];
}

template<class VertexType, class EdgeType>
void listGraph<VertexType, EdgeType>::createGraph(const VertexType V[], const EdgeType E[])
{
	edgeList *edge, *temp;
	for (int index = 0; index < verNum; index++) {
		nodeList[index] = new NodeList(V[index]);
	}
	for (int index = 0; index < verNum; index++) {
		edgeNum = 0;
		for (int j = 0; j < verNum; j++) {
			if (E[index][j] != 0) {
				if (edgeNum++ == 0) {
					edge = new edgeList(j, E[index][j]);
					nodeList[index].head = edge;
				}
				else {
					temp = edge;
					edge = new edgeList(j, E[index][j]);
					temp->next = edge;
				}
			}
		}
	}
}

template<class VertexType, class EdgeType>
listGraph<VertexType, EdgeType>::~listGraph()
{

}
