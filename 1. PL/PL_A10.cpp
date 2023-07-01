#include<iostream>
#define MAX 10
using namespace std;
class population{
	public:
		int popn[MAX];
		string city[MAX];
	public:
		void get_data(int n){
			for(int i=0;i<n;i++){
				cout<<"Enter city and population: ";
				cin>>city[i]>>popn[i];	
			}
		}
		void display(int index){
			cout<<city[index]<<"\t"<<popn[index]<<endl;
		}
};
void insertionSort(int a[],string s[],int no){
	int i,key,j;
	string c;
	for(i = 1; i < no; i++){
		key = a[i];
		c = s[i];
		for(j=i-1;j>=0 && a[j]>=key;j--){
			a[j+1] = a[j];
			s[j+1] = s[j];
		}
		a[j+1] = key;
		s[j+1] = c;
	}
}
int partition(int a[],string s[],int left,int right){
	int i=left,j=right,p=left,temp;
	string temp2;
	while(i<=j){
		while(a[i]<=a[p] && i<=right)
			i++;
		while(a[j]>a[p])
			j--;
		if(i<j){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp; 
			temp2 = s[i];
			s[i] = s[j];
			s[j] = temp2;
		}
	}
	temp = a[j];
	a[j] = a[p];
	a[p] = temp;
	temp2 = s[j];
	s[j] = s[p];
	s[p] = temp2;
	return j;
}
void quick_sort(int a[],string s[],int left,int right){
	if(left<right){
		int pivot = partition(a,s,left,right);
		quick_sort(a,s,left,pivot-1);
		quick_sort(a,s,pivot+1,right);
	}
}
int main(){
	population p;
	int x,ch,no,i;
	cout<<"Enter no of cities: ";
	cin>>no;
	p.get_data(no);
	do{
		cout<<"1.Insertion Sort\n2.Quick Sort: ";
		cin>>ch;
		switch(ch){
			case 1: insertionSort(p.popn,p.city,no);
					for(i=0;i<no;i++)
						p.display(i);
					break;
			case 2:	quick_sort(p.popn,p.city,0,no-1);
					for(i=0;i<no;i++)
						p.display(i);
					break;
			default:cout<<"Invalid Input!";
		}
		cout<<"Press 1 to continue: ";
		cin>>x;
	}while(x==1);	
	return 0;
}
/*
Enter no of cities: 6
Enter city and population: aaa 120
Enter city and population: bbb 180
Enter city and population: ccc 110
Enter city and population: ddd 100
Enter city and population: eee 130
Enter city and population: fff 150
1.Insertion Sort
2.Quick Sort: 1
ddd     100
ccc     110
aaa     120
eee     130
fff     150
bbb     180
Press 1 to continue: 1
1.Insertion Sort
2.Quick Sort: 2
ddd     100
ccc     110
aaa     120
eee     130
fff     150
bbb     180
Press 1 to continue: 2

--------------------------------
Process exited after 44.47 seconds with return value 0
Press any key to continue . . .*/
