#include <iostream>
using namespace std;

class MaxHeap
{
private:
	int *heap = nullptr;
	int size;
	int capacity;

public:
	MaxHeap() : size(0), capacity(0) {}

	MaxHeap(int *array, int size, int capacity)
	{
		if (size > capacity)
			throw "Size cannot be greater than capacity";
		this->size = size;
		this->capacity = capacity;
		this->heap = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			this->heap[i] = array[i];
		}
		this->buildHeap(array);
	}

	void buildHeap(int *array)
	{
		for (int i = size / 2 - 1; i >= 0; i--)
		{
			heapifyDown(i);
		}
	}

	void heapifyDown(int i)
	{
		int leftChild = 2 * i + 1;
		int rightChild = 2 * i + 2;
		int greatest = i;
		if (leftChild < size && heap[leftChild] > heap[greatest])
			greatest = leftChild;
		if (rightChild < size && heap[rightChild] > heap[greatest])
			greatest = rightChild;

		if (greatest != i)
		{
			this->swap(greatest, i);
			heapifyDown(greatest);
		}
	}

	void heapifyUp(int i)
	{
		if (i == 0)
			return;
		if (heap[i] > heap[(i - 1) / 2])
		{
			swap(i, (i - 1) / 2);
			heapifyUp((i - 1) / 2);
		}
	}

	void push(int key)
	{
		if (size + 1 > capacity)
			throw "Excess capacity";
		heap[size] = key;
		size++;
		heapifyUp(size - 1);
	}

	int peek()
	{
		if (isEmpty())
			throw "Heap is empty";
		return heap[0];
	}

	int pop()
	{
		int data = heap[0];
		swap(0, size - 1);
		heap[size - 1] = NULL;
		size--;
		heapifyDown(0);
		return data;
	}

	bool remove(int key)
	{
		for (int i = 0; i < size; i++)
		{
			if (heap[i] == key)
			{
				swap(i, size - 1);
				heap[size - 1] = NULL;
				size--;
				heapifyDown(i);
				return true;
			}
		}
		return false;
	}

	bool contains(int key)
	{
		for (int i = 0; i < size; i++)
		{
			if (heap[i] == key)
				return true;
		}
		return false;
	}

	void swap(int i, int j)
	{
		int temp = heap[i];
		heap[i] = heap[j];
		heap[j] = temp;
	}

	int getSize()
	{
		return size;
	}

	bool isEmpty()
	{
		return size == 0;
	}
};

int main()
{
	int arr[3] = {1, 2, 3};
	MaxHeap *heap = new MaxHeap(arr, 3, 4);
	cout << heap->pop() << endl;
	heap->push(4);
	heap->remove(4);
	cout << heap->pop() << endl;
	return 0;
}
