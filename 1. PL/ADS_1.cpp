#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* left;
		Node* right;
		bool visited;
		Node(int d){
			data = d;
			left = NULL;
			right = NULL;
		}
	Node* search(Node* root, int key){
		if(root == NULL || root->data == key)
			return root;
		if(root->data < key)   	// Key is greater than root's data
			return search(root->right,key);
		return search(root->left,key); // Key is smaller than root's data
	}
	Node* insert(Node* root, int data){
		if(root == NULL){
			return new Node(data);
		}
		else{
			Node* cur;
			if(data <= root->data){
				cur = insert(root->left, data);
				root->left = cur;
			}
			else{
				cur = insert(root->right, data);
				root->right = cur;
			}
			return root;
		}
	}
	Node* deletenode(Node* root, int key){
		if (root == NULL) // Base case
			return root;
		if(root->data > key){ //If root->data is greater than k then we delete the root's subtree
			root->left = deletenode(root->left, key);
			return root;
		}
		else if(root->data < key){
			root->right = deletenode(root->right, key);
			return root;
		}
		if (root->left == NULL){ // If one of the children is empty
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}
		else{
			Node* Parent = root;
			Node* succ = root->right; // Find successor of the node
			while (succ->left != NULL){
				Parent = succ;
				succ = succ->left;
			}
			if (Parent != root)
				Parent->left = succ->right;
			else
				Parent->right = succ->right;
			root->data = succ->data; // Copy Successor Data		 
			delete succ; // Delete Successor and return root
			return root;
		}
		/*else{
			Node* Parent = root;
			Node* pre = root->left; // Find predecessor of the node
			while (pre->right != NULL){
				Parent = pre;
				pre = pre->left;
			}
			if (Parent != root)
				Parent->right = pre->left;
			else
				Parent->left = pre->left;
			root->data = pre->data; // Copy predecessor Data		 
			delete pre; // Delete predecessor and return root
			return root;
		}*/
	}
	void inorder(Node* root){
		if(root == NULL)
			return;		
		inorder(root->left); //First recur on left subtree		
		cout << root->data << " "; //Then read the data of child		
		inorder(root->right); // Recur on the right subtree
	}
	void preorder(Node* root){
		if(root == NULL)
			return;		
		cout << root->data << " "; //First read the data of child		
		preorder(root->left); //Then recur on left subtree		
		preorder(root->right); //Then Recur on the right subtree
	}
	void postorder(Node* root){
		if(root == NULL)
			return;		
		postorder(root->left); //Then recur on left subtree		
		postorder(root->right); //Then Recur on the right subtree		
		cout << root->data << " "; //First read the data of child
	}	
	void inOrder(Node *root){ // Non recursive Inorder Traversal using Stack.
		stack<Node *> s;
		Node *curr = root;
		while (curr != NULL || s.empty() == false){
			while (curr != NULL){ 	// Reach the left most Node of the curr Node
				s.push(curr);	//place pointer to a tree node on the stack before traversing the node's left subtree
				curr = curr->left;
			}	
			curr = s.top(); // Current must be NULL at this point
			s.pop();
			cout << curr->data << " ";
			curr = curr->right;	// we have visited the node and its left subtree. Now, it's right subtree's turn
		}
	}
	void preOrder(Node* root){ // Non recursive Preorder Traversal using Stack.
		if (root == NULL) // Base Case
			return;	
		stack<Node *> s; // Create an empty stack and push root to it
		s.push(root);
		/*Pop all items one by one. Do following for every popped item 
		a) print it
		b) push its right child 
		c) push its left child Note that right child is pushed first so that left is processed first*/
		while (s.empty() == false){			
			Node* node = s.top(); // Pop the top item from stack and print it
			cout<<node->data<<" "; 
			s.pop();			
			if (node->right!=NULL)
				s.push(node->right); // Push right and left children of the popped node to stack
			if (node->left!=NULL)
				s.push(node->left);
		}
	}
	/*void postOrder(Node *root){	
		if (root == NULL) return; // Base Case
		stack<Node *> s1; 	// Create two empty stack for post order traversal
		stack<Node *> s2;
		s1.push(root); 	// Enqueue Root and initialize height
		while (s1.empty() == false){
			Node *node = s1.top();
			s1.pop();
			s2.push(node);
			if (node->left != NULL)
				s1.push(node->left);
			if (node->right != NULL)
				s1.push(node->right);
		}
		while(!s2.empty()){
			Node *n= s2.top();
			cout<<n->data<<" ";
			s2.pop();
		}
	}*/	
	void postOrder(Node* head){ // non- recursive post order traversal
	    Node* temp = head;
	    while (temp && temp->visited == false) {	 
	        if (temp->left && temp->left->visited == false)
	            temp = temp->left;	 
	        else if (temp->right && temp->right->visited == false)
	            temp = temp->right;
	        else {
	            cout<<temp->data;
	            temp->visited = true;
	            temp = head;
	        }
	    }
	}
	void printLevelOrder(Node *root){ // Level Order Printing
		if (root == NULL) return; 	// Base Case	
		queue<Node *> q; // Create an empty queue for level order tarversal
		q.push(root); 	// Enqueue Root and initialize height
		while (q.empty() == false){	
			int nodeCount = q.size(); // nodeCount (queue size) indicates number of nodes at current level.
			cout<<" --> ";
			while (nodeCount > 0){ // Dequeue all nodes of current level and Enqueue all nodes of next level
				Node *node = q.front();
				cout<<node->data<<" ";
				q.pop();
				if (node->left != NULL)
					q.push(node->left);
				if (node->right != NULL)
					q.push(node->right);
				nodeCount--;
			}
		}
	}
};
int main(){
	Node Tree(0);
	Node* root = NULL;
	int choice;
	char ch='Y';
	while(ch=='Y'||ch=='y'){
		cout<<"Operations on Binary Search Tree"<<endl;
		cout<<"1.Create\n2.Insert\n3.Delete\n4.Search\n5.Display\n6.Breadth First Search / LOP\n7.Quit"<<endl;
		cout<<"Enter your Choice:- ";
		cin>>choice;
		switch(choice){
		case 1:	int t; 	//Number of nodes to be inserted
				cout<<endl<<"Enter number of nodes you want to insert :- ";
				cin>>t;
				while(t--){
					int data;
					cout<<endl<<"Enter "<<t<<" Element - ";
					cin>>data;
					root = Tree.insert(root,data);
				}
				cout<<endl<<" BST Constructed! "<<endl;
				break;
		case 2: t=0;
				cout<<endl<<"Enter data to insert in BST :- ";
				cin>>t;
				root = Tree.insert(root,t);
				cout<<endl<<"Elements Inserted! ";
				break;
		case 3: int delete_data;
				cout<<endl<<"Enter the node to be Deleted :-";
				cin>>delete_data;	
				Tree.deletenode(root,delete_data);
				cout<<endl<<"Inorder Traversal is of Tree is as :- ";
				Tree.inorder(root);
				break;
		case 4:	if(root!=NULL){
					cout<<endl<<"Enter the data to Search in BST :";
					int data;
					cin>>data;
					if(Tree.search(root,data)!=NULL)
						cout<<endl<<data<<" is found in BST! ";
					else
						cout<<endl<<data<<" is not found in BST! ";
				}
				else
					cout<<endl<<"BST is Empty! ";
				break;
		case 5: if(root!=NULL){
					cout<<endl<<"Tree Traversals are as follws :- ";
					cout<<endl<<"Inorder Traversal of Tree is :- ";
					Tree.inorder(root);
					cout<<endl<<"Non-recursive Inorder Traversal of Tree is :- ";
					Tree.inOrder(root);
					cout<<endl<<"Preorder Traversal of Tree is :- ";
					Tree.preorder(root);
					cout<<endl<<"Non-recursive Preorder Traversal of Tree is :- ";
					Tree.preOrder(root);
					cout<<endl<<"Postorder Traversal of Tree is :- ";
					Tree.postorder(root);
					cout<<endl<<"Non-recursive Postorder Traversal of Tree is :- ";
					Tree.postOrder(root);
				}
				else
					cout<<endl<<"BST is Empty! ";
				break;
		case 6: if(root!=NULL){
					cout<<endl<<"Breadth First Search Traversal (LOP) :- ";
					Tree.printLevelOrder(root);
				}
				else
					cout<<endl<<"BST is Empty! ";
				break;
		case 7: exit(0);
		default:cout<<endl<<"Invalid Choice! Re-enter your choice";
				break;
		}
		cout<<endl<<endl<<"Do you want to continue (Y/N) ? ";
		cin>>ch;
		if(ch=='Y' || ch=='y')
			continue;
		else
			exit(0);
	}
	return 0;
}
