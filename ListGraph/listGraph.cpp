#include "listGraph.h"
#include <string.h>
#include <queue>
#include <stack>

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
bool listGraph<VertexType, EdgeType>::insert(int from, int to, EdgeType w)
{
	if (exist(from, to)) return false;
	edgeList *p = nodeList[from].head;
	while (p != NULL)	p = p->next;
	p->next = new edgeList(to, w);
	return true;
}

template<class VertexType, class EdgeType>
bool listGraph<VertexType, EdgeType>::remove(int from, int to)
{
	if (exist(from, to)) return false;
	edgeList *p = nodeList[from].head,*q;
	while (p != NULL && p->node != to) p = p->next;
	if(p == NULL) return false;
	q = p;
	p = p->next;
	q->next = p->next;
	delete p;
}

template<class VertexType, class EdgeType>
bool listGraph<VertexType, EdgeType>::exist(int from, int to)
{
	edgeList *p = nodeList[from].head;
	while (p != NULL && p->node != to) p = p->next;
	if (p == NULL) return false;
	return true;
}

template<class VertexType, class EdgeType>
void listGraph<VertexType, EdgeType>::BFS()
{
	memset(visited, false, sizeof(visited));
	queue<int> que;
	que.push(0);
	edgeList *head;
	while (!que.empty()) {
		int temp = que.front();
		que.pop();
		if (!visited[temp]) {
			visited[temp] = true;
			cout << nodeList[temp].name << " ";
			head = nodeList[temp].head;
			while (head != NULL) {
				que.push(head->node);
				head = head->next;
			}
		}
	}
	cout << endl;
}

template<class VertexType, class EdgeType>
void listGraph<VertexType, EdgeType>::DFS()
{
	memset(visited, false, sizeof(visited));
	stack<int> sta;
	sta.push(0);
	edgeList *head;
	while (!sta.empty()) {
		int temp = sta.top();
		sta.pop();
		if (!vivited[temp]) {
			head = nodeList[temp].head;
			cout << nodeList[temp].name << " ";
			while (head != NULL) {
				sta.push(head->node);
				head = head->next;
			}
		}
	}
	cout << endl;
}

template<class VertexType, class EdgeType>
void listGraph<VertexType, EdgeType>::topSort()
{
	queue<int> que;
	int *curNum = new int[verNum];
	edgeList *p;
	memset(visited, false, sizeof(visited));	
	memset(curNum, 0, sizeof(curNum));
	for (int index = 0; index < verNum; index++) {
		p = nodeList.head;
		while (p != NULL) {
			curNum[p->node]++;
			p = p->next;
		}
	}
	for (int index = 0; index < verNum; index++) {
		if (curNum[index] == 0)
			que.push(index);
		curNum[index] = -1;
	}
	while (!que.empty) {
		int n = que.front();
		que.pop();
		p = nodeList.head;
		while (p != NULL) {
			curNum[p->node]--;
			p = p->next;
		}
		for (int index = 0; index < verNum; index++) {
			if (curNum[index] == 0)
				que.push(index);
		}
	}
}

template<class VertexType, class EdgeType>
listGraph<VertexType, EdgeType>::~listGraph()
{
	edgeList *p, *q;
	for (int index = 0; index < verNum; index++) {
		p = nodeList[index].head;
		while (p != NULL) {
			q = p;
			p = p->next;
			delete q;
		}
	}
	delete[]nodeList;
	delete[]visited;
}

