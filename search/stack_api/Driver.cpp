#include "Stack.h"
#include <iostream>

int main()
{
	Stack test(0);

	test.addNode(1);

	test.displayStack();

	int x = test.lifo();
	
	std::cout << x << std::endl;

	test.displayStack();
	test.displayDone();

	return 0;
}
