#ifndef STACK_H
#define STACK_H

#include <vector>
using std::vector;

class Stack
{
	private:
		vector<unsigned int> mStack;
		vector<unsigned int> mHistory;
	public:
		Stack();
		Stack( const unsigned int first );
		
		// Adds a node if it is not already on either list
		bool addNode( const unsigned int );

		// Last in first out, returns the node from stack 
		// and moves it to done
		const unsigned int lifo();

		// Returns the ith element in the Done stack
		const unsigned int getHistory( int i );

		// Prints the contents of the stack
		void displayStack();
		
		// Returns true if mStack is empty
		bool isEmpty(){ return mStack.empty(); }

		// Prints the contents of the done stack
		void displayHistory();

		int lenHistory() {return mHistory.size(); }

		void reset() { mStack.clear(); mHistory.clear(); }


};

#endif
