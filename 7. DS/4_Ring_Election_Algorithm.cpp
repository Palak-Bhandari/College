#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int id;
    bool isCoordinator;
    bool hasToken;
    Node(int id) : id(id), isCoordinator(false), hasToken(false) {}
    void sendToken(Node &receiver)
    {
        cout << "Node " << id << " sends the token to Node " << receiver.id << endl;
        receiver.receiveToken(*this);
        hasToken = false;
    }
    void receiveToken(Node &sender)
    {
        cout << "Node " << id << " receives the token from Node " << sender.id << endl;
        if (isCoordinator)
        {
            cout << "Node " << id << " is already the Coordinator" << endl;
        }
        else
        {
            isCoordinator = true;
            cout << "Node " << id << " becomes the new Coordinator" << endl;
        }
    }
};
int main()
{
    int numNodes;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    vector<Node> nodes;
    for (int i = 1; i <= numNodes; i++)
    {
        nodes.emplace_back(i);
    }
    int coordinatorId;
    cout << "Enter the ID of the initial Coordinator: ";
    cin >> coordinatorId;
    if (coordinatorId <= 0 || coordinatorId > numNodes)
    {
        cout << "Invalid Coordinator ID." << endl;
        return 1;
    }
    nodes[coordinatorId - 1].isCoordinator = true;
    nodes[coordinatorId - 1].hasToken = true;
    cout << "Node " << coordinatorId << " is the initial Coordinator" << endl;
    for (int i = 0; i < numNodes; i++)
    {
        int nextNodeIndex = (i + 1) % numNodes;
        nodes[i].sendToken(nodes[nextNodeIndex]);
    }
    
    return 0;
}
