#pragma once
#include "graph.h"

template <class VertexType, class EdgeType>
class listGraph:public graph
{
public:
	listGraph(int verSize);
	~listGraph();
	void createGraph(const VertexType V[], const EdgeType E[]);
	bool insert(int from, int to, EdgeType w);
	bool remove(int from, int to);
	bool exist(int from, int to);
	void BFS();		// �����������ʵ��
	void DFS();		// �����������ʵ��
	void topSort();	// �ز�����ʵ��
protected:
	int verNum,edgeNum;		// ��ʾ�ڵ������
private:
	struct edgeList {
		EdgeType weight;			// Ȩֵ
		edgeList *next;		// ָ����һ���ڵ�
		int node;			// ��ʾ�ñ߽����ָ��Ľڵ��б��еĵڼ����ڵ�
		edgeList(int n ,EdgeType e, edgeList a = NULL) {
			node = n;
			weight = e;
			next = a;
		}
	};
	struct NodeList {
		edgeList *head;		// ��ʾ�߽���ͷָ��
		VertextType name;   // ��ʾ�ýڵ������
		NodeList(VertexType v, edgeList a = NULL) {
			name = v;
			head = a;
		}
	};
	NodeList nodeList;
	bool *visited;			// ��������������
};