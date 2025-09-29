#include <chrono>
#include <iostream>

class MyObject
{
public:
	int x, y, z;
	MyObject() : x(1), y(2), z(3) {}
};

int main()
{
	const int NUM_OBJECTS = 100000; //1e5; if I define it in scientific style, it will be casted in double, but not constant;
	
		std::chrono::high_resolution_clock::time_point startHeap = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < NUM_OBJECTS; ++i)
		{
			MyObject* obj = new MyObject();
			delete obj;
		}

		std::chrono::high_resolution_clock::time_point endHeap = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double, std::milli> elapsedHeap = endHeap - startHeap;

		std::cout << "Heap allocation time: " << elapsedHeap.count() << " ms\n";
	
	
		std::chrono::high_resolution_clock::time_point startStack = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < NUM_OBJECTS; ++i)
		{
			MyObject obj;
		}

		std::chrono::high_resolution_clock::time_point  endStack = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double, std::milli> elapsedStack = endStack - startStack;

		std::cout << "Stack allocation time: " << elapsedStack.count() << " ms\n";

		std::cout << "Difference in " << elapsedHeap.count() / elapsedStack.count() << "x" << std::endl;
	
	return 0;
}