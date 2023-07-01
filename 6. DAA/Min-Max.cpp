#include<bits/stdc++.h>
using namespace std;
void findMinAndMax(int arr[], int low, int high, int &min, int &max) {
    if (low == high) {
        if (max < arr[low]) {          
            max = arr[low];
        }
        if (min > arr[high]) {        
            min = arr[high];
        }
        return;
    }
    if (low == high-1){
        if (arr[low] < arr[high]) {
            if (min > arr[low]) {       
                min = arr[low];
            }
            if (max < arr[high]) {      
                max = arr[high];
            }
        } else {
            if (min > arr[high]) {      
                min = arr[high];
            }
            if (max < arr[low]) {       
                max = arr[low];
            }
        }
        return;
    }
    int mid = (low + high) / 2;
    findMinAndMax(arr, low, mid, min, max);
    findMinAndMax(arr, mid + 1, high, min, max);
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    int max = INT_MIN, min = INT_MAX;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    findMinAndMax(arr, 0, n - 1, min, max);
    cout << "The minimum array element is " << min << endl;
    cout << "The maximum array element is " << max << endl;
    return 0;
}