#include <bits/stdc++.h>

/*
    Merge Sort Algorithm

    @author = vasubhrdwj   
*/

using namespace std;

void merge(vector<int>& arr,int low, int mid, int high);

void mergeSort(vector<int>& arr,int low,int high);

int main(){
    vector<int> arr = {1,4,7,2,4,9,11,3,42,7,6,8,55};
    int n = arr.size();

    cout<<"Before Merge Sort: \n";
    for(int elem : arr) cout<<elem<<" ";
    cout<<"\n\n";
    mergeSort(arr, 0, n-1);
    cout<<"After Merge Sort: \n";
    for(int elem : arr) cout<<elem<<" "; 
}

void merge(vector<int>& arr,int low, int mid, int high){
    int left = low;
    int right = mid+1;
    vector<int> temp(high - low + 1);
    int i=0;

    while(left <= mid && right <= high){
        if(arr[left] < arr[right]){
            temp[i] = arr[left];
            i++;
            left++;
        }
        else{ //arr[right] < arr[left]
            temp[i] = arr[right];
            i++;
            right++;
        }
    }

    while(left <= mid){
        temp[i] = arr[left];
        i++;
        left++;
    }

    while(right <= high){
        temp[i] = arr[right];
        i++;
        right++;
    }

    for(int i=0;i<temp.size();i++){
        arr[low + i] = temp[i];
    }
}

void mergeSort(vector<int>& arr,int low,int high){
    if(low >= high) return;

    int mid = (low + high)>>1;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);

}