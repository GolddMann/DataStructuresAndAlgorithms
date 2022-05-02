#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
	T data;
	Node *next = nullptr;

public:
	Node(T data, Node *next)
	{
		this->data = data;
		this->next = next;
	}

	Node(T data)
	{
		this->data = data;
	}

	Node *getNext()
	{
		return next;
	}

	void setData(T value)
	{
		data = value;
	}

	T getData()
	{
		return data;
	}

	bool hasNext()
	{
		return next != nullptr;
	}
};

template <typename T>
class Queue
{
private:
	Node<T> *head = nullptr;
	Node<T> *tail = nullptr;
	int size;

public:
	Queue() : size(0) {}

	bool isEmpty()
	{
		return size == 0;
	}

	int getSize()
	{
		return size;
	}

	void push(T value)
	{
		Node<T> *newnode = new Node<T>(value, head);
		if (isEmpty())
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			head = newnode;
		}
		size++;
	}

	T pop()
	{
		if (isEmpty())
			throw "Queue is empty";
		T value = tail->getData();
		if (size == 1)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			Node<T> *temp = head;
			while (temp->getNext() != tail)
			{
				temp = temp->getNext();
			}
			delete tail;
			tail = temp;
		}
		size--;
		return value;
	}
};

int main()
{
	Queue<int> queue;
	queue.push(3);
	queue.push(2);
	queue.push(1);
	cout << queue.pop() << endl;
	cout << queue.pop() << endl;
	cout << queue.pop() << endl;
	return 0;
}
