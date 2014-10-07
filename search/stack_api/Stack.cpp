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

void Stack::addNode( const unsigned int node )
{
	bool duplicate = 0;

	for( vector<int>::size_type i = 0; i < mStack.size(); i++ )
	{
		if( mStack[i] == node )
		{ duplicate = 1; break;}
	}

	if( duplicate == 1 )
		return;
	for( vector<int>::size_type i = 0; i < mDone.size(); i++ )
	{
		if( mDone[i] == node )
		{ duplicate = 1; break; }
	}

	if( duplicate == 1 )
		return;

	mStack.push_back( node );

}

const unsigned int Stack::lifo()
{
	const unsigned int output = mStack[mStack.size() - 1];
	mStack.pop_back();

	mDone.push_back( output );

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

void Stack::displayDone()
{
	std::cout << "Done Stack: " << std::endl;

	for( vector<int>::size_type i = 0; i < mDone.size(); i++ )
	{
		std::cout << mDone[i] << std::endl;
	}
}
