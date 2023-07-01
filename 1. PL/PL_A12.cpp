#include<iostream>
using namespace std;
int intersection_2(int a[],int b[],int s1,int s2) {
	int count = 0;
	int i,j;
	for(i=0;i<s1;i++)
		for(j=0;j<s2;j++)
			if(a[i]==b[j])
				count++;
	return count;	
}
int intersection_3(int a[],int b[],int c[],int s1,int s2,int s3) {
	int count = 0,i,j,k;
	for(i=0;i<s1;i++)
		for(j=0;j<s2;j++)
			for(k=0;k<s3;k++)
					if(a[i]==b[j] && a[i]==c[k] && b[j]==c[k])
						count++;
	return count;
}
int intersection_4(int a[],int b[],int c[],int d[],int s1,int s2,int s3,int s4) {
	int count = 0,i,j,k,l;
	for(i=0;i<s1;i++)
		for(j=0;j<s2;j++)
			for(k=0;k<s3;k++)
				for(l=0;l<s4;l++)
					if(a[i]==b[j] && a[i]==c[k] && a[i]==d[l] && b[j]==c[k] && c[k]==d[l] && b[j]==d[l])
						count++;
	return count;	
}	
int main() 
{
	int math,chem,phy,bio,total_4;
	int cpp,java,python,total_3;
	int i;
	cout<<"---- 4 sets Problem ----\n";
	cout<<"Enter no. of maths students: ";
	cin>>math;
	int m[math];
	cout<<"Enter their roll nos: ";
	for(i=0;i<math;i++) {
		cin>>m[i];
	}
	cout<<"Enter no. of physics students: ";
	cin>>phy;
	int p[phy];
	cout<<"Enter their roll nos: ";
	for(i=0;i<phy;i++) {
		cin>>p[i];
	}
	cout<<"Enter no. of chemistry students: ";
	cin>>chem;
	int c[chem];
	cout<<"Enter their roll nos: ";
	for(i=0;i<chem;i++) {
		cin>>c[i];
	}
	cout<<"Enter no. of biology students: ";
	cin>>bio;
	int b[bio];
	cout<<"Enter their roll nos: ";
	for(i=0;i<bio;i++) {
		cin>>b[i];
	}
	total_4 = math + phy + chem + bio - intersection_2(m,p,math,phy) - intersection_2(m,c,math,chem)
	- intersection_2(m,b,math,bio) - intersection_2(c,p,chem,phy) - intersection_2(b,p,bio,phy)
	- intersection_2(c,b,chem,bio) + intersection_3(m,p,c,math,phy,chem) + intersection_3(m,p,b,math,phy,bio) 
	+ intersection_3(m,b,c,math,bio,chem) + intersection_3(b,p,c,bio,phy,chem) - intersection_4(m,p,c,b,math,phy,chem,bio);
    cout << "\nThe total number of students are:- "<<total_4<<endl;

    cout<<"\n---- 3 sets Problem ----\n";
    cout<<"Enter no. of students who know CPP: ";
	cin>>cpp;
	int pl1[cpp];
	cout<<"Enter their roll nos: ";
	for(i=0;i<cpp;i++) {
		cin>>pl1[i];
	}
	cout<<"Enter no. of students who know Java: ";
	cin>>java;
	int pl2[java];
	cout<<"Enter their roll nos: ";
	for(i=0;i<java;i++) {
		cin>>pl2[i];
	}
	cout<<"Enter no. of students who know Python: ";
	cin>>python;
	int pl3[python];
	cout<<"Enter their roll nos: ";
	for(i=0;i<python;i++) {
		cin>>pl3[i];
	}
	total_3 = cpp + java + python - intersection_2(pl1,pl2,cpp,java) - intersection_2(pl1,pl3,cpp,python)
	- intersection_2(pl3,pl2,python,java) + intersection_3(pl1,pl2,pl3,cpp,java,python);
	cout << "\nThe total number of students are:- "<<total_3<<endl;	
	return 0;
}
/*
---- 4 sets Problem ----
Enter no. of maths students: 6
Enter their roll nos: 1 2 3 4 5 6
Enter no. of physics students: 8
Enter their roll nos: 2 3 5 6 7 8 9 10
Enter no. of chemistry students: 7
Enter their roll nos: 2 3 7 1 8 9 11
Enter no. of biology students: 5
Enter their roll nos: 2 7 9 11 12

The total number of students are:- 12

---- 3 sets Problem ----
Enter no. of students who know CPP: 6
Enter their roll nos: 1 2 3 4 5 6
Enter no. of students who know Java: 8
Enter their roll nos: 3 4 7 8 9 10 11 12
Enter no. of students who know Python: 8
Enter their roll nos: 1 2 3 10 11 13 14 15

The total number of students are:- 15

--------------------------------
Process exited after 171.8 seconds with return value 0
Press any key to continue . . .*/
