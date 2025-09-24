#include<stdio.h>
void read_array(int,int[]);
void search(int,int[],int);
void main()
{
	int a,key;
	printf(" Enter the no of elements: ");
	scanf("%d",&a);
	int arr[10];
	read_array(a,arr);
	printf("enter the key to be search :");
	scanf("%d",&key);
	search(key,arr,a);	
}
void read_array(int n,int arr[])
{
	int i;
	printf("enter the element");
  	for(i=0;i<n;i++)
  	{
  		scanf("%d",&arr[i]);
  	}
}
void search(int n,int arr[],int key)
{
	int begin, mid,end;
	begin=0;
	end=1;
	while(arr[mid]!=key&& end> begin)
	{
		mid=(end-begin)/2;
		if(arr[mid]>key)
		{
			begin=mid++;
		}
		else
		{
			end=mid--;
		}
		if (arr[mid]==key)
		{
			printf("key found at the position: %d\n",mid);
		}
		else
		{
			printf("key is not found ");
		}
	}
}
			
