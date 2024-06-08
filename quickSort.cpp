#include <bits/stdc++.h>

/*
    Quick Sort Algorithm

    @author = vasubhrdwj   
*/

using namespace std;

int partition(vector<int>& arr,int low, int high);
void quickSort(vector<int>& arr,int low,int high);

int main(){
    vector<int> arr = {1,4,7,2,4,9,11,3,42,7,6,8,55};
    int n = arr.size();

    cout<<"Before Quick Sort: \n";
    for(int elem : arr) cout<<elem<<" ";
    cout<<"\n\n";
    quickSort(arr, 0, n-1);
    cout<<"After Quick Sort: \n";
    for(int elem : arr) cout<<elem<<" "; 
}

int partition(vector<int>& arr,int low, int high){
    int pivot = arr[low];

    // i -> pointer to check the elements that are greater than pivot
    int i = low;
    // j ->pointer to point to the elements smaller than pivot
    int j = high;
    // Whenever i and j stop, we can swap them to put them in correct place
    while(i < j){
        while(i < high && arr[i] <= pivot) i++;

        while(j > low && arr[j] > pivot) j--;

        if(i < j) swap(arr[i], arr[j]);

    }

    swap(arr[low], arr[j]);

    return j;
}

void quickSort(vector<int>& arr,int low,int high){
    if(low >= high) return;

    int partitionIndex = partition(arr,low,high);
    quickSort(arr,low,partitionIndex-1);
    quickSort(arr,partitionIndex+1,high);

    return;
}