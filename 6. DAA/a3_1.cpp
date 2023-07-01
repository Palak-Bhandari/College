#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int no = n;
    int start[n], end[n], p[n], flag[n];
    cout<<"Enter start and end respectively: ";
    for(int i=0;i<n;i++){
        cin>>start[i];
        cin>>end[i];
        p[i]=i+1;
        flag[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(end[j]>end[j+1]){
                swap(p[j],p[j+1]);
                swap(start[j],start[j+1]);
                swap(end[j],end[j+1]);
            }
        }
    }
    cout<<"sorted array: ";
    for(int i=0;i<n;i++){
        cout<<"\n"<<p[i]<<"\t"<<start[i]<<"\t"<<end[i]<<"\t"<<flag[i]<<endl;
    }
    int min_cab = 0;
    n--;
    int j;
    while(n>0){
        int k=0;
        while(flag[k]==1){
            k++;
        }
        j = k;
        flag[0]=1;
        for(int i=j+1;i<no;i++){
            if(start[i]>=end[j] && flag[i]==0){
                j = i;
                flag[i] = 1;
                n--;
            }
        }
        min_cab++;
    }
    cout<<min_cab;
    return 0;
}
