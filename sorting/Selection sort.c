/*Selection sort*/
#include<stdio.h>
#define max 1000
void selection(int *,int *);
int main()
{
	int i,num,arr[max];
	scanf("%d",&num);
	for(i=0;i<num;i++)
	scanf("%d",&arr[i]);
	selection(arr,&num);
	return 0;
}

void selection(int *p,int *n)
{
	int i,j,temp,min;
	for(i=0;i<(*(n)-1);i++)
	{
		min=i;
		for(j=i;j<*(n);j++)
		{
			if(*(p+min)>*(p+j))
		    min=j;
		}
		if(min!=i)
		{
			temp=*(p+i);
			*(p+i)=*(p+min);
			*(p+min)=temp;
		}
	}
	for(i=0;i<*(n);i++)
	printf("%d\t",*(p+i));
}

		
		
