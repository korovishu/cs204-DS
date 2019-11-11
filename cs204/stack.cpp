#include <bits/stdc++.h> 
using namespace std;
#define ll long long 
#define f(i, a, b) for(ll i=a;i<b;i++)
#define fi(i, a, b) for(ll i=b-1;i>=a;i--)
#define pb push_back
#define VI vector<int>
#define Vll vector<long long>

struct coordinate{
	int x;
	struct coordinate* next;
};

void Push(int a,struct coordinate** headptr){
	if(*headptr == NULL){
		*headptr = new coordinate();
		(*headptr)->x = a;
		(*headptr)->next = NULL;
	}
	else{
		coordinate* temp = new coordinate();
		temp->x =a;
		temp->next = NULL;
		coordinate* temp1 = *headptr;
		while(temp1->next!=NULL)
			temp1 = temp1->next;
		temp1->next = temp; 
	}

}

void Pop(struct coordinate** headptr)
{
	coordinate* temp1 = *headptr;
	coordinate* temp2 = NULL;
	while(temp1!=NULL &&temp1->next!=NULL){
		temp2 = temp1;
		temp1 = temp1->next;
	}
	if(temp1==NULL)
		cout<<"Stack is empty";
	else{
		cout<<temp1->x<<" is popped\n";
		if(temp2==NULL){
			free(temp1);
			*headptr = NULL;
		}
		else
		{
			temp2->next = NULL;
			free(temp1);		
		}
	}
}

void Top(coordinate** headptr)
{
	coordinate* temp = *headptr;
	while (temp!=NULL &&temp->next!=NULL)
	{
		temp = temp->next;
	}
	if(temp==NULL)
	cout<<"Stack is empty";
	else
	cout<<temp->x<<"\n";	
}

void size(coordinate ** headptr)
{
	coordinate* temp = *headptr;
	int i=0;
	while (temp!=NULL)
	{
		temp = temp->next;
		i++;
	}
	cout<<i<<"\n";
}

int main()
{
	coordinate* root = NULL;
	int a=0;
		while(a!=5){
			cin>>a;
			if(a==1)
			{
				int x;
				cin>>x;
				Push(x,&root);
			}
			if(a==2)
			{
				Pop(&root);
			}
			if(a==3)
			{
				Top(&root);
			}
			if(a==4)
			{
				size(&root);
			}
		}
}
