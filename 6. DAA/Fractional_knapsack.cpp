#include<bits/stdc++.h>
using namespace std;
int main(){
    int no,W;
    double total = 0.0;
    cout<<"Enter the no of items: ";
    cin>>no;
    cout<<"Enter capacity: ";
    cin>>W;
    int wt[no],profit[no],item[no];
    double ratio[no];
    cout<<"Enter wt and profit for each item respectively: ";
    for(int i=0;i<no;i++){
        item[i]=i;
        cin>>wt[i];
        cin>>profit[i];
        ratio[i] = (double)profit[i]/(double)wt[i];
    }
    for(int i=0;i<no;i++){
        for(int j=0;j<no-i;j++){
            if(ratio[j]<ratio[j+1]){
                swap(ratio[j],ratio[j+1]);
                swap(item[j],item[j+1]);
                swap(wt[j],wt[j+1]);
                swap(profit[j],profit[j+1]);
            }
        }
    }
    cout<<"Item\twt\tprofit\tratio\n";
    for(int i=0;i<no;i++){
        cout<<item[i]<<"\t"<<wt[i]<<"\t"<<profit[i]<<"\t"<<ratio[i]<<endl;
    }
    for (int i = 0; i < no; i++) {
        if (wt[i] <= W) {
            W -= wt[i];
            total += (double)profit[i];
        }
        else {
            total += (double)profit[i] * ((double)W / (double)wt[i]);
            break;
        }
	}
    cout<<"The Total is: "<<total;
    return 0;
}