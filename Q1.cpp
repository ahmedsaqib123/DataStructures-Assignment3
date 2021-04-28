#include<iostream>
#include<stdlib.h>
#include<ctime>
#define N 100
using namespace std;

int partition(int a[N], int start, int end)
{
	int pivot, index, i;
	index = start;
	pivot = end;
	for(i=start; i < end; i++)
	{
		if(a[i] < a[pivot])
		{
		swap(a[i], a[index]);
		index++;
		}
	}
	swap(a[pivot], a[index]);
 
	return index;
}
 
int random_pivot(int a[N], int start, int end)
{
	int pvt, n, temp;
	n = rand();
	pvt = start + n%(end-start+1);
	swap(a[end], a[pvt]);
 
	return partition(a, start, end);
}

void insertion_sort(int a[N])
{
	int i,j,key;
	for(i=1;i<N;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			
		a[j+1]=a[j];
		j=j-1;
		}
		a[j+1]=key;
	}	
}

int quicksort_random(int a[N], int start, int end)
{
	int pindex;
	if(start < end)
	{
		pindex = random_pivot(a, start, end);
		if (pindex<15)
		{
			insertion_sort(a);  
		}
		quicksort_random(a, start, pindex-1);
		quicksort_random(a, pindex+1, end);
	}
	return 0;
}

void print_arr(int arr[N])
{
	for(int i=0; i<N; i++)
	{
		if(i==36 || i==72)		//just to make the output screen more clear and understandable. 
		{
			cout<<endl;
		}
		cout<<" "<<arr[i];
	}
}
int quicksort_median(int arr[N],int start,int end)
{
	int median;
	
	insertion_sort(arr);
	if (N % 2 != 0) 
	{
    	median=arr[N/2]; 
	}
	else
	{
		median=(arr[(N-1)/2] + arr[N/2])/2; 
    }
    
	if(start>=end)
    return 0;
    
    int mid=(start+end)/2;
    int pivot=arr[mid];
    int i=start,j=end;
    int temp;
    while(i<j)
    {
        if(arr[i]>=pivot && arr[j]<=pivot)
        {
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
            i++;
            j--;
        }
        else
        {
            i++;
        }
    }
    
	if (mid<15)
	{
		insertion_sort(arr);  
	}
    quicksort_median(arr,start,mid);
    quicksort_median(arr,mid+1,end);

} 

int quicksort_middle(int arr[N],int start,int end)
{
    if(start>=end)
    return 0;

    int mid=(start+end)/2;
    int pivot=arr[mid];
    int i=start,j=end;
    int temp;
    while(i<j)
    {
        if(arr[i]>=pivot && arr[j]<=pivot)
        {
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
            i++;
            j--;
        }
        else
        {
            i++;
        }
    }
	if (mid<6)
	{
		insertion_sort(arr);  
	}
    quicksort_middle(arr,start,mid);
    quicksort_middle(arr,mid+1,end);
}


int quicksort_start(int arr[N],int start,int end)
{
	int pivot;
	if(start<end)
	{
		insertion_sort(arr);
	}
	else
	{
		int j=start,i=end+1;
		pivot=end+1;
		do
		{
			while(arr[i]<arr[pivot])
			{
				i++;
			}
			while(arr[j]>arr[pivot])
			{
				j--;
			}
			swap(arr[i],arr[j]);
		}while(arr[i]!=arr[j]);
		quicksort_start(arr,end,pivot);
		quicksort_start(arr,pivot,start);
	}
}



int main()
{	
	int arr[N],num;
	clock_t t,t1,t2,t3;
	srand(time(0));
	
	for(int i = 0; i < N; i++)
	{
		num=rand()%100+1;
		arr[i]=num;
	}
	cout<<"Before Sorting: "<<endl;
    print_arr(arr);
    cout<<endl<<endl;
    
    cout<<"After Sorting (Middle Pivot): "<<endl;
    t=clock();
    quicksort_middle(arr,0,N-1);
    print_arr(arr); 
    cout<<endl;
    t=clock()-t;
    double time=((double) t)/CLOCKS_PER_SEC;
    cout<<"Time: "<<time<<endl;
    cout<<endl<<endl;
    
    cout<<"After Sorting (Median Pivot): "<<endl;
    t1=clock();
    quicksort_median(arr,0,N-1);
    print_arr(arr);   
    cout<<endl;
    t1=clock()-t;
    double time1=((double) t1)/CLOCKS_PER_SEC;
    cout<<"Time: "<<time1<<endl;

    
	quicksort_random(arr, 0, N-1);
	cout<<endl<<endl;
	t2=clock();
	cout<<"After Sorting (Random Pivot): "<<endl;
    print_arr(arr);
    cout<<endl;
    t2=clock()-t;
    double time2=((double) t2)/CLOCKS_PER_SEC;
    cout<<"Time: "<<time2<<endl;
    cout<<endl<<endl;
    
    cout<<"After Sorting (First Pivot): "<<endl;
    t3=clock();
    quicksort_start(arr,0,N-1);
    print_arr(arr);   
    cout<<endl;
    t3=clock()-t;
    double time3=double (t3)/CLOCKS_PER_SEC;
    cout<<"Time: "<<time3<<endl;
    cout<<endl<<endl;
}

