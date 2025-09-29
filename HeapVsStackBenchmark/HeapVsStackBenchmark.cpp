#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

class MyObject
{
public:
	int x, y, z;
	MyObject() : x(1), y(2), z(3) {}
};

double testHeap(int numObjects)
{
	std::chrono::high_resolution_clock::time_point startHeap = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < numObjects; ++i)
	{
		MyObject* obj = new MyObject();
		delete obj;
	}

	std::chrono::high_resolution_clock::time_point endHeap = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli> elapsedHeap = endHeap - startHeap;

	//std::cout << "Heap allocation time: " << elapsedHeap.count() << " ms\n";

	return elapsedHeap.count();
}

double testStack(int numObjects)
{
	std::chrono::high_resolution_clock::time_point startStack = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < numObjects; ++i)
	{
		MyObject obj;
	}

	std::chrono::high_resolution_clock::time_point  endStack = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli> elapsedStack = endStack - startStack;

	//std::cout << "Stack allocation time: " << elapsedStack.count() << " ms\n";

	return elapsedStack.count();
}

int main()
{
	std::vector<int> testCases = { 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

	std::cout << std::setw(12) << "Objects"
		<< std::setw(15) << "Heap (ms)"
		<< std::setw(15) << "Stack (ms)"
		<< std::setw(15) << "Difference\n";
	std::cout << std::string(60, '-') << "\n";

	for (int n : testCases)
	{
		double heapTime = testHeap(n);

		double stackTime = testStack(n);

		double ratio = heapTime / stackTime;

		std::cout << std::setw(12) << n
			<< std::setw(15) << std::fixed << std::setprecision(4) << heapTime
			<< std::setw(15) << stackTime
			<< std::setw(15) << std::setprecision(2) << ratio << "x\n";
	}

	return 0;
}