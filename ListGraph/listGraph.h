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
	void BFS();		// �����������ʵ��
	void DFS();		// �����������ʵ��
	void topSort();	// �ز�����ʵ��
private:
	struct edgeList {
		int weight;			// Ȩֵ
		edgeList *next;		// ָ����һ���ڵ�
		int node;			// ��ʾ�ñ߽����ָ��Ľڵ��б��еĵڼ����ڵ�
	};
	struct NodeList {
		edgeList *head;		// ��ʾ�߽���ͷָ��
	};

	NodeList nodeList;		
};