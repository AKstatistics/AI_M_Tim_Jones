#include "Q.h"

using std::vector;

Q::Q()
{}

Q::Q( const unsigned int first )
{
	mQ.push_back( first );
}

// This function adds a node to the stack if it has not already been deque once.
// The function returns TRUE if the node was successfully added.
bool Q::addNode( const unsigned int node )
{
	bool duplicate = 0;	// This bool will be set to TRUE if the node has already been queued.
				// The opposite of this bool is TRUE when the node has successfully been added to the queue.

	for( deque<int>::size_type i = 0; i < mQ.size(); i++ )
	{
		if( mQ[i] == node )
		{ duplicate = 1; break;}
	}

	if( duplicate == 1 )
		return !duplicate;
	for( vector<int>::size_type i = 0; i < mHistory.size(); i++ )
	{
		if( mHistory[i] == node )
		{ duplicate = 1; break; }
	}

	if( duplicate == 1 )
		return !duplicate;

	mQ.push_back( node );

	return !duplicate;

}

const unsigned int Q::fifo()
{
	const unsigned int output = mQ.front();
	mQ.pop_front();

	mHistory.push_back( output );

	return output;
}

void Q::displayQ()
{
	std::cout << "Queue: " << std::endl;

	for( deque<int>::size_type i = 0; i < mQ.size(); i++ )
	{
		std::cout << mQ[i] << std::endl;
	}
}

void Q::displayHistory()
{
	std::cout << "History Queue: " << std::endl;

	for( vector<int>::size_type i = 0; i < mHistory.size(); i++ )
	{
		std::cout << mHistory[i] << std::endl;
	}
}

const unsigned int Q::getHistory(int i )
{
	return mHistory[i];
}


