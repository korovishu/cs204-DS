#include <bits/stdc++.h> 
using namespace std;  
class Node
{
public:
    int value;
    Node* nxt;
};
class Node* createnode()
{
    Node* node = new Node;
    return node;
}
void push(Node** root,int x)
{
    Node* temp = createnode();
    if(*root==NULL)
    {
        *root=temp;
        temp->value=x;
        temp->nxt=NULL;
    }
    else
    {
        Node* t = *root;
        while(t->nxt!=NULL)
        {
            t=t->nxt;
        }
        t->nxt=temp;
        temp->value=x;
        temp->nxt=NULL;
    }
}
void pop(Node** root)
{
    Node *a;
    a=*root;
    if(a==NULL) {cout<<"Queue is empty!\n";return;}
    cout<<a->value<<" is popped"<<endl;
    *root=a->nxt;
    delete a;
    return;
}
bool isempty(Node* root)
{
    if(root==NULL) return true;
    return false; 
}
int main()
{
    Node* root=NULL;
    //enter a number greater than 3 to terminate
    while(1)
    {
        int a; cin>>a;
        if(a==1)
        {
            int v;cin>>v;
            push(&root,v);
        }
        else if(a==2)
        {
            pop(&root);
        }
        else if(a==3)
        {
            if(isempty(root)) cout<<"Queue is empty\n";
            else cout<<"Queue is not empty\n";
        }
        else break;
    }
}
