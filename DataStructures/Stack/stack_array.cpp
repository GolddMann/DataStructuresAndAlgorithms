#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
	T *stack;
	int size;
	int capacity;

public:
	Stack(int capacity = 0)
	{
		if (capacity < 0)
			throw "capacity can't be less than 0";
		this->capacity = capacity;
		this->size = 0;
		this->stack = new T[capacity];
	}

	Stack(T *array, int size, int capacity)
	{
		if (capacity < size)
			throw "capacity can't be less than size";
		this->capacity = capacity;
		this->size = size;
		this->stack = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			this->stack[i] = array[i];
		}
	}

	bool isEmpty()
	{
		return size == 0;
	}

	void push(T key)
	{
		if (size + 1 > capacity)
		{
			if (capacity == 0)
				capacity = 1;
			else
				capacity *= 2;
			T *newArray = new T[capacity];
			for (int i = 0; i < size; i++)
			{
				newArray[i] = stack[i];
			}
			delete[] stack;
			stack = newArray;
			stack[size++] = key;
		}
		else
		{
			stack[size++] = key;
		}
	}

	T peek()
	{
		if (!isEmpty())
			return stack[size - 1];
		else
		{
			throw "Stack is empty";
		}
	}

	T pop()
	{
		if (!isEmpty())
		{
			int data = stack[size - 1];
			stack[size - 1] = NULL;
			size--;
			return data;
		}
		else
		{
			throw "Stack is empty";
		}
	}

	~Stack()
	{
		delete[] stack;
	}
};

int main()
{
	Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	return 0;
}
