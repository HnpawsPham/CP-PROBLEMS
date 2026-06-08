#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<int> res;
    for(const int& x: a)
        if(x < k) res.push_back(x);
    for(const int& x : a)
        if(x == k) res.push_back(x);
    for(const int& x : a) 
        if(x > k) res.push_back(x);

    for(int x : res) cout<<x<<" ";
    return 0;
}