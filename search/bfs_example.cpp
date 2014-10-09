#include "./graph_api/Graph.h"
#include <iostream>

void bfs( Graph &g, int root, int goal );

int main()
{
	enum { A, B, C, D, E, F, G, H, I, J, K, L, M, N };
	Graph tree( 14 );

	tree( A, B ) = 1;
	tree( A, C ) = 1;
	tree( B, D ) = 1;
	tree( B, E ) = 1;
	tree( C, F ) = 1;
	tree( D, G ) = 1;
	tree( E, H ) = 1;
	tree( F, H ) = 1;
	tree( G, I ) = 1;
	tree( H, J ) = 1;
	tree( H, K ) = 1;
	tree( I, L ) = 1;
	tree( J, L ) = 1;
	tree( K, M ) = 1;
	tree( L, N ) = 1;
	tree( M, N ) = 1;
	tree( E, N ) = 1;

	tree.makeUndirected();

	bfs( tree, A, N );

	return 0;
}
