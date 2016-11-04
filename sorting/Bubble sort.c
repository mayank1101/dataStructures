/*Bubble Sort*/
#include<stdio.h>
#define max 1000
void bubble(int *,int);
int main()
{
	int arr[max],i,num;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	scanf("%d",&(*(arr+i)));
	bubble(arr,num);
	return 0;
}

void bubble(int *p,int n)
{
	int i,j,temp;
	int exchangs;
	for(i=0;i<n-1;i++)
	{
		exchangs=0;
		for(j=0;j<n-1-i;j++)
		{
			if(*(p+j)>*(p+j+1))
			{
				temp=*(p+j);
				*(p+j)=*(p+(j+1));
				*(p+(j+1))=temp;
			    exchangs++;
			}
		}
		if(exchangs==0)
		break;
	}
	
	for(i=0;i<n;i++)
	printf("%d\t",*(p+i));
}

		
		
	
	
