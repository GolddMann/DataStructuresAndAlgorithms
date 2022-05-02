#include <iostream>
using namespace std;

int LinearSearch(int *arr, int size, int key){
	for(int i = 0; i < size; i++){
		if(arr[i] == key)
			return i;
	}
	return -1;
}


int main(){
	int arr[5] = {4,1,2,3,5};
	int size = 5;
	cout << LinearSearch(arr, 5, 2) << endl;
	return 0;
}