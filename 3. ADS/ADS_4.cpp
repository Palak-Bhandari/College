#include <bits/stdc++.h> 
using namespace std;    
#define V 5  
class Edge {
public:
    int src, dest, weight;
};
class Graph1 {
public:
    int Vertex, E;
    Edge* edge;
}; 
class subset {
public:
    int parent;
    int rank;
};
Graph1* createGraph(int Vertex, int E){
    Graph1* graph1 = new Graph1;
    graph1->Vertex = Vertex;
    graph1->E = E;
    graph1->edge = new Edge[E];
    return graph1;
}
int find(subset subsets[], int i){
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void Union(subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int myComp(const void* a, const void* b){
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}
void KruskalMST(Graph1* graph1){
    int Vertex = graph1->Vertex;
    Edge result[Vertex]; 
    int e = 0; 
    int i = 0; 
    qsort(graph1->edge, graph1->E, sizeof(graph1->edge[0]),
          myComp);
    subset* subsets = new subset[(Vertex * sizeof(subset))];
    for (int v = 0; v < Vertex; ++v){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < Vertex - 1 && i < graph1->E){
        Edge next_edge = graph1->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y){
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    cout << "Following are the edges in the constructed MST\n";
    int minimumCost = 0;
    for (i = 0; i < e; ++i){
        cout << result[i].src << " -- " << result[i].dest
             << " == " << result[i].weight << endl;
        minimumCost = minimumCost + result[i].weight;
    }
    cout << "Minimum Cost Spanning Tree: " << minimumCost << endl;
}
// Prims MST
int minKey(int key[], bool mstSet[]){   
    int min = INT_MAX, min_index;   
    for (int v = 0; v < V; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
    return min_index;  
}  
void printMST(int parent[], int graph[V][V]){  
    cout<<"Edge \tWeight\n";  
    for (int i = 1; i < V; i++)  
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
}   
void primMST(int graph[V][V]){   
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
    printMST(parent, graph);  
}  
int main(){  
	int choice;
	char ch;
	do{
	cout<<"1. Prims Algorithm\n2. Kruskals Algorithm\n3. Exit\n Enter your choice: ";
	cin>>choice;
	switch(choice){
		case 1:{	int graph[V][V];
				    cout<<"Enter the values: ";
					for(int i=0;i<V;i++){
						for(int j=0;j<V;j++){
							cin>>graph[i][j];
						}
					}   
					primMST(graph); 
					break;
				}  
		case 2: {	int Vertex,E;
					cout<<"Enter no of Vertex: ";
					cin>>Vertex;
					cout<<"Enter no of Edges: ";
					cin>>E;
					Graph1* graph1 = createGraph(Vertex, E);
					for(int i = 0; i < E; i++){
						cout<<"Enter source: ";
						cin>> graph1->edge[i].src;
						cout<<"Enter destination: ";
						cin>> graph1->edge[i].dest;
						cout<<"Enter weight: ";
						cin>> graph1->edge[i].weight;
						cout<<endl;
					}
				    KruskalMST(graph1);  
				   	break;
				}
		case 3: exit(0);
				break;
		default: cout<<"Invalid Choice!!";
	}
	cout<<"Do you want to continue (Y/N): ";
	cin>>ch;
	}while(ch == 'Y' || ch == 'y');
    return 0;  
}  
