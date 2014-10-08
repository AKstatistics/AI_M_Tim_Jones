// NOTE: The Stack object will automatically not add nodes to the queue which are already queued or have been once dequeued (already searched).

#include "./graph_api/Graph.h"
#include "./stack_api/Stack.h"
#include <iostream>
#include <vector>

void dls( Graph &g, int root, int goal, int limit )
{
	int node, to;
	int depth = 0;
	int i = 0;

	Stack search( root );		// Stores the queue of 
	std::vector<int> searchDepth;	// Stores the depth of the queued node.
	std::vector<int> path;		// Stores the path to the current node being search.
	searchDepth.push_back(0);
	path.push_back(0);

	while( !search.isEmpty() )
	{
		node = search.lifo();	// Pop out the next node to search for the stack

		if(searchDepth[searchDepth.size() - 1] > depth)	// If we have increased the depth the add the node to the path
			path.push_back( node );

		if(searchDepth[searchDepth.size() - 1] <= depth) // If we have remained at the same depth or decreased in depth (gone back up the graph) 
		{
			for( int i = 0; i <= depth - searchDepth[searchDepth.size() - 1]; i++ ) // Then for each level we went back up
				path.pop_back();	// Remove a node from the path we took
			path.push_back( node );		// And add the current node to the stack
		}
		
		depth = searchDepth[searchDepth.size() - 1];	// Now save the depth of the current node
		searchDepth.pop_back();				// and remove that from the depth list.
		
		std::cout << i << ": " << node << std::endl;

		if( node == goal ) break;	// If we found our goal, quit.
		if( depth < limit )		// If we havent gone deeper than our limit...
		{
			for( to = g.nodes()-1; to >=0; to-- )	// For each node in the graph
			{
				if( g( node, to ) && search.addNode( to ))	// If the nodes are connected try adding the node, to.
				{
					searchDepth.push_back( depth + 1 );	// Add the depth.
				}
			}
		}
	}	
	
	std::cout << "Path found: " << std::endl;
	for( std::vector<int>::size_type i = 0; i < path.size(); i++ )
		std::cout << path[i] << std::endl;
}
