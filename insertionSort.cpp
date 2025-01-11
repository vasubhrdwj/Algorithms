#include <bits/stdc++.h>

/*
    Insertion Sort Algorithm
    TC - O(n^2)
    SC = O(1)

    @author = vasubhrdwj   
*/

using namespace std;

void insertionSort(vector<int>& arr);

int main(){
    vector<int> arr = {1,4,7,2,4,9,11,3,42,7,6,8,55};
    int n = arr.size();

    cout<<"Before Insertion Sort: \n";
    for(int elem : arr) cout<<elem<<" ";
    cout<<"\n\n";
    insertionSort (arr);
    cout<<"After Insertion Sort: \n";
    for(int elem : arr) cout<<elem<<" "; 
}

void insertionSort(vector<int>& arr){
    int n = arr.size();

    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }

}