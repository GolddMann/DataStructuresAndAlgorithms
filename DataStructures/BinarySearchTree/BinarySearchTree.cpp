#include <iostream>
using namespace std;

class Node{
private:
	int data;
	Node *left;
	Node *right;
public:
	Node(int data, Node *left = nullptr, Node *right = nullptr){
		this->data = data;
		this->left = left;
		this->right = right;
	}

	int getData(){
		return data;
	}

	int setData(int key){
		data = key;
	}

	Node *getLeft(){
		return left;
	}

	Node *getRight(){
		return right;
	}

	void setLeft(Node *newleft){
		left = newleft;
	}

	void setRight(Node *newright){
		right = newright;
	}
};

class BinarySearchTree{
private:
	Node *root;
	int size;
	int capacity;

	void printInOrder(Node *node){
		if(node == nullptr)
			return;
		printInOrder(node->getLeft());
		cout << node->getData() << " ";
        printInOrder(node->getRight());
	}

	void printPreOrder(Node *node){
        if(node == nullptr)
            return;
        printPreOrder(node->getRight());
        cout << node->getData() << " ";
        printPreOrder(node->getLeft());
	}

	void print(Node *node){
        if(node == nullptr)
            return;
        cout << node->getData() << endl;
        print(node->getLeft());
        print(node->getRight());
	}

public:
	BinarySearchTree(int capacity):size(0), capacity(capacity){}

	BinarySearchTree(int *array, int size, int capacity){
		if(size > capacity)
			throw "Size can't be greater than capacity";
		this->capacity = capacity;
		this->size = 0;
		for(int i = 0; i < size; i++){
			this->push(array[i]);
		}
	}

	bool isEmpty(){
		return size == 0;
	}

	void push(int key){
		Node *newnode = new Node(key);
		if(isEmpty())
			root = newnode;
		else{
			Node *temp = root;
			while(true){
				if(temp->getData() > key){
					if(temp->getLeft() == nullptr){
						temp->setLeft(newnode);
						break;
					}
					else{
						temp = temp->getLeft();
					}
				}
				else{
					if(temp->getRight() == nullptr){
						temp->setRight(newnode);
						break;
					}
					else
						temp = temp->getRight();
				}
			}
		}
		this->size++;
	}

	bool contains(int key){
		return contains(root, key);
	}

	bool contains(Node *node, int key){
		if(node == nullptr)
			return false;
		if(node->getData() == key)
			return true;

		return contains(node->getLeft(), key) || contains(node->getRight(), key);
	}

	void remove(int key){
		if(isEmpty())
			throw "BST is empty";
        if(contains(key)){
            root = remove(root, key);
        }
	}

	Node *remove(Node *node, int key){
		if(node == nullptr) return nullptr;

		if(node->getData() > key){
			node->setLeft(remove(node->getLeft(), key));
		}
		else if(node->getData() < key){
			node->setRight(remove(node->getRight(), key));
		}
		else{
			if(node->getLeft() == nullptr){
				Node *temp = node->getRight();
				delete node;
				return temp;
			}
			else if(node->getRight() == nullptr){
				Node *temp = node->getLeft();
				delete node;
				return temp;
			}
			else{
				Node *maxLeft = getMaxFromLeft(node->getLeft());
				node->setData(maxLeft->getData());
				node->setLeft(remove(node->getLeft(), maxLeft->getData()));
				return node;
			}
		}
	}

	Node *getMaxFromLeft(Node *node){
		while(node->getRight() != nullptr)
			node = node->getRight();

		return node;
	}

	void printInOrder(){
		printInOrder(root);
	}

	void printPreOrder(){
        printPreOrder(root);
	}

	void print(){
        print(root);
	}
};


int main(){
	BinarySearchTree tree = BinarySearchTree(4);
	tree.push(3);
	tree.push(2);
	tree.push(1);
	tree.push(4);
	tree.print();
	cout << endl;
	tree.remove(3);
	tree.print();
	return 0;
}
