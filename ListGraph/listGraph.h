#pragma once
#include "graph.h"

template <class VertexType, class EdgeType>
class listGraph:public graph
{
public:
	listGraph();
	~listGraph();
	void createGraph(const VertexType V[], const EdgeType E[]);
	bool insert(int from, int to, EdgeType w);
	bool remove(int from, int to);
	bool exist(int from, int to);
	void BFS();		// 广度优先搜索实现
	void DFS();		// 深度优先搜索实现
	void topSort();	// 拓补排序实现
private:
	struct edgeList {
		int weight;			// 权值
		edgeList *next;		// 指向下一个节点
		int node;			// 表示该边界点所指向的节点列表中的第几个节点
	};
	struct NodeList {
		edgeList *head;		// 表示边界点的头指针
	};

	NodeList nodeList;		
};