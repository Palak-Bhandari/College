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
int main(){  
    int Vertex,E;
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
    return 0;  
}  