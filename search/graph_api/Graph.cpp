#include "Graph.h"
#include <iostream>
Graph::Graph( const int nodes )
{
	mNodes = 0;
	mTemp = -1.5;

	if( !(nodes > 0 && nodes <= 100) )
		return;
	mNodes = nodes;
	mpWeights = new double[mNodes*mNodes];

	for( int i = 0; i < mNodes*mNodes; i++ )
		mpWeights[i] = 0;
}

int Graph::nodes()
{
	return mNodes;
}

double& Graph::operator()(const int from, const int to )
{
	if( from != to && 0 <= from && from < mNodes && 0 <= to && to < mNodes )
		return mpWeights[from * mNodes + to];
	else
	{
		return mTemp;
	}
}

void Graph::makeUndirected()
{
	for( int i = 0; i < mNodes; i++)
	{
		for( int j = 0; j < mNodes; j++)
			if( i < j )
				(*this)(j,i) = (*this)(i, j);
	}
}

Graph::~Graph()
{
	delete [] mpWeights;
	mpWeights = nullptr;
}
