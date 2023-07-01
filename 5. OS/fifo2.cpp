#include<bits/stdc++.h>
using namespace std;
int is_present(vector<int>a,int b){
	for(int i=0;i<a.size();i++){
		if(a[i]==b) return i;
	}
	return 999;
}
int main(){
	vector<int> pages;
	int n;
	cout<<"Enter number of pages: ";
	cin>>n;
	cout<<"\nEnter page values: ";
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		pages.push_back(temp);
	}
	int cap;
	cout<<"\nEnter capacity: ";
	cin>>cap;
	int pf=0;
	queue<int> q;
	vector<int> container;
	for(int i=0;i<n;i++){
		if(q.size()<cap){
			if(is_present(container,pages[i])==999){
				container.push_back(pages[i]);
				q.push(pages[i]);
				pf++;
			}
		}
		else{
			if(is_present(container,pages[i])==999){
				int temp = q.front();
				q.pop();
				int index = is_present(container,temp);
				container[index] = pages[i];
				q.push(pages[i]);
				pf++;
			}
		}
	}
	cout<<"\nPage fault: "<<pf;
	return 0;
}
