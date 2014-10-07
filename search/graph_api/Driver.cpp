#include "Graph.h"
#include <iostream>

int main()
{
	Graph graph(5);
	graph(0,1) = 1;
	graph(1,2) = 1;
	graph(1,3) = 1;

	graph.makeUndirected();

	std::cout << graph(0,1) << std::endl;
	std::cout << graph(1,0) << std::endl;
}
