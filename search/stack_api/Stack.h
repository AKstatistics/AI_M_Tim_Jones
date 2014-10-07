#ifndef STACK_H
#define STACK_H

#include <vector>
using std::vector;

class Stack
{
	private:
		vector<unsigned int> mStack;
		vector<unsigned int> mDone;
	public:
		Stack();
		Stack( const unsigned int first );
		
		// Adds a node if it is not already on either list
		bool addNode( const unsigned int );

		// Last in first out, returns the node from stack 
		// and moves it to done
		const unsigned int lifo();

		// Prints the contents of the stack
		void displayStack();
		
		// Returns true if mStack is empty
		bool isEmpty(){ return mStack.empty(); }

		// Prints the contents of the done stack
		void displayDone();


};

#endif
