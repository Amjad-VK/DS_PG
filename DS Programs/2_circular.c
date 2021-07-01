// PROGRAM FOR CIRCULAR QUEUE OPERATIONS 

#include<stdio.h>

int Q[5],HEAD=0,TAIL=0,SIZE=5;  // VARIBLES DECLARED AS GLOBAL

void main()
{
	void insertq(int);    // 'insertq' FUNCTION PROTOTYPE
	int deleteq(void);    // 'deleteq' FUNCTION PROTOTYPE
	int search(int);      //  'search' FUNCTION PROTOTYPE
	
	int option,item,result;  //VARIBLES DECLARED AS LOCAL 
	
	do
	{   printf("Select an option\n-----------------\n");
		printf("1. INSERT \n");
		printf("2. DELETE \n");
		printf("3. SEARCH \n");
		printf("4. EXIT   \n");

		printf("\n Enter your option :");
		scanf("%d",&option); // READING OPTION

		switch(option)  // SWITCH STATEMENT TO HANDLE THE OPTIONS
		{
			case 1:    // INSERT CASE BLOCK
			       printf("Enter item to Insert :");
				   scanf("%d",&item); // READING ITEM TO INSERT 
			       insertq(item);  // CALLLING 'insertq' FUNCTION
			       break;    
			case 2:    // DELETE CASE BLOCK
			       item=deleteq();    // DELETING ITEM FROM HEAD
			       if(item)
			       printf("ITEM DELETED %d \n",item); // PRINTING DELETED MSG
			       
			       break;
			case 3:    // SEARCH CASE BLOCK
			       printf("Enter an Item to Search : ");
			       scanf("%d",&item); // READING ITEM TO SEARCH
			       result = search(item); // CALLING 'search' FUNCTION FUNCTION WILL RETURN 0 IF ITEM NOT FOUND . IF ITEM FOUND THEN 1 WILL BE RETURND 
			       if(!result) 
			       	printf("%d IS NOT FOUND \n",item);  // RETURN 0
			       else 
			       	printf("%d IS FOUND",item);         // RETURN 1
			       break;	             
		}// END OF SWITCH 
	} while(option!=4); // LOOP WILL TERMINATED IF USER ENTER OPTION 4
}  // END OF MAIN

    // Insertq() : TO INSTERT AN ITEM TO QUEUE

void insertq(int item)
{
	int temp;
	temp=(TAIL+1) % SIZE;   
     // CHECKING IS QUEUE FULL
	if(temp==HEAD)
	{
		printf("QUEUE IS FULL\n");
	}
	else
	{
		TAIL=temp;
		Q[TAIL]=item;
		printf("INSERT SUCCESS\n");
	}
	
} //END OF insertq

  // deleteq() : TO DELETE AN ITEM FROM QUEUE

int deleteq(void)
{
	int item;
	 // CHECKING IS QUEUE EMPTY
	if( HEAD != TAIL) // QUEUE IS NOT EMPTY
	{
		HEAD=(HEAD+1) % SIZE;
		item=Q[HEAD];
		
		printf("",item);
		return item; // RETURNING THE DELETED ITEM
	}
	else 
		printf("QUEUE IS EMPTY \n");  
	return 0;
}// END OF deletq

// 'search()' : TO SEARCH AN ITEM IN QUEUE

int search(int item)
{
    // head & tail IS USED AS A COPY OF 'HEAD' and 'TAIL'
	for( int head = (HEAD+1)%SIZE, tail = TAIL ; head<=tail ; head = (head+1)%SIZE )
	{
		if(Q[head]==item)
		{
			return 1; // IF ITEM FOUND 
		}
		
	}
	return 0; // IS ITEM NOT FOUND
}//END OF search














