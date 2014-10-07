// NOTE: The Stack object will automatically not add nodes to the queue which are already queued or have been once dequeued (already searched).

#include "./graph_api/Graph.h"
#include "./stack_api/Stack.h"
#include <iostream>
#include <vector>

void dls( Graph g, int root, int goal, int limit )
{
	int node, depth, to;
	int i = 0;

	Stack search( root );		// Stores the queue of 
	std::vector<int> searchDepth;	// Stores the depth of the queued node.
	std::vector<int> parent;
	searchDepth.push_back(0);

	while( !search.isEmpty() )
	{
		node = search.lifo();
		depth = searchDepth[searchDepth.size() - 1];
		searchDepth.pop_back();
		
		std::cout << i << ": " << node << std::endl;

		if( node == goal ) break;
		if( depth < limit )
		{
			for( to = g.nodes()-1; to >=0; to-- )
			{
				if( g( node, to ) && search.addNode( to ))	// If the nodes are connected try adding the node, to.
				{
					parent.push_back( node );		// If the node is added successfully store the parent
					searchDepth.push_back( depth + 1 );	// and the depth.
				}
			}
		}
	}	

	search.displayStack();
	search.displayDone();
}
