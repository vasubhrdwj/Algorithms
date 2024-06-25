#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> computeLps(string s){
    int n = s.size();
    vector<int> lps(n);

    int j = 0;
    for(int i=1;i<n;){
        if(s[i] == s[j]){
            lps[i] = j+1;
            i++;
            j++;
        }
        else{ //Not Equal
            if(j == 0){
                lps[i] = 0;
                i++;
            }
            else{
                j = lps[j-1];
            }
        }   
    }

    return lps;
}

vector<int> KMP(string s, string pat){
    int n = s.size(), p = pat.size();
    vector<int> lps = computeLps(pat);
    int i=0, j=0;
    vector<int> occurences;

    while(i<n){
        if(s[i] == pat[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else i++;
        }

        if(j == p){
            occurences.push_back(i-j);
            j=0;
        }
    }

    return occurences;
}


int main()
{
    string s = "abcxabcdabcdabcy";
    string pattern = "abcdabcy";
    // string s = "sadbutsad", pattern = "sad";
    // string s = "leetcode", pattern = "eetc";
    vector<int> ans = KMP(s, pattern);

    for(int val : ans)cout<<val<<endl;
    
}
