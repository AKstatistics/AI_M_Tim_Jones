// NOTE: The Q object will automatically not add nodes to the queue which are already queued or have been once dequeued (already searched).

#include "./graph_api/Graph.h"
#include "./queue_api/Q.h"
#include <iostream>
#include <deque>

void bfs( Graph &g, int root, int goal )
{
	int node, to;
	int depth = 0;
	int i = 1;

	Q search( root );		// Stores the queue of 
	std::deque<int> searchDepth;	// Stores the depth of the queued node.
	std::vector<int> path;		// Stores the path to the current node being search.
	searchDepth.push_back(0);
	path.push_back( root );

	while( !search.isEmpty() )
	{
		node = search.fifo();	// Pop out the next node to search for the stack

		if(searchDepth[0] > depth)	// If we have increased the depth the add the node to the path
			path.push_back( node );

		if(searchDepth[0] <= depth) // If we have remained at the same depth or decreased in depth (gone back up the graph) 
		{
			for( int i = 0; i <= depth - searchDepth[0]; i++ ) // Then for each level we went back up
				path.pop_back();	// Remove a node from the path we took
			path.push_back( node );		// And add the current node to the stack
		}
		
		depth = searchDepth[0];		// Now save the depth of the current node
		searchDepth.pop_front();	// and remove that from the depth list.
		
		std::cout << i++ << ". Node: " << node << "  Depth: " << depth << std::endl;

		if( node == goal ) break;	// If we found our goal, quit.
		for( to = g.nodes()-1; to >=0; to-- )	// For each node in the graph
		{
			if( g( node, to ) && search.addNode( to ))	// If the nodes are connected try adding the node, to.
			{
				searchDepth.push_back( depth + 1 );	// Add the depth.
			}
		}
	}	
	
	std::cout << "Path found: " << std::endl;
	for( std::vector<int>::size_type i = 0; i < path.size(); i++ )
		std::cout << path[i] << std::endl;
}
