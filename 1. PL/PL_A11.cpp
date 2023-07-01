#include<iostream>
#define MAX 20
using namespace std;
class student{
	public:
		int marks[MAX];
		int rollno[MAX];
		string name[MAX];
		int n;
	public:
		void add(int n){
			for(int i=0;i<n;i++){
				cout<<"Enter roll no, name and marks: ";
				cin>>rollno[i]>>name[i]>>marks[i];
			}	
		}
		void display(int index){
			cout<<"RollNo\tName\tMarks\n";
			cout<<rollno[index]<<"\t"<<name[index]<<"\t"<<marks[index];
		}		
};
int sentinel_search(int rollno[],int key,int n){
	int last = rollno[n - 1];
	rollno[n - 1] = key;
	int i = 0;
	while(rollno[i] != key)
		i++;
	rollno[n - 1] = last;
	if((i < n - 1) || (rollno[n - 1] == key))
		return i;
	else
		return -1;
}
int binary_search(int rollno[],int l,int r,int key){
	int mid;
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (rollno[mid] == key)
			return mid;
		else if (rollno[mid] > key)
			return binary_search(rollno,l, mid - 1, key);
		else if (rollno[mid] < key)
			return binary_search(rollno,mid + 1, r, key);
	}
	return -1;
}
int fibonacci(int s[],int n){
	int x;
	cout<<"Enter the Marks to search: ";
	cin>>x;
	int k2=0;
	int k1=1;
	int k = k2+k1;
	int offset = -1;
	while(k<n){
		k2 = k1;
		k1 = k;
		k = k1+k2;
	}
	while(k>1){
		int i;
		if((offset+k2)<=(n-1))
			i = offset + k2;
		else
			i = n-1;
		if(s[i]<x){
			k=k1;
			k1=k2;
			k2=k-k1;
			offset=i;
		}
		else if(s[i]>x){
			k=k2;
			k1=k1-k2;
			k2=k-k1;
		}
		else
			return i;	
	}
	return -1;
}
int main(){	
	student s;
	int key,n,x,ch,result;
	cout<<"Enter no of students: ";
	cin>>n;
	s.add(n);
	do{
		cout<<"1.Sentinel Search\n2.Binary Search\n3.Fibonacci Search: ";
		cin>>ch;
		switch(ch){
			case 1: cout<<"Enter the roll no to search: ";
					cin>>key;
					result = sentinel_search(s.rollno,key,n);
					if(result == -1){
						cout<<"Student roll no not present!";
					}else{
						cout<<"Found details at index: "<<result<<endl;
						s.display(result);
					}
					break;
			case 2: cout<<"Enter the roll no to search: ";
					cin>>key;
					result = binary_search(s.rollno,0, n - 1, key);
					if(result == -1){
						cout<<"Student roll no not present!";
					}else{
						cout<<"Found details at index: "<<result<<endl;
						s.display(result);
					}
					break;
			case 3:	result = fibonacci(s.marks,n);
					if(result==-1)
						cout<<"Roll no not found!";
					else{
						cout<<"Found details at index: "<<result<<endl;
						s.display(result);
					}
					break;
			default:cout<<"Invalid Choice!";
		}
		cout<<"\nPress 1 to continue: ";
		cin>>x;
	}while(x==1);	
	return 0;
}
/*
Enter no of students: 8
Enter roll no, name and marks: 1 aa 34
Enter roll no, name and marks: 2 bb 49
Enter roll no, name and marks: 3 cc 56
Enter roll no, name and marks: 4 dd 62
Enter roll no, name and marks: 5 ee 69
Enter roll no, name and marks: 6 ff 71
Enter roll no, name and marks: 7 gg 78
Enter roll no, name and marks: 8 hh 81
1.Sentinel Search
2.Binary Search
3.Fibonacci Search: 1
Enter the roll no to search: 7
Found details at index: 6
RollNo  Name    Marks
7       gg      78
Press 1 to continue: 1
1.Sentinel Search
2.Binary Search
3.Fibonacci Search: 2
Enter the roll no to search: 3
Found details at index: 2
RollNo  Name    Marks
3       cc      56
Press 1 to continue: 1
1.Sentinel Search
2.Binary Search
3.Fibonacci Search: 3
Enter the Marks to search: 49
Found details at index: 1
RollNo  Name    Marks
2       bb      49
Press 1 to continue: 2

--------------------------------
Process exited after 90 seconds with return value 0
Press any key to continue . . .*/
