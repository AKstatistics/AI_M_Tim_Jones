// This is a First In, First Out queue. Its just a queue and a vector for history.
// This is just like the Stack I made. It prevents previously searched nodes from being added
// and returns a bool: TRUE if the node was added. I named it Q to avoid confusion with the queue class
// I used the deque class in this class. Also I hate typing queue. Though actually come to think of it is kinda fun
// queue queue queue queue queue queueu qeueuqueuq e equueq

#ifndef Q_H
#define Q_H

#include <vector>
#include <deque>
#include <iostream>
using std::vector;
using std::deque;

class Q
{
	private:
		deque<unsigned int> mQ;
		vector<unsigned int> mHistory;
	public:
		Q();
		Q( const unsigned int first );
		
		// Adds a node if it is not already on either list
		bool addNode( const unsigned int );

		// Last in first out, returns the node from queue 
		// and moves it to done
		const unsigned int fifo();

		// Returns the ith element in the Done queue
		const unsigned int getHistory( int i );

		// Prints the contents of the queue
		void displayQ();
		
		// Returns true if mQ is empty
		bool isEmpty(){ return mQ.empty(); }

		// Prints the contents of the done queue
		void displayHistory();

		int lenHistory() {return mHistory.size(); }

		void reset() { mQ.clear(); mHistory.clear(); } 


};

#endif
