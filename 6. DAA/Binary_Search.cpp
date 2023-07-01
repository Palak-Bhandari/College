#include <bits/stdc++.h>
#include<ctime>
#include<cstdlib> 
using namespace std;
using namespace std::chrono;
int linear_search(int n, int key, int arr[]){
    int i;
    for (i = 0; i < n; i++){
        if (arr[i] == key){
            return i;
        }
    }
    return -1;
}
int binary_search_recursive(int arr[], int key, int low, int high){
    int mid;
    if (low <= high){
        mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            return binary_search_recursive(arr, key, low, mid - 1);
        else if (arr[mid] < key)
            return binary_search_recursive(arr, key, mid + 1, high);
    }
    return -1;
}
int binary_search_iterative(int arr[], int key, int low, int high){
    int mid;
    while (low <= high){
        mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key){
            high = mid - 1;
        }
        if (arr[mid] < key){
            low = mid + 1;
        }
    }
    return -1;
}
int binary_search_random(int arr[], int key, int low, int high){
	int divide=-1;
	while(divide <= low || divide >= high){
		if(low==high){
		    divide  = low;
		    break;
		}
		divide = rand() % high;
	}
	if(low<=high){
        if(arr[divide] == key){
            return divide;
        }
        else if(arr[divide] > key)
            return binary_search_random(arr,key,low,divide-1);
        else if(arr[divide] < key)
            return binary_search_random(arr,key,divide+1,high);
    }
    return -1;
}
int main()
{
    int key,n,i,ch;
    do{
        cout<<"Enter value of (n) for generating 10^n inputs(Enter 0 to exit)=";
        cin>>n;
        int arr_size;
        arr_size=pow(10,n);
        int arr[arr_size];
        srand(time(0));
        for(i=0;i<arr_size;i++){
            // arr[i] = rand()%10;
            arr[i]=i;
        }
        do{
            auto start = high_resolution_clock::now();
            cout << "Enter choice\n1.Linear Search\n2.Binary Search- Recursive\n3.Binary Search- Iterative\n4.Random binary\n";
            cin >> ch;
            int key;
            key = rand()% arr_size;
            cout<<"\nElement we are searching for is "<<key;
            int a;
            switch (ch){
            case 1:
                a = linear_search(arr_size, key, arr);
                break;
            case 2:
                a = binary_search_recursive(arr, key, 0, arr_size - 1);
                break;
            case 3:
                a = binary_search_iterative(arr, key, 0, arr_size - 1);
                break;
            case 4:
                a = binary_search_random(arr, key, 0, arr_size - 1);
                break;
            default:
                cout << "\nInvalid Input";
            }
            if (a == -1){
                cout << "\nNot found!";
            }
            else{
                cout << "\nIndex: " << a;
            }
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            cout<<"\nExecution time= "<<duration.count()<< endl;
        }while(ch!=0);
    }while(n!=0);
    return 0;
}