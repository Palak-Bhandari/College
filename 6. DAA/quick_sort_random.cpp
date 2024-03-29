#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}
int partition_rand(int arr[], int low, int high)
{
	srand(time(NULL));
	int random = low + rand() % (high - low);
	swap(arr[random], arr[high]);
	return partition(arr, low, high);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partition_rand(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
	int arr[n];
    cout<<"Enter the array: ";
    for(int i = 0; i<n ; i++){
        cin>>arr[i];
    }
	quickSort(arr, 0, n - 1);
	printf("Sorted array: \n");
	for (int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
    }
	return 0;
}
