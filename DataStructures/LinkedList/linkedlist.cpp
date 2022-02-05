#include <iostream>
using namespace std;

template<typename T>
class Node{
private:
	T data;
	Node<T> *next = nullptr;
public:
	Node(T data){
		this->data = data;
	}

	Node(T data, Node<T> *next){
		this->data = data;
		this->next = next;
	}

	T getData(){
		return data;
	}

	bool hasNext(){
		return next != nullptr;
	}

	Node<T> *getNext(){
		return next;
	}

	void setNext(Node<T> *next){
		this->next = next;
	}
};

template<typename T>
class LinkedList{
private:
	Node<T> *head = nullptr;
	Node<T> *tail = nullptr;
	int size;
public:
	LinkedList():size(0){}

	LinkedList(T value){
		this->head = new Node<T>(value);
		this->tail = this->head;
		size = 1;
	}

	bool isEmpty(){
		return size == 0;
	}

	void push_back(T value){
		Node<T> *newnode = new Node<T>(value);
		if(isEmpty()){
			head = newnode;
			tail = newnode;
			size = 1;
		}
		else{
			tail->setNext(newnode);
			if(tail == head)
				head->setNext(tail);
			tail = tail->getNext();
			size++;
		}
	}

	void push_front(T value){
		Node<T> *newnode = new Node<T>(value, head);
		if(isEmpty()){
			tail = newnode;
			head = newnode;
			size = 1;
		}
		else{
			if(head == tail)
				newnode->setNext(tail);
			head = newnode;
			size++;
		}
	}

	T pop_back(){
		if(isEmpty())
			throw "LinkedList is empty, unable to pop_back()";
		T data = tail->getData();
		if(size == 1){
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else{
			Node<T> *temp = head;
			while(temp->getNext() != tail)
				temp = temp->getNext();
			delete tail;
			tail = temp;
			return data;
		}
		size--;
		return data;
	}

	T pop_front(){
		if(isEmpty())
			throw "LinkedList is empty, unable to pop_front()";
		T data = head->getData();
		if(size == 1){
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else{
			Node<T> *temp = head;
			head = head->getNext();
			delete temp;
		}
		size--;
		return data;
	}

	bool contains(T key){
		Node<T> *temp = head;
		while(temp != nullptr){
			if(temp->getData() == key)
				return true;
			temp = temp->getNext();
		}
		return false;
	}

	T peek_back(){
		if(isEmpty())
			throw "LinkedList is empty";
		return tail->getData();
	}

	T peek_front(){
		if(isEmpty())
			throw "LinkedList is empty";
		return head->getData();
	}

	~LinkedList(){
		Node<T> *temp = head;
		while(temp != nullptr){
			Node<T> *next = temp->getNext();
			delete temp;
			temp = next;
		}
	}
};


int main(){
	LinkedList<int> linkedlist;
	linkedlist.push_back(2);
    cout << linkedlist.pop_back() << endl;
	return 0;
}
