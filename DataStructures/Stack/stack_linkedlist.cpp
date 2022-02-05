#include <iostream>
using namespace std;

template<typename T>
class Node{
private:
	T data;
	Node *next = nullptr;
public:
	Node(T data, Node *next){
		this->data = data;
		this->next = next;
	}

	Node(T data){
		this->data = data;
	}

	Node* getNext(){
		return next;
	}

	void setData(T value){
		data = value;
	}

	T getData(){
		return data;
	}

	bool hasNext(){
		return next != nullptr;
	}
}

template<typename T>
class Stack{
private:
	Node<T> *head = nullptr;
	int size;
public:
	Stack():size(0){}
	
	Stack(int value){
		this->head = new Node<T>(value);
		this->size = 1;
	}

	bool isEmpty(){
		return size == 0;
	}

	bool getSize(){
		return size;
	}

	void push(int value){
		Node<T> *newnode = new Node<T>(value, head);
		head = newnode;
		size++;
	}

	T pop(){
		if(isEmpty())
			throw "Stack is empty, unable to pop()";
		T data = head->getData();
		Node<T> *node = head;
		head = head->getNext();
		delete node;
		size--;
		return data;
	}

	T peek(){
		if(isEmpty())
			throw "Stack is empty, unable to peek()";
		return head->getData();
	}

	bool contains(T key){
		Node<T> *pointer = head;
		while(pointer != nullptr){
			if(pointer->getData() == key)
				return true;
			pointer = pointer->getNext();
		}
		return false;
	}
};

int main(){
	Stack<int> stack;
	stack.push(2);
	cout << stack.peek() << endl;
	return 0;
}