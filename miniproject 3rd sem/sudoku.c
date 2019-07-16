#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void row(int a[9][9],int y,int z);
void col(int a[9][9],int y,int z);
void fun(int a[9][9],int y,int z);
void bum(int check[]);
int box;
int main()
{
 int a[9][9];
 int i,j;
 printf("enter elements of sudoku(1-9):\n");
 for(i=0;i<9;i++)
 {
  for(j=0;j<9;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }
 row(a,9,9);
 col(a,9,9);
 box=0;
 fun(a,0,0);
 box++;
 fun(a,0,3);
 box++;
 fun(a,0,6);
 box++;
 fun(a,3,0);
 box++;
 fun(a,3,3);
 box++;
 fun(a,3,6);
 box++;
 fun(a,6,0);
 box++;
 fun(a,6,3);
 box++;
 fun(a,6,6);
 box++;
 return 0;
}
void fun(int a[9][9],int y,int z)
{
 int i,j,c,k;
 int check[10];
 i=y;
 j=z;
 c=0;
 for(k=0;k<9;k++)
 {
   check[k]=a[i][j];
   j++;
   c++;
   if(c==3)
   {
     j=z;
     i++;
     c=0;
   }
 }
 bum(check);
}
void bum(int check[10])
{
	for(int i=0;i<9;i++)
	{
         for(int j=i+1;j<9;j++)
	 {
		 if(check[i]==check[j])
		 {
	          printf("wrong sudoku: in box %d\n",box);
		  break;
		 }
	 }
	}
}
void row(int a[9][9],int y,int z)
{
  int i,j,k;
  for(i=0;i<9;i++)
  {
   for(j=0;j<9;j++)
   {
    for(k=j+1;k<z;k++)
    {
     if(a[i][j]==a[i][k])
     {
	printf("error in %d row\n",i);
	break;
     }
    }
   }
  }
}
void col(int a[9][9],int y,int z)
{
  int i,j,k;
  for(j=0;j<9;j++)
  {
   for(i=0;i<9;i++)
   {
    for(k=i+1;k<y;k++)
    {
     if(a[i][j]==a[k][j])
     {
      printf("error in %d col:\n",j);
      break;
     }
    }
   }
  }
}
