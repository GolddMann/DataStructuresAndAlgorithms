#include <iostream>
#include <string>
using namespace std;

template <typename T>
class DynamicArray
{
private:
	T *array;
	int capacity;
	int sizee; // used size

public:
	DynamicArray(int capacity = 0)
	{
		if (capacity < 0)
			throw "capacity can't be less than 0";
		this->sizee = 0;
		this->capacity = capacity;
		this->array = new T[capacity];
	}

	DynamicArray(T *arr, int capacity, int size)
	{
		if (size > capacity)
		{
			throw "Size cannot be greater than capacity";
		}
		this->size = size;
		this->capacity = 0;
		this->array = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			this->array[i] = arr[i];
		}
	}

	bool isEmpty()
	{
		return sizee == 0;
	}

	int getCapacity()
	{
		return capacity;
	}

	int getSize()
	{
		return sizee;
	}

	bool contains(T key)
	{
		for (int i = 0; i < sizee; i++)
		{
			if (array[i] == key)
				return true;
		}
		return false;
	}

	int getIndexOf(T key)
	{
		for (int i = 0; i < sizee; i++)
		{
			if (array[i] == key)
				return i;
		}
		return -1;
	}

	int append(T key)
	{
		if (sizee + 1 > capacity)
		{
			if (capacity != 0)
				capacity *= 2;
			else
				capacity = 1;
			T *newArray = new T[capacity];
			for (int i = 0; i < sizee; i++)
			{
				newArray[i] = array[i];
			}
			delete[] array;
			array = newArray;
		}
		array[sizee++] = key;
	}

	int pop()
	{
		if (sizee != 0)
		{
			sizee--;
		}
		else
		{
			throw "Array is empty!";
		}
	}

	int getByIndex(int i)
	{
		if (i >= sizee)
		{
			throw "out of bounds";
		}
		return array[i];
	}

	int setByIndex(int i, T key)
	{
		if (i >= sizee)
		{
			throw "Out of size";
		}
		array[i] = key;
	}

	~DynamicArray()
	{
		delete[] array;
	}
};

int main()
{
	DynamicArray<int> ints;
	ints.append(2);
	ints.append(3);
	cout << ints.getByIndex(0) << endl;
	return 0;
}
