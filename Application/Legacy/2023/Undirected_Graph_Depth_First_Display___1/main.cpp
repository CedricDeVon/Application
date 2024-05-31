#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class UndirectedGraph
{
public:
	std::map<int, bool> visited;
	std::map<int, std::list<int>> nodes;

	void addEdge(int node, int target);
	void displayViaDepthFirstTraversal(int root);
};

void UndirectedGraph::addEdge(int node, int target)
{
	nodes[node].push_back(target);
}

void UndirectedGraph::displayViaDepthFirstTraversal(int root)
{
	visited[root] = true;
	std::cout << root << " ";
	for (std::list<int>::iterator i = nodes[root].begin(); i != nodes[root].end(); ++i)
	{
		if (!visited[*i])
		{
			displayViaDepthFirstTraversal(*i);
		}
	}
}

int main(void)
{
	UndirectedGraph graph;
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(0, 3);
	graph.addEdge(1, 0);
	graph.addEdge(2, 0);
	graph.addEdge(2, 4);
	graph.addEdge(2, 3);
	graph.addEdge(3, 0);
	graph.addEdge(3, 2);
	graph.addEdge(4, 2);

	graph.displayViaDepthFirstTraversal(0);

	int exit_code = 0;
	std::cin >> exit_code;
	return 0;
}

