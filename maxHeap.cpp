#include <bits/stdc++.h>

/*
    Max Heap Implementation

    @author = vasubhrdwj   
*/

using namespace std;

void MaxHeapify(vector<int>& heap, int i,int n);
void BuildMaxHeap(vector<int>& heap,int n);
void HeapSort(vector<int>& heap,int n);

int main(){
    vector<int> arr = {1,4,7,2,4,9,11,3,42,7};

    cout<<"Before HeapSort: \n";
    for(int elem : arr) cout<<elem<<" ";
    cout<<"\n\n";
    HeapSort(arr,arr.size());
    cout<<"After HeapSort: \n";
    for(int elem : arr) cout<<elem<<" "; 
}

void MaxHeapify(vector<int>& heap, int i,int n){
    int leftChild = 2*i + 1;
    int rightChild = 2*i + 2;
    int largest = i;

    if(leftChild < n && heap[leftChild] > heap[largest])
        largest = leftChild;
    if(rightChild < n && heap[rightChild] > heap[largest])
        largest = rightChild;
    if(largest != i){
        swap(heap[largest], heap[i]);
        MaxHeapify(heap,largest,n);
    }
}

void BuildMaxHeap(vector<int>& heap,int n){
    for(int i = (n/2)-1; i>=0;i--){
        MaxHeapify(heap,i,n);
    }
}

void HeapSort(vector<int>& heap, int n){
    BuildMaxHeap(heap,n);
    for(int i=n-1;i>0;i--){
        swap(heap[0],heap[i]);
        n--;
        MaxHeapify(heap,0,n);
    }
}
