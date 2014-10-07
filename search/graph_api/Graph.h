#ifndef GRAPH_H
#define GRAPH_H



class Graph
{
	private:
		unsigned int 	mNodes;		// Number of nodes
		double* 	mpWeights;	// Weights of connections
		double		mTemp;		// This is returned when () receives an invalid input
	public:
		// Constructor
		Graph( const int nodes );

		// Accessor for number of nodes
		int nodes();

		// Gives access to the weight connecting two nodes 
		double& operator()( const int from, const int to );	

		// Makes matrix symmetric about the main diagonal
		// Copies upper right triangle to the lower left triangle
		// This has the effect of making all connections bi-directional
		void makeUndirected();

		// Destructor
		~Graph();


};


#endif
