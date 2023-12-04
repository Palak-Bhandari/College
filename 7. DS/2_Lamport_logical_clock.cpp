/*
The algorithm of Lamport timestamps is a simple algorithm used to determine the order of events in a
distributed computer system. As different nodes or processes will typically not be perfectly
synchronized, this algorithm is used to provide a partial ordering of events with minimal overhead, and
conceptually provide a starting point for the more advanced vector clock method. They are named after
their creator, Leslie Lamport. Distributed algorithms such as resource synchronization often depend
on some method of ordering events to function. For example, consider a system with two processes
and a disk. The processes send messages to each other, and also send messages to the disk requesting
access. The disk grants access in the order the messages were sent

*/

#include <iostream>
#include <vector>

using namespace std;

// Function to display the logical timestamp
void display(int e1, int e2,
             vector<int>& p1, vector<int>& p2)
{
    int i;

    cout << "\nThe time stamps of "
         "events in P1:\n";

    for (i = 0; i < e1; i++) {
        cout << p1[i] << " ";
    }

    cout << "\nThe time stamps of "
         "events in P2:\n";

    // Print the array p2[]
    for (i = 0; i < e2; i++)
        cout << p2[i] << " ";
}

int main()
{
    int e1, e2;

    // Get user input for the number of events for each process
    cout << "Enter the number of events for P1: ";
    cin >> e1;

    cout << "Enter the number of events for P2: ";
    cin >> e2;

    vector<vector<int> > m(e1, vector<int>(e2));
 
    // Get user input for the matrix m
    cout << "Enter the message passing events matrix m (1 for sent, -1 for received, 0 otherwise):" << endl;
    for (int i = 0; i < e1; i++) {
        for (int j = 0; j < e2; j++) {
            cin >> m[i][j];
        }
    }

    vector<int> p1(e1), p2(e2);

    // Initialize p1[] and p2[]
    for (int i = 0; i < e1; i++)
        p1[i] = i + 1;

    for (int i = 0; i < e2; i++)
        p2[i] = i + 1;

    cout << "\t";
    for (int i = 0; i < e2; i++)
        cout << "\te2" << i + 1;

    for (int i = 0; i < e1; i++) {

        cout << "\n e1" << i + 1 << "\t";

        for (int j = 0; j < e2; j++)
            cout << m[i][j] << "\t";
    }

    for (int i = 0; i < e1; i++) {
        for (int j = 0; j < e2; j++) {

            // Change the timestamp if the
            // message is sent
            if (m[i][j] == 1) {
                p2[j] = max(p2[j], p1[i] + 1);
                for (int k = j + 1; k < e2; k++)
                    p2[k] = p2[k - 1] + 1;
            }

            // Change the timestamp if the
            // message is received
            if (m[i][j] == -1) {
                p1[i] = max(p1[i], p2[j] + 1);
                for (int k = i + 1; k < e1; k++)
                    p1[k] = p1[k - 1] + 1;
            }
        }
    }

    // Function Call
    display(e1, e2, p1, p2);

    return 0;
}


/* OUTPUT
Enter the number of events for P1: 5
Enter the number of events for P2: 3
Enter the message passing events matrix m (1 for sent, -1 for received, 0 otherwise):
0 0 0
0 0 1
0 0 0
0 0 0
0 -1 0

        e21     e22     e23
 e11    0       0       0
 e12    0       0       1
 e13    0       0       0
 e14    0       0       0
 e15    0       -1      0
The time stamps of events in P1:
1 2 3 4 5
The time stamps of events in P2:
1 2 3
--------------------------------
Process exited after 118.8 seconds with return value 0
Press any key to continue . . .
*/
