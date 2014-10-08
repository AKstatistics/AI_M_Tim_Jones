#include "./graph_api/Graph.h"
#include <iostream>

void dls( Graph &g, int root, int goal, int limit );

int main()
{
	enum {A, B, C, D, E, F, G, H };

	Graph tree( 8 );

	tree( A, B ) = 1;
	tree( A, C ) = 1;
	tree( B, D ) = 1;
	tree( C, E ) = 1;
	tree( C, F ) = 1;
	tree( D, G ) = 1;
	tree( D, H ) = 1;

	dls( tree, A, F, 7 );

	return 0;
}
