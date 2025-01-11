#include <bits/stdc++.h>

/*
    Bubble Sort Algorithm
    TC - O(n^2)
    SC = O(1)

    @author = vasubhrdwj   
*/

using namespace std;

void bubbleSort(vector<int>& arr);

int main(){
    vector<int> arr = {1,4,7,2,4,9,11,3,42,7,6,8,55};
    int n = arr.size();

    cout<<"Before Bubble Sort: \n";
    for(int elem : arr) cout<<elem<<" ";
    cout<<"\n\n";
    bubbleSort(arr);
    cout<<"After Bubble Sort: \n";
    for(int elem : arr) cout<<elem<<" "; 
}

void bubbleSort(vector<int>& arr){
    int n = arr.size();

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                arr[j] = arr[j] ^ arr[j+1];
                arr[j+1] = arr[j] ^ arr[j+1];
                arr[j] = arr[j] ^ arr[j+1];
            }
        }
    }

}