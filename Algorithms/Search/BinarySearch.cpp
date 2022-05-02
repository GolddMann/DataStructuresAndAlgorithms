#include <iostream>
using namespace std;

int BinarySearch(int arr[], int size, int key){ // for sorted array
	int start = 0;
	int end = size-1;
	while(start <= end){
		int mid = start + (end - start)/2;
		if(arr[mid] == key)
			return mid;

		if(arr[mid] > key)
			end = mid-1;
		else
			start = mid+1;
	}
	return -1;
}


int main(){
	int arr[5] = {1,2,3,4,5};
	int size = 5;
	int key = 2;
	cout << BinarySearch(arr, size, key) << endl;
	return 0;
}