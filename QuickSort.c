#include<stdio.h>
#include<conio.h>

void swap(int a,int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}


int partition(int *a,int start,int end)
{
	int pivot = a[end];
	int pIndex = start;
	int i,temp;

	for(i=start;i<end;i++)
	{
		if(a[i]<=pivot)
		{
			//swap(a[i],a[pIndex]);
			temp = a[i];
			a[i] = a[pIndex];
			a[pIndex]= temp;
			pIndex++;
		}
	}

	//swap(a[pIndex],a[end]);

	temp = a[pIndex];
	a[pIndex] = a[end];
	a[end] = temp;

	return(pIndex);
}

void quicksort(int *a,int start,int end)
{
	int pIndex;
	if(start<end)
	{
		pIndex = partition(a,start,end);
		quicksort(a,start,pIndex-1);
		quicksort(a,pIndex+1,end);
	}
}

void main()
{
	int n,a[10],i;
	clrscr();
	printf("Enter n :");
	scanf("%d",&n);

	printf("Enter elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	quicksort(a,0,n-1);

	printf("Sorted elements:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	getch();
}

