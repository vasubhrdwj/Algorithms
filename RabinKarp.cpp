#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> rabin_karp(string const& src, string const& txt){
    const int p = 31; //53 for all cases
    const int m = 1e9 + 9;
    int s = src.size(), t= txt.size();
    if(s>t) return {};

    vector<long long> p_pow(t);
    p_pow[0] = 1;
    for(int i=1;i<t;i++){
        p_pow[i] = (p_pow[i-1] * p) % m;
    }

    vector<long long> hVal(t+1, 0);

    for(int i=0;i<t;i++){
        hVal[i+1] = (hVal[i] + (txt[i]-'a'+1)*p_pow[i]) % m;
    }
    long long sHash = 0;
    for(int i=0;i<s;i++){
        sHash = (sHash + (src[i] - 'a' + 1)*p_pow[i])%m;
    }

    vector<int> occurences;
    for(int i=0;(i+s-1)<t;i++){
        long long currHash = (hVal[i+s] +m - hVal[i])%m;
        if(currHash == sHash * p_pow[i]%m)
            occurences.push_back(i);
    }

    return occurences;



}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    string a = "abaxczhsgdabcabcbghabc";
    string b = "abc";
    vector<int> ans = rabin_karp(b,a);
    for(auto& el : ans) cout<<el<<" ";
}
