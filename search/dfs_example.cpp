#include "./graph_api/Graph.h"

void dfs( Graph& g, int root, int goal );

int main()
{
	enum {A, B, C, D, E, F, G, H };

	Graph tree( 8 );

	tree( A, B ) = 1;
	tree( B, C ) = 1;
	tree( C, D ) = 1;
	tree( C, E ) = 1;
	tree( A, F ) = 1;
	tree( F, G ) = 1;
	tree( F, H ) = 1;

	dfs( tree, A, H );

	return 0;
}
