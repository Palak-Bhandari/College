#include <iostream>
using namespace std;
void printArray(int arr[], int n) {
	for (int i = 0; i < n; ++i)
	  cout<<arr[i]<<" ";
	cout<<"\n";
}
void heapify(int arr[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;	
	if (left < n && arr[left] > arr[largest])
	  largest = left;
	if (right < n && arr[right] > arr[largest])
	  largest = right;
	if (largest != i) {
	  swap(arr[i], arr[largest]);
	  heapify(arr, n, largest);
	  cout<<"\n"<<"from heapify : ";
	    printArray(arr, n);
	}
}
void heapify_2(int arr[], int n, int i) {
	int smallest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;	
	if (left < n && arr[left] < arr[smallest])
	  smallest = left;
	if (right < n && arr[right] < arr[smallest])
	  smallest = right;
	if (smallest != i) {
	  swap(arr[i], arr[smallest]);
	  heapify_2(arr, n, smallest);
	  cout<<"\n"<<"from heapify : ";
	    printArray(arr, n);
	}
}
void heapSort(int arr[], int n) { 
    cout<<"\n    BUILD HEAP : ";
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
    cout<<"\n    HEAP SORT : ";
    cout <<"\nHEAP : ";
        printArray(arr, n);
    for (int i = n - 1; i >= 0; i--){
      swap(arr[0], arr[i]);
      cout <<"\n" << i <<"th pass : ";
        printArray(arr, n);
      heapify(arr, i, 0);
      cout <<"\n" << i <<"th Pass after heapify : ";
        printArray(arr, n);
    }
}
void heapSort_2(int arr[], int n) { 
    cout<<"\n    BUILD HEAP : ";
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify_2(arr, n, i);
    cout<<"\n    HEAP SORT : ";
    cout <<"\nHEAP : ";
        printArray(arr, n);
    for (int i = n - 1; i >= 0; i--){
      swap(arr[0], arr[i]);
      cout <<"\n" << i <<"th pass : ";
        printArray(arr, n);
      heapify_2(arr, i, 0);
      cout <<"\n" << i <<"th Pass after heapify : ";
        printArray(arr, n);
    }
}
int main() {
	int n,choice;
	cout<<"Enter no of elements in array to be sorted : ";
	cin>>n;
	int arr[n];
	cout<<"\nEnter the array : ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"\nArray Before Sorting : ";
	printArray(arr, n);
	cout<<"1. Ascending order sorting \n2. Descending order sorting : ";
	cin>>choice;
	switch(choice){
		case 1: heapSort(arr, n);
				cout<<"\nArray After Sorting(Ascending Order) is : ";
				printArray(arr, n);
				break;
		case 2: heapSort_2(arr, n);
				cout<<"\nArray After Sorting(Descending Order) is : ";
				printArray(arr, n);
				break;
		default: cout<<"Invalid Option!";
	}
	
}	
