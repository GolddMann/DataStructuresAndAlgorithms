#include <iostream>
using namespace std;

class UnionFind{
private:
	int *posisions;
	int *array;
	int size;
public:
	UnionFind(int *array, int size){
		this->size = size;
		this->array = new int[size];
		this->posisions = new int[size];
		for(int i = 0; i < size; i++){
            this->array[i] = array[i];
			this->posisions[i] = i;
		}
	}


	int find(int key){
		int i;
		for(i = 0; i < size; i++){
			if(key == array[i])
				break;
		}
		if(i == size){
			throw "Value wasn't been found";
		}

		int root = i;
		while(root != posisions[root])
			root = posisions[root];

		while(i != root){
			posisions[i] = root;
			i = posisions[i];
		}

		return root;
	}

	void Union(int a, int b){
		int aRoot = find(a);
		int bRoot = find(b);
		if(aRoot == bRoot)
			return;

		posisions[bRoot] = aRoot;
	}
};


int main(){
	int arr[4] = {1,2,3,4};
	int size = 4;
	UnionFind unionfind = UnionFind(arr, size);
	unionfind.Union(1,2);
	unionfind.Union(1,3);
	unionfind.Union(4,1);
	cout << unionfind.find(2);
	return 0;
}
