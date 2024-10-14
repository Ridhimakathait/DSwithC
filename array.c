#include<stdio.h>
#include<stdlib.h>
/*reverse an array*/
// void reverse(int [],int,int);
// void main(){
//     int a[20],n,temp;
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//         scanf("%d",&a[i]);
//     }
   
//     reverse(a,0,n-1);
//     for(int i=0;i<n;i++){
//         printf("%d",a[i]);
//     }

// }

// void reverse(int a[],int i,int j){
//     int temp;
//     if(i<j){
//         temp=a[i];
//         a[i]=a[j];
//         a[j]=temp;
//         reverse(a,i+1,j-1);
//     }
//     else
//         return;
// }

/*rotate by a position*/
// void main(){
//     int a[20],n,temp,k;
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//         scanf("%d",&a[i]);
//     }
//     scanf("%d",&k);
//     for(int i=0;i<k;i++){
//         temp=a[n-1];
//         for(int j=n-2;j>=0;j--){
//             a[j+1]=a[j];
//         }
//         a[0]=temp;
//     }

//     for(int i=0;i<n;i++){
//         printf("%d",a[i]);
//     }

// }



// void reverse(int a[],int i,int j) {
//         while (i<j) {
//             int temp=a[i];
//             a[i]=a[j];
//             a[j]=temp;
//             i++;
//             j--;
//         }
// }


// void rotate(int a[],int n,int k) {
//     k=k%n;
//     reverse(a,0,k-1);
//     reverse(a,k,n-1);
//     reverse(a,0,n-1);
// }

// int main() {
//     int n;
//     scanf("%d", &n);
//     int a[n];
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//     }
//     int k;
//     scanf("%d", &k);
// rotate(a, n, k);
//     for (int i = 0; i < n; i++) {
//         printf("%d ", a[i]);
//     }
//     return 0;
// }





/*union*/
// void main(){
//     int a[20],b[20],m,n,flag;

//     scanf("%d",&m);
//     for(int i=0;i<m;i++)
//         scanf("%d",&a[i]);

//     scanf("%d",&n);
//     for(int i=0;i<n;i++)
//         scanf("%d",&b[i]);

//     for(int i=0;i<m+n;i++){
//         if(i<m){
//             printf("%d",a[i]);
//         }
//         else{
//             flag=1;
//             for(int j=0;j<m;j++){
//                 if(a[j]==b[i-m]){
//                     flag=0;
//                     break;
//                 }
                
//         }
//         if(flag==1)
//             printf("%d",b[i-m]);
//         }
//     }

// }



// void main(){
//     int a[20],n,temp,k;
//     int flag=1;
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//         scanf("%d",&a[i]);
//     }
//     int diff=a[1]-a[0];
//     for(int i=1;i<n-1;i++){
//         if(a[i+1]-a[i]!=diff){
//             flag=0;
//         }
//     }

//     if(flag==1)
//         printf("AP");
//     else
//         printf("NOT AP");

// }



/*min distance between two numbers*/
// int min(int arr[], int n, int a, int b) {
//     int min_dist = n + 1;  
//     int prev_index = -1;   

    
//     for (int i = 0; i < n; i++) {
//         if (arr[i] == a || arr[i] == b) {
           
//             if (prev_index != -1 && arr[prev_index] != arr[i]) {
//                 int dist = i - prev_index;
//                 if (dist < min_dist) {
//                     min_dist = dist;
//                 }
//             }
//             prev_index = i;  
//         }
//     }
//     return (min_dist == n + 1) ? -1 : min_dist;
// }

// int main() {
//     int T;
//     scanf("%d", &T); 

//     while (T--) {
//         int n;
//         scanf("%d", &n);  

//         int arr[n];
//         for (int i = 0; i < n; i++) {
//             scanf("%d", &arr[i]);  
//         }

//         int a, b;
//         scanf("%d %d", &a, &b);  

//         int result = min(arr, n, a, b);
//         printf("%d\n", result);  
//     }

//     return 0;
// }

// void oddc(int[],int);
// void main(){
//     int a[10],T,n;
//     scanf("%d",&T);
//     while(T--){
//         scanf("%d",&n);
//         for(int i=0;i<n;i++)
//             scanf("%d",&a[i]);
//         oddc(a,n);

//     }
// }

// void oddc(int a[],int n){
//     int c;
//     for(int i=0;i<n;i++){
//         c=0;
//         for(int j=0;j<n;j++){
//             if(a[i]==a[j])
//                 c++;
//         }
//         if(c%2!=0){
//             printf("%d",a[i]);
//             break;}
        
//     }
// }

void nr(int arr[],int l){
    int count[100]={0};
    for(int i=0;i<l;i++){
        count[arr[i]]++;
    }
    int nr=0;
    for(int i=0;i<100;i++){
        if(count[i]==1){
            printf("%d",i);
            nr++;
        if(nr==3)
            return;
        }
        
    }
}

void main(){
    
    int a[7]={1,2,3,4,2,5,6};
    nr(a,7);
}