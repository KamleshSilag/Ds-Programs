#include<stdio.h>
#include<conio.h>
struct student
{
	int rno,marks;
};
void accept(int n, struct student *ptr)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nEnter rno  and marks:\n");
		scanf("%d%d",&ptr->rno,&ptr->marks);
		ptr++;
	}

}
void display(struct student *ptr,int n)
{
	int i;
	printf("\nSorted List As per Roll no :");
	for(i=0;i<n;i++)
	{
		printf("\nRno : %d Marks: %d ",ptr->rno,ptr->marks);
		ptr++;
	}
}
void countSort(struct student s[100], int n, int exp)
{
    struct student output[100]; // output array
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
	count[ (s[i].rno/exp)%10 ]++;
    
    for (i = 1; i < 10; i++)
	count[i] += count[i - 1];
    
    for (i = n - 1; i >= 0; i--)
    {
	output[count[ (s[i].rno/exp)%10 ] - 1] = s[i];
	count[ (s[i].rno/exp)%10 ]--;
    }
    
    for (i = 0; i < n; i++)
	s[i] = output[i];
}

int getMax(struct student s[100], int n)
{
    int mx = s[0].rno;
    int i;
    for (i = 1; i < n; i++)
	if (s[i].rno > mx)
	    mx = s[i].rno;
    return mx;
}

void radixsort(struct student s[100], int n)
{

    int m = getMax(s, n);
    int exp;
    for (exp = 1; m/exp > 0; exp *= 10)
	countSort(s, n, exp);
}

void main()
{
	struct student s[100];
	int n;
	clrscr();
	printf("Enter how many student data to sort :\n");
	scanf("%d",&n);
	accept(n,s);
	radixsort(s,n);
	display(s,n);
	getch();
}