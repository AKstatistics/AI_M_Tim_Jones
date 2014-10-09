#include "Q.h"

#include <iostream>

int main()
{
	Q test( 1 );
	test.addNode( 2 );

	std::cout << test.fifo() << std::endl;

	return 0;
}

