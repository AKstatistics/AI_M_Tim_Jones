#include "./graph_api/Graph.h"
#include <iostream>

void ids( Graph &g, int root, int goal, int limit );

int main()
{
	enum {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P };

	Graph tree( 16 );

	tree( A, B ) = 1;
	tree( A, C ) = 1;
	tree( A, D ) = 1;
	tree( B, E ) = 1;
	tree( B, F ) = 1;
	tree( C, G ) = 1;
	tree( C, H ) = 1;
	tree( D, I ) = 1;
	tree( D, J ) = 1;
	tree( G, K ) = 1;
	tree( G, L ) = 1;
	tree( I, M ) = 1;
	tree( J, N ) = 1;
	tree( M, O ) = 1;
	tree( M, P ) = 1;

	ids( tree, 0, O, 2 );

	return 0;
}
