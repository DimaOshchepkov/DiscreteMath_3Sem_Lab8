#include "Header.h"

void CreateFile(std::string name)
{
	std::ofstream fout(name);
	std::cout << "Inpute count tops\n";
	int countTop = 0;
	std::cin >> countTop;
	std::cout << "Input count edges\n";
	int countEdges = 0;
	std::cin >> countEdges;

	fout << countTop << ' ' << countEdges << '\n';

	std::cout << "Enter edges in format top - top";
	for (int i = 0; i < countEdges; i++)
	{
		int x, y;
		std::cin >> x >> y;
		fout << x << " " << y << '\n';
	}
	fout.close();
}

std::vector<std::list<int>> ReadFile(std::string name)
{
	std::ifstream fin(name);
	int countTop = 0, countEdges = 0;
	fin >> countTop >> countEdges;

	std::vector<std::list<int>> graph(countTop);
	for (int i = 0; i < countEdges; i++)
	{
		int x, y;
		fin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	fin.close();

	return graph;
}


std::vector<std::list<int>> CountConnectivityComponent(std::vector<std::list<int>> graph)
{
	std::vector<bool> visited(graph.size(), false);
	std::list<int> q;

	std::vector<std::list<int>> components;
	int count = 0;
	for (int i = 0; i < graph.size(); i++)
	{
		if (!visited[i])
		{
			components.push_back({ i });
			q.push_back(i);
			visited[i] = true;
			while (q.size() != 0)
			{
				int front = q.back();
				q.pop_back();
				for (int top : graph[front]) {
					if (!visited[top])
					{
						q.push_back(top);
						components.back().push_back(top);
						visited[top] = true;
					}
				}
			}
		}
	}

	return components;

}