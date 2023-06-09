#include<iostream>
using namespace std;
void heapify(int arr[],int n,int rootIndex){
    int largest =rootIndex;
    int leftchild=2*rootIndex+1;
    int rightchild=2*rootIndex+2;

    if (leftchild<n && arr[leftchild]>arr[largest])
        largest=leftchild;
    if (rightchild<n && arr[rightchild]>arr[largest])
        largest=rightchild;
    if (largest != rootIndex){
        swap(arr[rootIndex] , arr[largest]);   
    }
}
void heapsort(int arr[],int n){
    for (int i =n/2-1;i>=0;i--)
    heapify(arr,n,i);

    for (int i =n-1; i>=0;i--){
        swap(arr[0],arr[i]);

        heapify(arr,i,0);
    }
}

void printArray(int arr[],int n){

    for (int i=0;i<n; ++i)
    cout<<arr[i]<<" ";
    cout<<"\n";
}
int main(){

    int arr[]={17,15,11,10,5};
    int n =5;
    heapsort(arr , n);

    cout<<"sorted array:\n";
    printArray(arr,n);
    return 0;
} 