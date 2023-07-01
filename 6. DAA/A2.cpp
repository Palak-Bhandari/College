#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int select(int arr[],int i, int x){
    int m1[5];
    for(int j=0;j<5;j++){
        m1[j] = arr[5*i+j];
    }
    sort(m1,m1+5);
    return m1[x];
}
int median_of_median(int arr[],int n){
    int m[n/5];
    if(n<6){
        return select(arr,0,floor(n/2));
    }
    for(int i=0;i<(n/5)-1;i++){
        m[i] = select(arr,i,2);
    }
    return median_of_median(m,n/5);
}
int find_index(int arr[], int n){
    int medofmed = median_of_median(arr,n);
    for(int i=0;i<n;i++){
        if(arr[i]=medofmed)
            return i;
    } 
}
int partition(int low, int high, int arr[]){
    int pivot = low;
    int i = low;
    int j = high;
    int temp;
    while(i<=j){
		while(arr[i]<=arr[pivot] && i<=high)
			i++;
		while(arr[j]>arr[pivot])
			j--;
		if(i<j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp; 
		}
	}
	temp = arr[j];
	arr[j] = arr[pivot];
	arr[pivot] = temp;
	return j;
}
void quicksort(int low,int high, int arr[]){
    if(low<high){
        int p = partition(low,high,arr);
        quicksort(low,p-1,arr);
        quicksort(p+1,high,arr);
    }
}
int main(){
    cout<<fixed<<setprecision(10);
	for (int i = 1 ; i <= 6 ; i++) {
        int n = pow(10,i);
        int v[n] ;
        for (int i = 0 ; i < n ; i++) {
            int val = rand() % (n+2);
            v[i] = val ;
        }
        cout << "\nInput Size = " << n << endl;
        auto start1 = std::chrono::steady_clock::now();
        quicksort(0, n - 1,v) ;
        auto finish1 = std::chrono::steady_clock::now();
        double time1 = std::chrono::duration_cast < std::chrono::duration<double> > (finish1 - start1).count();
        cout << "\nTime Taken By Divide and conquer  = " << fixed << time1 << setprecision(10) << endl;
    }
}