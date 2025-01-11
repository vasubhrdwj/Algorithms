#include <bits/stdc++.h>

/*
    Segment Tree

    @author = vasubhrdwj   
*/

typedef long long ll;
typedef long double ld;
#define PB push_back
#define ff first 
#define ss second

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;

const int MX = 1e5;
int a[MX], seg[4 * MX];

void build(int node, int lo, int hi){
    if(lo == hi){
        seg[node] =  a[lo];
        return;
    }
    int mid = (hi + lo)/2;

    build(2*node+1, lo, mid);
    build(2*node+2, mid+1, hi);
    seg[node] = max(seg[2*node+1], seg[2*node+2]);
    /*
    For minimum -> min(seg[2*node+1], seg[2*node+2]);
    For Sum -> seg[2*node+1] + seg[2*node+2];
    */
}

int query(int node, int lo, int hi, int l, int r){
    
    if(lo >= l && hi <= r){ // Complete overlap
        return seg[node];
    }

    if(hi < l || lo > r){ // No overlap
        return INT_MIN;
    }

    int mid = (lo + hi) / 2;
    int left = query(node*2 + 1, lo, mid, l, r);
    int right = query(node*2 + 2, mid+1, hi, l, r);

    return max(left, right);
    /*
    For minimum -> min(left, right);
    For Sum -> left + right;
    */
}

void test();

int main()
{

    int x;
    cout << "Options: (Enter the number)" << '\n';
    cout << "1. Test" << '\n' << "2.Custom input" << '\n';
    cin >> x;
    if(x == 1){
        test();
        return 0;
    }

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> a[i];

    build(0, 0, n-1);
    
    int q, l, r;
    cin >> q;
    while(q--){
        cin >> l >> r;
        cout << query(0, 0, n-1, l, r) << '\n';
    }
}

void test(){
    vi testArr = {4, 5, 1, 2, 6, 8, 3};
    for(int i=0; i<testArr.size(); i++) a[i] = testArr[i];

    build(0, 0, 6);

    for(int i=0; i<7 ; i++) cout << i << '\t';
    cout << '\n';
    for(int i=0; i<7; i++) cout << a[i] << '\t';
    cout << "\n\n\n";


    vector<pi> queries = {{0,3}, {1,4}, {0,6}, {2,2}, {4,6}};

    for(auto& q : queries){
        int l = q.ff, r = q.ss;
        cout << "For " << l << " to " << r << " :  ";
        cout << query(0, 0, 6, l, r) << "\n\n"; 
    }
}

