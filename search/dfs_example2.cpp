#include "./graph_api/Graph.h"

void dfs( Graph &g, int root, int goal );
void ids( Graph &g, int root, int goal, int limit );

int main()
{
	enum {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P };

	Graph tree( 16 );

	tree( L, P ) = 1;
	tree( A, B ) = 1;
	tree( D, A ) = 1;
	tree( H, P ) = 1;
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

	tree.makeUndirected();

	dfs( tree, P, A );

	ids( tree, P, A, 2 );

	return 0;
}
