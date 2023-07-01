#include <bits/stdc++.h>
using namespace std;
class Node{
	public:
	Node *left, *right;
	int info; 	 			// True if left pointer points to predecessor in Inorder Traversal
	bool lthread;  			// True if right pointer points to successor in Inorder Traversal	
	bool rthread;
//	Node(){
//		left=NULL;
//		right=NULL;
//		lthread=true;
//		rthread=true;
//	} 
	Node* insert(Node* root, int ikey){ 		// Insert a Node in Binary Threaded Tree
		Node* ptr = root;  						// Searching for a Node with given value
		Node* par = NULL;  						// Parent of key to be inserted
		while (ptr != NULL){
			if (ikey == ptr->info){ 			// If key already exists, return
				cout<<endl<<"Duplicate Key!";
				return root;
		}
		par = ptr;  							// Update parent pointer	
		if (ikey < ptr->info) { 				// Moving on left subtree.
			if (ptr->lthread == false)
				ptr = ptr->left;
			else
				break;
		}
		else { 									// Moving on right subtree.
			if (ptr->rthread == false)
				ptr = ptr->right;
			else
				break;
			}
		}
		Node* tmp = new Node; 					// Create a new Node
		tmp->info = ikey;
		tmp->lthread = true;
		tmp->rthread = true;
		if (par == NULL){
			root = tmp;
			tmp->left = NULL;
			tmp->right = NULL;	
		}  
		//cout<<endl<<root<<"=>"<<root->lthread<<" "<<root->left<<" "<<"=="<<root->info<<"=="<<root->right<<" "<<root->rthread;
		else if (ikey < (par->info)){
			tmp->left = par->left; 				// Prececessor
			tmp->right = par; 					// Successor
			par->lthread = false; 				// lthread is converted to left link T ===> False
			par->left = tmp; 					// Tmp will become left child.
			//cout<<endl<<tmp<<"=>"<<tmp->lthread<<" "<<tmp->left<<" "<<"=="<<tmp->info<<"=="<<tmp->right<<" "<<tmp->rthread;
		}
		else{
			tmp->left = par; 					// Parent will become the predecessor for its right child.
			tmp->right = par->right; 			// right pointer will Point to Successor
			par->rthread = false; 				// Convert Thread to link.
			par->right = tmp; 					// New node will become right child of parent.
			//cout<<endl<<tmp<<"=>"<<tmp->lthread<<" "<<tmp->left<<" "<<"=="<<tmp->info<<"=="<<tmp->right<<" "<<tmp->rthread;
		}
		return root;
	}
	void inorder(Node* root){	//Recursive
		if(root == NULL)
			return;
		if(root->lthread == false) 					//First recur on left subtree
			inorder(root->left);
		cout << root->info<< " "; 					//Then read the data of child
		if(root->rthread == false)					// Recur on the right subtree
			inorder(root->right);
	}
	void preorder(Node* root){ 						// Recursive Preorder Traversing
		if(root == NULL)
			return;
		cout << root->info<< " "; 					//First read the data of child
		if(root->lthread == false) 					//Then recur on left subtree
			preorder(root->left);
		if(root->rthread == false) 					//Then Recur on the right subtree
			preorder(root->right);
	}
	void postorder(Node* root){ 					// Recursive Podtorder Traversing
		if(root == NULL)
			return;
		if(root->lthread == false) 					//Then recur on left subtree
			postorder(root->left);
		if(root->rthread == false) 					//Then Recur on the right subtree
			postorder(root->right);
		cout << root->info<< " "; 					//First read the data of child
	}
	Node* inorderSuccessor(Node* ptr){ 				// Returns inorder successor using rthread (Used in inorder)
		if (ptr->rthread == true) 					// If rthread is set, we can quickly find
			return ptr->right;
		ptr = ptr->right; 							// Else return leftmost child of right subtree
		while (ptr->lthread == false)
			ptr = ptr->left;
		return ptr;
	}
	void inOrder(Node* root){	// Non-recursive
		if (root == NULL)
			cout<<endl<<"\t Tree is empty";
		Node* ptr = root; 							// Reach leftmost Node
		while (ptr->lthread == false)
			ptr = ptr->left;
		while (ptr != NULL) { 						// One by one print successors
			cout<<" "<<ptr->info; 					//cout<<endl<<"\t Tree is as :-";
			ptr = inorderSuccessor(ptr);
		}
	}
	void preOrder(Node *root){	// Non-recursive
		Node *ptr;
		if(root==NULL){
			cout<<"Tree is empty";
			return;
		}
		ptr=root;
		while(ptr!=NULL){
			cout<<ptr->info<<" ";
			if(ptr->lthread==false)
				ptr=ptr->left;
			else if(ptr->rthread==false)
				ptr=ptr->right;
			else{
				while(ptr!=NULL && ptr->rthread==true)
					ptr=ptr->right; 					// go to successor / parent
					if(ptr!=NULL)
						ptr=ptr->right; 				// go to right child of successor / parent	
			}
		}
	}
	Node* inSucc(Node* ptr){							// Returns inorder successor using left and right children (Used in deletion)
		if (ptr->rthread == true)
			return ptr->right;
		ptr = ptr->right;
		while (ptr->lthread == false)
			ptr = ptr->left;
		return ptr;
	}
	Node* inPred(Node* ptr){							// Returns inorder predessor using left and right children (Used in deletion)
		if (ptr->lthread == true)
			return ptr->left;
		ptr = ptr->left;
		while (ptr->rthread == false)
			ptr = ptr->right;
		return ptr;
	}
	Node* caseA(Node* root, Node* par,Node* ptr){	 	// Here 'par' is pointer to parent Node and 'ptr' is pointer to current Node.
		if (par == NULL) 							 	// If Node to be deleted is root
			root = NULL;
		else if (ptr == par->left){ 				 	// If Node to be deleted is left of its parent
			par->lthread = true;	
			par->left = ptr->left;
		}
		else{
			par->rthread = true;
			par->right = ptr->right;
		}
		delete ptr; 									// Free memory and return new root
		return root;
	}
	Node* caseB(Node* root, Node* par,Node* ptr){ 		// Here 'par' is pointer to parent Node and 'ptr' is pointer to current Node.
		Node* child; 									// Initialize child Node to be deleted has left child.
		if (ptr->lthread == false)	
			child = ptr->left;
		else 											// Node to be deleted has right child.
			child = ptr->right;
		if (par == NULL) 								// Node to be deleted is root Node.
			root = child;
		else if (ptr == par->left) 						// Node is left child of its parent.
			par->left = child;
		else
			par->right = child;
		Node* s = inSucc(ptr); 							// Find successor and predecessor
		Node* p = inPred(ptr);
		if (ptr->lthread == false) 						// If ptr has left subtree.
			p->right = s;
		else{ 											// If ptr has right subtree.
			if (ptr->rthread == false)
			s->left = p;
		}
		delete ptr;
		return root;
	}
	Node* caseC(Node* root,Node* par,Node* ptr){ 		// Here 'par' is pointer to parent Node and 'ptr' is pointer to current Node.
		Node* parsucc = ptr; 							// Find inorder successor and its parent.
		Node* succ = ptr->right;
		while (succ->lthread==false){ 					// Find leftmost child of successor
			parsucc = succ;
			succ = succ->left;
		}
		ptr->info = succ->info;
		if (succ->lthread == true && succ->rthread == true)
			root = caseA(root, parsucc, succ);
		else
			root = caseB(root, parsucc, succ);
		return root;
	}
	Node* delThreadedBST(Node* root, int dkey){ 		// Deletes a key from threaded BST with given root and returns new root of BST.
		Node *par = NULL, *ptr = root; 					// Initialize parent as NULL and ptrent Node as root.
		int found = 0; 									// Set true if key is found
		while (ptr != NULL){ 							// Search key in BST : find Node and its parent.
			if (dkey == ptr->info) {
				found = 1;
				break;
			}
			par = ptr;
			if (dkey < ptr->info){
				if (ptr->lthread == false)
					ptr = ptr->left;
				else
					break;
			}
			else{
				if (ptr->rthread == false)
					ptr = ptr->right;
				else
					break;
			}
		}
		if (found == 0)
			cout<<"dkey not present in tree\n";		
		else if (ptr->lthread == false && ptr->rthread == false) 	// Two Children
			root = caseC(root, par, ptr);		
		else if (ptr->lthread == false) 							// Only Left Child
			root = caseB(root, par, ptr);		
		else if (ptr->rthread == false) 							// Only Right Child
			root = caseB(root, par, ptr);		
		else 														// No child
			root = caseA(root, par, ptr);
		return root;
	}
	Node* search(Node* root, int key) { 
		if(root == NULL || root->info == key)
			return root;
		if(root->info < key && root->rthread==false) 				// Key is greater than root's data
			return search(root->right,key);		 
		else if (root->info > key && root->lthread==false) 			// Key is smaller than root's data
			return search(root->left,key);
	}
	void printLevelOrder(Node *root){ 								// Level Order Printing
		if (root == NULL) return; 									// Base Case	
		queue<Node *> q;											// Create an empty queue for level order tarversal	
		q.push(root); 												// Enqueue Root and initialize height
		while (q.empty() == false){
			int nodeCount = q.size();
			cout<<" --> "; 									    	// Dequeue all nodes of current level and Enqueue all nodes of next level
			while (nodeCount > 0){
				Node *node = q.front();
				cout<<node->info<<" ";
				q.pop();
				if (node->left != NULL && node->lthread==false)
					q.push(node->left);
				if (node->right != NULL && node->rthread==false)
					q.push(node->right);
				nodeCount--;
			}
		}
	} 
	void postOrder(Node* root){// Non-Recursive Postorder Traversal
		stack<Node*> S1;
		stack<Node*> S2;
		S1.push(root);
		while(!S1.empty()){
			S2.push(S1.top());
			Node* temp=S1.top();
			S1.pop();
			if(temp->lthread == false) 
				S1.push(temp->left);
			if(temp->rthread == false) 
				S1.push(temp->right);
		}
		while(!S2.empty()){
			Node* temp=S2.top();
			S2.pop();
			cout<<temp->info<<" ";
		}
		cout<<endl;
	}
};
int main(){
	Node Tree;
	Node* root = NULL;
	int choice;
	char ch='Y';
	while(ch=='Y'||ch=='y'){
	cout<<"Operations on Threaded Binary Tree -"<<endl;
	cout<<"1. Create"<<endl<<"2. Insert"<<endl<<"3. Delete"<<endl<<"4. Search"<<endl<<"5. Display"<<endl<<"6. Breadth First Search / LOP"<<endl<<"7. Quit :";
	cin>>choice;
	switch(choice){
		case 1: int t; //Number of nodes to be inserted
				cout<<endl<<"Enter number of nodes you want to insert - ";
				cin>>t;
				while(t--){
					int data;
					cout<<endl<<"Enter "<<t<<" Element -  ";
					cin>>data;
					root = Tree.insert(root,data);
				}
				cout<<endl<<"TBT Constructed!"<<endl;
				break;
		case 2: t=0;
				cout<<endl<<"Enter data to insert in TBT :- ";
				cin>>t;
				root = Tree.insert(root,t);
				cout<<endl<<"Node added in TBT! ";
				break;
		case 3: int delete_data;
				cout<<endl<<"Enter the node tobe Deleted :-";
				cin>>delete_data;
				root = Tree.delThreadedBST(root, delete_data);
				cout<<endl<<"Non-Recursive Inorder Traversal of TBT is as :- ";
				Tree.inOrder(root);
				break;
		case 4: if(root!=NULL){ 
					cout<<endl<<"Enter the data to Search in TBT :";
					int data;
					cin>>data;
					if(Tree.search(root,data)!=NULL)
						cout<<endl<<data<<" is found in TBT!";
					else
						cout<<endl<<data<<" is not found in TBT!";
				}
				else
					cout<<endl<<"TBT is Empty!";
				break;
		case 5: if(root!=NULL){
					cout<<endl<<"TBT Traversals are as follows: ";
					cout<<endl<<"Inorder Traversal of Tree is : ";
					Tree.inorder(root);
					cout<<endl<<"Non-recursive Inorder Traversal of Tree is : ";
					Tree.inOrder(root);
					cout<<endl<<"Preorder Traversal of Tree is : ";
					Tree.preorder(root);
					cout<<endl<<"Non-recursive Preorder Traversal of Tree is : ";
					Tree.preOrder(root);
					cout<<endl<<"Postorder Traversal of Tree is : ";
					Tree.postorder(root);
					cout<<endl<<"Non-recursive Postorder Traversal of Tree is : ";
					Tree.postOrder(root);
				}
				else
					cout<<endl<<"TBT is Empty!";
				break;
		case 6: if(root!=NULL){
					cout<<endl<<"Breadth First Search Traversal (LOP) :- ";
					Tree.printLevelOrder(root);
				}
				else
					cout<<endl<<"TBT is Empty!";
				break;
		case 7: exit(0);
		default:cout<<endl<<"Invalid Choice! Re-enter your choice Again !";
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
