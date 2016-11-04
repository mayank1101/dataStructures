/*Insertion Sort*/
#include<stdio.h>
#define max 1000
void insertion(int *, int *);
int main()
{
	int arr[max];
	int i,num;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	scanf("%d",&*(arr+i));
	insertion(arr,&num);
	return 0;
}

void insertion(int *p,int *n)
{
	int i,j,k;
	for(i=1;i<*(n);i++)   //iteration for unsorted part
	{
		k=*(p+i);     //element to be inerted in sorted part
		for(j=i-1;j>=0&&k<*(p+j);j--) //iteration to find appropriate palace for inserting k
		{                               
			*(p+(j+1))=*(p+j);
			*(p+j)=k;
		}
		
	}
	for(i=0;i<*(n);i++)
	printf("%d\t",*(p+i));
}
