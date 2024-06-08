#include <bits/stdc++.h>

/*
    Min Heap Implementation

    @author = vasubhrdwj   
*/

using namespace std;

void MinHeapify(vector<int>& heap, int i,int n);
void BuildMinHeap(vector<int>& heap,int n);
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
    int leftChild = 2*i;
    int rightChild = 2*i + 1;
    int smallest = i;

    if(leftChild < n && heap[leftChild] < heap[smallest])
        smallest = leftChild;
    if(rightChild < n && heap[rightChild] < heap[smallest])
        smallest = rightChild;
    if(smallest != i){
        swap(heap[smallest], heap[i]);
        MaxHeapify(heap,smallest,n);
    }
}

void BuildMinHeap(vector<int>& heap,int n){
    for(int i = n/2; i>=0;i--){
        MaxHeapify(heap,i,n);
    }
}

void HeapSort(vector<int>& heap, int n){
    BuildMinHeap(heap,n);
    for(int i=n-1;i>0;i--){
        swap(heap[0],heap[i]);
        n--;
        MaxHeapify(heap,0,n);
    }
}