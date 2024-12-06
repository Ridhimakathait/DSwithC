#include<stdio.h>


void print(int a[],int n){
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

void bubblesort(int a[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void insertionsort(int a[],int n){
    for(int i=1;i<=n-1;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && key<a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void selectionsort(int a[],int n){
    int indexofmin;
    for(int i=0;i<n-1;i++){
        indexofmin=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[indexofmin])
                indexofmin=j;
        }
        int temp=a[i];
        a[i]=a[indexofmin];
        a[indexofmin]=temp;
    }
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high); 
        quickSort(A, low, partitionIndex - 1);  // sort left subarray 
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}


void merge(int a[],int low,int high,int mid){
    int i=low;
    int j=mid+1;
    int k=low;
    int temp[high-low+1];
    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            temp[k]=a[i];
            i++;
            }
        else{
            temp[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=high){
        temp[k]=a[i];
        j++;
        k++;
    }
    for(int i=low;i<=high;i++){
        a[i]=temp[i];
        }


}

void mergesort(int a[],int low,int high){
    int mid=(low+high)/2;
    if(low<high){
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
        }
}

void main(){
    int a[6]={12,54,65,7,23,9};
    int n=6;
    print(a,n);
    //bubblesort(a,n);
    // insertionsort(a,n);
    // selectionsort(a,n);
    // quickSort(a,0,n-1);
    mergesort(a,0,n-1);
    print(a,n);

}