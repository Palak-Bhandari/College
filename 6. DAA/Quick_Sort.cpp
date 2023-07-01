#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void  worst_case(vector<int>& arr,int arr_size){
    sort(arr.begin(), arr.end());
}
int partition(int low, int high, vector<int>& arr){
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
void quicksort_partition(int low,int high, vector<int>& arr){
    if(low<high){
        int p = partition(low,high,arr);
        quicksort_partition(low,p-1,arr);
        quicksort_partition(p+1,high,arr);
    }
}
int MedianOfMedian(vector<int>& arr, int low, int high) {
    if (high - low <= 5) {
        sort(arr.begin() + low, arr.begin() + high);
        return arr[(low + high) / 2];
    }
    vector<int> m;
    for (int i = low; i <= high; i += 5) {
        int m_high = min(i + 4, high);
        sort(arr.begin() + i, arr.begin() + m_high);
        m.push_back(arr[(i + m_high) / 2]);
    }
    int medOfmed = MedianOfMedian(m, 0, m.size() - 1);
    return medOfmed;
}
int partition_medOfmed(vector<int>& arr, int low, int high, int pivot) {
    int pivot1 = low;
    for (int i = low; i <= high; i++) {
        if (arr[i] == pivot) {
            pivot1 = i;
            break;
        }
    }
    swap(arr[pivot1], arr[high]);
    pivot1 = high;
    int i = low - 1;
    for (int j = low; j < pivot1; j++) {
        if (arr[j] < arr[pivot1]) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[pivot1]);
    return i + 1;
}
void quicksort_medOfmed(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = MedianOfMedian(arr, low, high);
        int p = partition_medOfmed(arr, low, high, pivot);
        quicksort_medOfmed(arr, low, p - 1);
        quicksort_medOfmed(arr, p + 1, high);
    }
}
int main(){
    cout<<fixed<<setprecision(10);
	for (int i = 1 ; i <= 5 ; i++) {
        int arr_size = pow(10,i);
        vector<int> arr(arr_size);
        for (int i = 0 ; i < arr_size ; i++) {
            int a = rand() % arr_size;
            arr[i] = a ;
        }
        cout << "\nInput Size = " << arr_size << endl;
        auto start1 = std::chrono::steady_clock::now();
        quicksort_medOfmed(arr,0,arr_size-1) ;
        auto finish1 = std::chrono::steady_clock::now();
        double time1 = std::chrono::duration_cast < std::chrono::duration<double> > (finish1 - start1).count();
        cout << "\nTime Taken By Median of Median  = " << fixed << time1 << setprecision(10) << endl;
        auto start2 = std::chrono::steady_clock::now();
        quicksort_partition(0,arr_size-1,arr) ;
        auto finish2 = std::chrono::steady_clock::now();
        double time2 = std::chrono::duration_cast < std::chrono::duration<double> > (finish2 - start2).count();
        cout << "\nTime Taken By Divide and conquer  = " << fixed << time2 << setprecision(10) << endl;
        worst_case(arr,arr_size);
        auto start3 = std::chrono::steady_clock::now();
        quicksort_partition(0,arr_size-1,arr) ;
        auto finish3 = std::chrono::steady_clock::now();
        double time3 = std::chrono::duration_cast < std::chrono::duration<double> > (finish2 - start2).count();
        cout << "\nTime Taken for worst case by partition  = " << fixed << time3 << setprecision(10) << endl;
    }
    return 0;
}