#include "./graph_api/Graph.h"
#include "./stack_api/Stack.h"
#include <iostream>

void dfs( Graph g, int root, int goal )
{
	int node;
	int to;
	int i = 0;

	Stack search;

	search.addNode( root );

	while( !search.isEmpty() )
	{
		node = search.lifo();

		std::cout << i << ": " << node << std::endl;

		if( node == goal ) break;

		for( to = g.nodes() - 1; to >= 0; to--)
		{
			if( g( node, to ) )
			{
				search.addNode( to );
			}
		}

		i++;
	}
	
	search.displayStack();
	search.displayDone();
}

