#include<stdio.h>
#include<stdlib.h>              // used to include malloc(),free() 

struct NODE                     //STRUCTURE DEFINITION
{
   int KEY;                    // varible to hold the value
   struct NODE * NEXT;         // pointer to point next node
};

struct NODE *SP=NULL;         // initally stack pointer set to NULL (0)

//MAIN FUNCTION
void main()
{
	int option,item,ans;

//FUNCTION PROTOTYPES
void push(int); 
int pop();
int search(int);
void display();

do //DO-WHILE LOOP TO PERFORM MENU 
{
  printf("\n 1.INSERT\n 2.DELETE\n 3.SEARCH\n 4.DISPLAY\n 5.EXIT\n");
  printf("\nENTER AN OPTION : ");
  scanf("%d",&option);
 
 switch(option) //SWITCH TO SELECT THE MATCHING CASE
 {
   case 1:printf("\nEnter a value to insert :");
          scanf("%d",&item);
          push(item);
          printf("%d is inserted \n",item);
          break;
   case 2:pop();
          printf("\n");
          break;
   case 3:printf("\nEnter a value to be searched:");
          scanf("%d",&item);
          ans=search(item);
           if(!ans)
            	printf("Not Found");
           else 
            	printf("Found");
          break;
          printf("\n");
   case 4:display();
          printf("\n");
          break;   
 } //END OF SWITCH
}while(option!=5); //END OF WHILE

}//END OF MAIN

//DISPLAY FUNCTION
void display()
{
     struct NODE *sp=SP; //creating a copy stack pointer to operate the loop without tampering the original one
     
     if(sp==NULL)  //checking whether the stack is empty
     printf("Stack is empty.");
     else
     {
      while(sp!=NULL) // loop will work till stack pointer is not equal to null 
      {
      printf(" %d ",sp->KEY);      
      sp=sp->NEXT;                 
      }
     }
}//END OF DISPLAY

//PUSH FUNCTION
void push(int x)
{
	//creating a node
   struct NODE *newNODE;
   newNODE=(struct NODE*)malloc(sizeof(struct NODE)); //allocating memmory    
   newNODE->KEY=x;   // filling the data                                    
   newNODE->NEXT=SP; //pushing                                              
   SP=newNODE;

}//END OF PUSH FUNCTION

//POP FUNCTION
int pop()
{
  int temp;         //temp varible to hold the poping item
  struct NODE *prePointer; //  pointer to preserve the pointer of poping node 

  if(SP!=(struct NODE *)0)
  {
     temp=SP->KEY;  //poping item is stored to temp 
     prePointer=SP; //preserving the stack pointer
     SP=SP->NEXT;   //stack pointer set to point to next node              
    
     printf("%d is deleted",temp); // printing poped item
    
    free(prePointer); // freeing the memory allocated to the poped node
   
   return temp; //returning the poped item
  }
else 
	printf("STACK IS EMPTY\n");
  return 0;
}//END OF POP FUNCTION

//SEARCH FUNCTION
int search(int x)
{
  struct NODE *sp=SP; //creating a copy stack pointer to operate the loop without tampering the original one
 
  while(sp!=NULL && sp->KEY!=x) //loop will work while stack pointer is not equal to NULL (stack is not empty) and key is not equal to the item that is to be searched
    sp=sp->NEXT;
  
   if(sp==(struct NODE *)0)
    {
      return 0;  //Not Found
    }
   else
   {
      return 1;  //Found
  }
}//end of search