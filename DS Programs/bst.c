#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
struct node *root=NULL;
int s=0;

struct node* createNode(int data)            // creating new node          
{
struct node *newNode=(struct node*)malloc(sizeof(struct node));  
newNode->data=data;        
newNode->left=NULL;
newNode->right=NULL;
return newNode; 
}

void insert(int data)                           //insertion                      
{
struct node *newNode=createNode(data);  
if(root == NULL)
{
root=newNode;
return;                         //Return a new node if the tree is empty
}
else
{
struct node *current=root,*parent=NULL;
while(1)
{
parent=current;
if(data < current->data)     //Traverse to the right place and insert the node
{
current=current->left;
if(current==NULL)
{
parent->left=newNode;
return;
}
}
else
{
current=current->right;
if(current==NULL)
{
parent->right=newNode;
return;
}
}
}
}
}

struct node* minNode(struct node *root)              // Find the inorder successor
{
if(root->left!=NULL)                           // Find the leftmost leaf           
return minNode(root->left);
else
return root;
}
int k=0;
struct node* deleteNode(struct node *node,int value)  //deleting a node
{
if(node==NULL)
return 0;                                    //Return a new node if the tree is empty
else
{
if(value<node->data)                   //find the value to be delete
node->left=deleteNode(node->left,value);
else if(value>node->data)
node->right=deleteNode(node->right,value);
else
{
k=1;
if(node->left==NULL)          // If the node is with only one child or no child
node=node->right;
else if(node->right==NULL)
node=node->left;
else                           
{
struct node *temp=minNode(node->right);      // If the node has two children
node->data=temp->data;                   // Place the inorder successor in position of the node to be delete       
node->right=deleteNode(node->right,temp->data); // Delete the inorder successor
}
}
root=node;
return node;
}
}

void inTraverse(struct node *node)                //function traverse
{
	if(root==NULL)                   
	{
	printf(" Tree is Empty\n");              //Return a new node if the tree is empty
	return;
	}
	else
	{
	if(node->left != NULL)
	inTraverse(node->left);                  // Traverse left
	printf(" %d ",node->data);
	if(node->right != NULL)
	inTraverse(node->right);                  // Traverse right
	}
}


int search(struct node *node,int data)              //function serach
{
if(root==NULL)                      
{
printf(" Tree is Empty\n");
return 0;                       //Return a new node if the tree is empty
}
else
{
if(node->left != NULL)     
search(node->left,data);
if(data==node->data)
{
printf(" %d ",node->data);
s=1;
}
else
printf(" %d ",node->data);
if(node->right != NULL)
search(node->right,data);
}
}

void main()    
{
int ch,data;
printf("\n BST");
while(1)
{
printf("\n1 : INSERT \n2 : DELETE \n3 : DISPLAY \n4 : SEARCH\n5 : EXIT\n Enter choice :");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("\n Enter data :");
	scanf("%d",&data);
	insert(data);
	printf("\n> %d Inserted sucessfully\n> BST : ",data);
	break;
case 2:if(root==NULL)
       {
	printf("\n> BST Empty");break;}
	printf("\n Enter data to delete :");
	scanf("%d",&data);
	k=0;
	if(root->left==NULL && root->right==NULL && root->data==data)
	{
	root=NULL;
	printf("\n %d Deleted sucessfully\n> BST : ",data);
     	break;
	}
	deleteNode(root,data);
	if(k==1)
	{
        printf("\n %d Deleted sucessfully.\n> BST : ",data);
	}
	else
	printf("\n Not found..");
        break;
case 3:printf("\n> BST : ");
       inTraverse(root);
       break;
case 4:printf("\n Enter data to search :");
	scanf("%d",&data);
	s=0;
	printf("\n> BST : ");
	search(root,data);
	if(s)
	{
	printf("\n> %d Found in the BST  ",data);
	}
	else
	printf("\n> Not found");
       break;
case 5:exit(0);
break;
}
}
}
