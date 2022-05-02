#include <iostream>
using namespace std;

void MergeArrays(int arr[], int s, int mid, int e){
	int newarr[e-s+1];
	int k = 0;
	int i = s;
	int j = mid;
	while(i < mid && j <= e){
		if(arr[i] < arr[j]){
			newarr[k] = arr[i++];
		}
		else{
			newarr[k] = arr[j++];
		}
		k++;
	}
	while(i < mid){
		newarr[k++] = arr[i++];
	}
	while(j <= e){
		newarr[k++] = arr[j++];
	}
	for(i = s, k = 0; i <= e; i++, k++){
		arr[i] = newarr[k];
	}
}

void BinarySort(int arr[], int s, int e){
	if(s >= e)
		return;
	int mid = s + (e-s)/2;
	BinarySort(arr, s, mid);
	BinarySort(arr, mid+1, e);
	MergeArrays(arr, s, mid+1, e);
}


void printArray(int arr[], int size){
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(){
	int arr[11] = {5,4,3,2,1,6,7,2,3,5,1};
	int size = 11;
	printArray(arr, size);
	BinarySort(arr, 0, size-1);
	printArray(arr, size);
	return 0;
}
