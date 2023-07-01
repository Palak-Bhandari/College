#include<iostream>
using namespace std;
int main(){
    int i,hash[100],choice,n,flag,item,key;
    cout<<"\nEnter size of Array (Hash Table): ";
    cin>>n;
    for(i=0;i<n;i++)
        hash[i]=-1;
    while(1){
        cout<<"\nFollowing operations can be performed on Hash Table: "<<endl;
        cout<<"\n1. Insert";
        cout<<"\n2. Search";
        cout<<"\n3. Delete";
        cout<<"\n4. Display";
        cout<<"\n5. Exit"<<endl;
        cout<<"\nEnter your Choice: ";
        cin>>choice;
        flag=0;
        switch(choice){
            case 1: cout<<"\nAccept the item to insert in heap: ";
                    cin>>item;
                    key= item % n;
                    if(hash[key] == -1){
                        hash[key] = item;
                        flag=1;
                    }
                    else{
                        for(i=key+1;i<n;i++){
                            if(hash[i]==-1){
                                hash[i]=item;
                                flag=1;
				                break;
                            }
                            if(flag!=1) i=i%n;
                        }
                    }
                    if(flag==1)
                        cout<<"\nItem Inserted Succesfully"<<endl;
                    else
                        cout<<"\nHash Overflow"<<endl;
                    break;
            case 2: cout<<"\nAccept the item to search in Heap: ";
                    cin>>item;
                    key= item % n;
                    for(i=key;i<n;i++)
                        if(hash[i]==item){
                            flag=1;
                            break;
                        }        
                    if(flag==1)
                        cout<<"\nItem "<<item<<" present at "<<i<<"th index in the heap"<<endl;
                    else
                        cout<<"\nItem "<<item<<" does not exist in the heap"<<endl;                
                    break;
            case 3: cout<<"\nAccept the item to be deleted: ";
                    cin>>item;
                    key= item % n;
                    for(i=key;i<n;i++)
                        if(hash[i]==item){
                            flag=1;
                            break;
                        }
                    if(flag==1){
                        cout<<"\nItem "<<item<<" present at "<<i<<"th index in the heap is deleted"<<endl;
                        hash[i]=-1;
                    }
                    else
                        cout<<"\nItem "<<item<<" does not exist in the heap"<<endl;                
                    break;
            case 4: cout<<"\n Hash Table is : ";
                    for(i=0;i<n;i++)
                        cout<<hash[i]<<" ";
                    cout<<endl;
                    break;
            case 5: exit(0);break;
            default : cout<<"\nInvaild Choice!"<<endl;break;
        }
    }
    return 0;
}
