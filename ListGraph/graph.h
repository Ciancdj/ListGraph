#pragma once
template <class VertexType,class EdgeType>
class graph
{
public:
	virtual void createGraph(const VertexType V[], const EdgeType E[]);
	virtual bool insert(int from, int to, EdgeType w);
	virtual bool remove(int from, int to);
	virtual bool exist(int from, int to);
	virtual void BFS();		// 广度优先搜索实现
	virtual void DFS();		// 深度优先搜索实现
	virtual void topSort();	// 拓补排序实现
};

