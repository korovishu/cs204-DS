#include <bits/stdc++.h> 
using namespace std;
	
struct node 
{ 	
	int key; 
	struct node *left, *right; 
}; 	
	
struct node *newNode(int item) 
{ 	
	struct node *temp = new node(); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 	
	
void inorder(struct node *root) 
{ 	
	if (root != NULL) 
	{ 
		inorder(root->left); 
		cout<<root->key<<" "; 
		inorder(root->right); 
	} 
} 	
	
struct node* insert(struct node* node, int key) 
{ 	

	if (node == NULL) return newNode(key); 


	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	return node; 
} 	
	
struct node * minValueNode(struct node* node) 
{ 	
    struct node* current = node; 
  	
    while (current && current->left != NULL) 
        current = current->left; 
  	
    return current; 
} 	
	
struct node* deleteNode(struct node* root, int key) 
{ 	
    if (root == NULL){ cout<<"Key is not present\n";return root;} 

    if (key < root->key) 
        root->left = deleteNode(root->left, key); 

    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
    
    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
 	
        struct node* temp = minValueNode(root->right); 
        root->key = temp->key; 
    
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 	
	
void postorder( node* root) {
        if(root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
void preorder( node* root) {
        if(root == NULL) return;
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }

int main() 
{ 	
	
	struct node *root = NULL; 
	int a=0;
	while(a!=7)
	{
		cin>>a;
		if(a==1)
		{
			int x;
			cin>>x;
			root = insert(root,x);
		}
		if(a==2)
		{
			int x;
			cin>>x;
			root = deleteNode(root,x);
		}
		if(a==3)
		{
			node* min = minValueNode(root);
			if(root!=NULL)
			cout<<root->key<<"\n";
			else
				cout<<"Tree is empty\n";
		}
		if(a==4)
		{
			inorder(root);
			cout<<endl;
		}
		if(a==5)
		{
			preorder(root);
			cout<<endl;
		}
		if(a==6)
		{
			postorder(root);
			cout<<endl;
		}
	} 
	
	return 0; 
} 	
