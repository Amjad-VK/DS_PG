#include<stdio.h>
#include<stdlib.h>
struct node *L=0,*t;
struct node
{
int key;
struct node *prev,*next;
};
void main()
{
struct node * insertdll(struct node *,int);  //insert
struct node * deletedll(struct node * ,struct node *); //delete
struct node * search(struct node *,int); //search
void display(struct node *); //display
int opt,key;
do
{
printf("\n 1.Insert\n 2.Delete\n 3.Search\n 4.Display\n 5.Exit\n"); //options given
printf("option:");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("Data:");
scanf("%d",&key);
L=insertdll(L,key);
printf("Successfully inserted");
break;
case 2:printf("Data:");
scanf("%d" ,&key);
t=search(L,key);
if(t!=(struct node *)0)
{
L=deletedll(L,t);
printf("%d is deleted",key);
}
else printf("Not found\n");
break;
case 3:printf("Data:");
scanf("%d" ,&key);
t=search(L,key);
if(t==(struct node *)0)
printf("Not found");
else printf("found");
break;
case 4:display(L);
break;
case 5:exit(0);
break;
}
}while(1);
}

//function to insert value into the list
struct node * insertdll(struct node *L1,int k)
{
struct node *x;
x=(struct node *)malloc(sizeof(struct node));
x->key=k;
x->next=L;
x->prev=(struct node *)0;
if(L!=(struct node *)0)
L->prev=x;
L=x;
return L;
}

//function to display the list
void display(struct node *L1)
{
if(L1==(struct node *)0)
{
printf("list is empty");
return;
}
while(L1!=(struct node *)0)
{
printf("%d ",L1->key);
L1=L1->next;
}
}

//function to search an element from the list
struct node * search(struct node *L1,int key1)
{
while(L1!=(struct node *)0 &&L1->key!=key1)
L1=L1->next;
return L1;
}

//function to delete an element from the list
struct node * deletedll(struct node *L1,struct node *x)
{
if(x->prev!=(struct node *)0)
x->prev->next=x->next;
else
L1=L1->next;
if(x->next!=(struct node *)0)
x->next->prev=x->prev;
return L1;
}

