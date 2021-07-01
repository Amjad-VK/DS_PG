#include<stdio.h>
void main()
{
int a[]={3,4,5,6,8};      // array a declaration     
int b[]={5,6,7,8,9,10};  // array b declaration  
int c[20];                // array c declaration    
int i,j,k;     // declaration of array operating variables
printf("First Array:");  // print first array
for(i=0;i<5;i++)
{
printf("%d\t",a[i]);
} 
printf("\nSecond Array:"); // print second array
for(j=0;j<6;j++)
{
printf("%d\t",b[j]);
}                 
void merge(int a[],int,int b[],int,int c[]); //function prototype
merge(a,5,b,6,c);  // function call
printf("\n Merged Array:");             
for(i=0;i<(5+6);i++)
{
printf("%d\n",c[i]);  // printing merged array elements
}
return;
} // end of main function


// function to merge two arrays
void merge(int a[],int m,int b[],int n,int c[])  // function definition
{
int i=0,j=0,k=0;
while(i<m && j<m) 
{
if(a[i]<b[j]) // comparing values of array a and array b
{ 
c[k]=a[i];   // store an item from array a and array b
k++; i++;   // k is incremented as an item is added to array c and i is incremented as one item is moved from array a   
}
else
{
c[k]=b[j];  // store an item from array b to array c  
k++;j++;   // k is incremented as an item is added to array c and i is incremented as one item is moved from array b         
}
} 

//copying if any element is left in array a 
while(i<m)
{
c[k]=a[i];
i++;
k++;
}
//copying if any element is left in array b
while(j<n)
{
c[k]=b[j];
k++;
j++;
}
}
