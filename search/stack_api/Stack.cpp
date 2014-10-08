#include "Stack.h"
#include <vector>
#include <iostream>

using std::vector;

Stack::Stack()
{}

Stack::Stack( const unsigned int first )
{
	mStack.push_back( first );
}

// This function adds a node to the stack if it has not already been queued once.
// The function returns TRUE if the node was successfully added.
bool Stack::addNode( const unsigned int node )
{
	bool duplicate = 0;	// This bool will be set to TRUE if the node has already been queued.
				// The opposite of this bool is TRUE when the node has successfully been added to the queue.

	for( vector<int>::size_type i = 0; i < mStack.size(); i++ )
	{
		if( mStack[i] == node )
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

	mStack.push_back( node );

	return !duplicate;

}

const unsigned int Stack::lifo()
{
	const unsigned int output = mStack[mStack.size() - 1];
	mStack.pop_back();

	mHistory.push_back( output );

	return output;
}

void Stack::displayStack()
{
	std::cout << "Stack: " << std::endl;

	for( vector<int>::size_type i = 0; i < mStack.size(); i++ )
	{
		std::cout << mStack[i] << std::endl;
	}
}

void Stack::displayHistory()
{
	std::cout << "History Stack: " << std::endl;

	for( vector<int>::size_type i = 0; i < mHistory.size(); i++ )
	{
		std::cout << mHistory[i] << std::endl;
	}
}

const unsigned int Stack::getHistory(int i )
{
	return mHistory[i];
}

