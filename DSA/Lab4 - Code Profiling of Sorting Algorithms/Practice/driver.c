#include<stdio.h>
#include<stdlib.h>

void readData(char name[],int *a,int size)
{
	FILE * x;
	int i;
	x=fopen(name,"r+");
	for(i=0;i<=size-1;i++)
	{
		fscanf(x,"%d",(a+i));
	}
	fclose(x);
}
void printData(int *a,int size)
{
	FILE *x;
	int i;
	x=fopen("output.txt","w+")
;	for(i=0;i<=size-1;i++)
	{
		fprintf(x,"%d\n",*(a+i));
	}
	fclose(x);
}

void insertion_sort_lot(int *p,int size)
{	
	int i,k;
	for(i=1;i<=size-1;i++)
	{	
		int x=*(p+i);
		for(k=i-1;k>=0;k--)
		{
			if(*(p+k)>=x)
				{
					*(p+k+1)=*(p+k);
					//*(p->park_id+k+1)=*(p->park_id+k);
					//strcpy((p->c+k+1)->name,(p->c+k)->name);
				}
			else 
				break;
		}
		*(p+k+1)=x;
		//*(p->park_id+k+1)=y;
		//strcpy((p->c+k+1)->name,n);
	}			
}
void quicksort(int *x,int first,int last){
    int pivot,j,temp,i;

     if(first<last)
     {
         pivot=first;
         i=first;
         j=last;
         while(i<j)
         {
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j)
             {
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }
         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}

void merge(int * p,int a,int mid,int b)
{
	int n1=mid-a+1;
	int n2=b-mid;
	int A[n1],B[n2];int i,j,k;
	for(i=0;i<=n1-1;i++)
	{			
		A[i]=*(p+a+i);
	}
	for(i=0;i<=n2-1;i++)
	{			
		B[i]=*(p+mid+1+i);
	}
	i=0;j=0;k=a;
	while(k<=b&&i<=n1-1&&j<=n2-1)
	{
		if(A[i]<=B[j])
		{
			*(p+k)=A[i];
			i++;k++;
		}
		else 
		{	
			*(p+k)=B[j];
			j++;k++;
		}
	}
	while(i<=n1-1)
		{
			*(p+k)=A[i];i++;k++;
		}
	while(j<=n2-1)
		{
			*(p+k)=B[j];j++;k++;
		}
}
void mergesort(int * p,int a,int b)
{
	if(a<b)
	{
		int mid=(a+b)/2;
		mergesort(p,a,mid);
		mergesort(p,mid+1,b);
		merge(p,a,mid,b);
	}
}	
int main(int argc, char *argv[])
{
	int *a;
	int size=atoi(argv[1]);
	//int size= 1000;	
	printf("Size is: %d\n",size);	
	a=(int *)malloc(sizeof(int)*size);
	char name[20]="input.txt";
	printf("Taking Input from Input.txt......\n");
	readData(name,a,size);
	printf("Input Taken\n");
	//*(a)=4;
	//*(a+1)=9;
	//*(a+2)=1;
	//*(a+3)=3;
	//mergesort(a,0,size-1);
	insertion_sort_lot(a,size);	
	//printf("%d %d %d %d",*(a),*(a+1),*(a+2),*(a+3));
	//quicksort(a,0,size-1);
	printf("Writing output to Output.txt......\n");
	printData(a,size);
	printf("Completed!\n");
	return 0;
}
	
