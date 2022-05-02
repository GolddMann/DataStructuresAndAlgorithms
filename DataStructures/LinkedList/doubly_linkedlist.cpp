#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
	T data;
	Node<T> *next = nullptr;
	Node<T> *prev = nullptr;

public:
	Node(T value)
	{
		this->data = value;
	}

	Node(T value, Node<T> *prev, Node<T> *next)
	{
		this->data = value;
		this->next = next;
		this->prev = prev;
	}

	T getData()
	{
		return data;
	}

	Node<T> *getNext()
	{
		return next;
	}

	Node<T> *getPrev()
	{
		return prev;
	}

	void setData(T value)
	{
		this->data = value;
	}

	void setNext(Node<T> *next)
	{
		this->next = next;
	}

	void setPrev(Node<T> *prev)
	{
		this->prev = prev;
	}

	bool hasNext()
	{
		return next != nullptr;
	}

	bool hasPrev()
	{
		return prev != nullptr;
	}
};

template <typename T>
class DoublyLinkedList
{
private:
	Node<T> *head;
	Node<T> *tail;
	int size;

public:
	DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

	bool isEmpty()
	{
		return size == 0;
	}

	void push_back(T value)
	{
		Node<T> *newnode = new Node<T>(value, tail, nullptr);
		if (isEmpty())
		{
			head = newnode;
			tail = newnode;
		}
		if (size == 1)
		{
			tail = newnode;
			head->setNext(tail);
		}
		else
		{
			tail->setNext(newnode);
			tail = tail->getNext();
		}
		size++;
	}

	void push_front(T value)
	{
		Node<T> *newnode = new Node<T>(value, nullptr, head);
		if (isEmpty())
		{
			head = newnode;
			tail = newnode;
		}
		if (size == 1)
		{
			head = newnode;
			tail->setPrev(head);
		}
		else
		{
			head = newnode;
		}
		size++;
	}

	T peek_back()
	{
		if (isEmpty())
		{
			throw "LinkedList is empty";
		}
		return tail->getData();
	}

	T peek_front()
	{
		if (isEmpty())
		{
			throw "LinkedList is empty";
		}
		return head->getData();
	}

	T pop_back()
	{
		if (isEmpty())
			throw "LinkedList is empty";
		T value = tail->getData();
		if (size == 1)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			Node<T> *temp = tail;
			tail = tail->getPrev();
			delete temp;
		}
		size--;
		return value;
	}

	T pop_front()
	{
		if (isEmpty())
			throw "LinkedList is empty";
		T value = head->getData();
		if (size == 1)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			Node<T> *temp = head;
			head = head->getNext();
			delete temp;
		}
		size--;
		return value;
	}
};

int main()
{
	DoublyLinkedList<int> list;
	list.push_back(3);
	list.push_front(2);
	list.push_back(4);
	cout << list.pop_back() << endl;
	cout << list.pop_back() << endl;
	cout << list.pop_back() << endl;
	return 0;
}
