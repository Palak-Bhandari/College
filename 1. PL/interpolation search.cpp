#include<stdio.h>
#define MAX 10
int list[MAX] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44 };
int find(int data) {
   	int lo = 0;
   	int hi = MAX - 1;
   	int mid = -1;
   	int comparisons = 1;      
   	int index = -1;
   	while(lo <= hi) {
      	printf("\nComparison %d  \n" , comparisons ) ;
      	printf("lo : %d, list[%d] = %d\n", lo, lo, list[lo]);
      	printf("hi : %d, list[%d] = %d\n", hi, hi, list[hi]);  
      	comparisons++;
      	mid = lo + (((double)(hi - lo) / (list[hi] - list[lo])) * (data - list[lo]));
      	printf("mid = %d\n",mid);
      	if(list[mid] == data) {
         	index = mid;
         	break;
    	}else {
         	if(list[mid] < data){
	            lo = mid + 1;
         	} else {
	            hi = mid - 1;
         	}	
      	}               
   	}
   	printf("\nTotal comparisons made: %d", --comparisons);
   	return index;
}
int main() {
   	int location = find(33);
   	if(location != -1)
      	printf("\nElement found at location: %d" ,(location+1));
   	else
      	printf("Element not found.");
   	return 0;
}
