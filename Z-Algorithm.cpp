#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> ZAlgorithm(string input){
    int n = input.size();
    vector<int> Z(n);
    int left = 0, right = 0;

    for(int k=1;k<n;k++){
        if(k > right){
            left = right = k;

            while(right<n && input[right] == input[right - left]) right++;
            Z[k] = right - left;
            right--;
        } 
        else{
            int k1 = k - left;
            
            if(Z[k1] < right - k+1)
                Z[k] = Z[k1];
            else{
                left = k;
                while(right<n && input[right] == input[right - left]) right++;
                Z[k] = right - left;
                right--;
            }
        }
    }

    return Z;
}

int main()
{
    string s = "abaxabab";

    vector<int> Z = ZAlgorithm(s);

    for(auto& elem : Z) cout<<elem<<" ";


}
