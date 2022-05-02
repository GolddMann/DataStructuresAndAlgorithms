#include <iostream>
using namespace std;

void BubbleSort(int arr[], int size){
	for(int j = 0; j < size; j++){
		for(int i = 0; i < size-j; i++){
			if(arr[i] > arr[i+1]){
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
}

void printArray(int arr[], int size){
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	int arr[6] = {4,2,3,4,1,2};
	int size = 6;
	printArray(arr, size);
	BubbleSort(arr, size);
	printArray(arr, size);
	return 0;
}