#include <bits/stdc++.h> 
using namespace std; 
using namespace std::chrono;
#define V 4   
int minKey(int key[], bool mstSet[]){   
    int min = INT_MAX, min_index;   
    for (int v = 0; v < V; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
    return min_index;  
}  
int printMST(int parent[], int graph[V][V]){  
    cout<<"Edge \tWeight\n";  
    int sum = 0;
    for (int i = 1; i < V; i++){
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
        sum += graph[i][parent[i]];
    } 
    return sum; 
        
}   
int primMST(int graph[V][V]){   
    int parent[V];    
    int key[V];    
    bool mstSet[V];   
    for (int i = 0; i < V; i++)  
        key[i] = INT_MAX, mstSet[i] = false;   
    key[0] = 0;  
    parent[0] = -1;   
    for (int count = 0; count < V - 1; count++){  
        int u = minKey(key, mstSet);    
        mstSet[u] = true;  
        for (int v = 0; v < V; v++)  
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])  
                parent[v] = u, key[v] = graph[u][v];  
    }    
    int a  = printMST(parent, graph);  
    return a;
}  
int main(){  
	int choice;
	char ch;
	int graph[V][V];
    cout<<"Enter the values: ";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>graph[i][j];
        }
    }   
    cout<<endl;
    auto start1 = std::chrono::steady_clock::now();
    int mst = primMST(graph);
    cout<<"Final Total weight for MST of minimum weight is: "<<mst;
    auto finish1 = std::chrono::steady_clock::now();
    double time1 = std::chrono::duration_cast < std::chrono::duration<double> > (finish1 - start1).count(); 
    cout << "\nTime Taken  = " << fixed << time1 << setprecision(10) << endl;
    return 0;  
}  
