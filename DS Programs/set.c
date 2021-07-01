#include<stdio.h>
#include<stdlib.h>
struct bit
{
unsigned char x:1; //reducing size to 1 bit
};
int uset []={1,2,3,4,5,6,7,8,9};
int size=9;
void main()
{
void readset(struct bit[],int n); //inputing set from user
void printset(struct bit[]);  //to give set output
void unionset(struct bit[],struct bit[],struct bit[]); //union set
void intersect(struct bit[],struct bit[],struct bit[]); //intersect set
void difference(struct bit[],struct bit[],struct bit[]); //difference set
struct bit a[9]={0},b[9]={0},c[9]={0}; 
int n;
printf("\nno of elements in a:\n");
scanf("%d",&n);
readset(a,n); 
printf(" no of elements in b:\n");
scanf("%d",&n);
readset(b,n);
printf("\nSET A=\n");
printset(a);
printf("\nSET B=\n");
printset(b);
unionset(a,b,c);
printf("\nAUB=\n");
printset(c);
intersect(a,b,c);
printf("\nAnB=\n");
printset(c);
difference(a,b,c);
printf("\nA-B=\n");
printset(c);
}

void readset(struct bit a[],int n)
{
int i,x,k;
printf("enter %d elements\n",n);
for(i=0;i<n;i++)
{
scanf("%d",&x);
for(k=0;k<size;k++)
if(uset [k]==x)
{
a[k].x=1;
break;
}}}
void printset(struct bit a[])
{
int k;
printf("{");
for(k=0;k<size;k++)
if(a[k].x!=0)
printf("%d,",uset[k]);
printf("\b}");
return;
}
void unionset(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<size;k++)
c[k].x=a[k].x||b[k].x;
return;
}
void intersect(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<size;k++)
c[k].x=a[k].x & b[k].x;
return;
}
void difference(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<size;k++)
if (a[k].x==1)
c[k].x=a[k].x^b[k].x;
return;
} 

