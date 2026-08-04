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

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    bool check[105];
    int l = 105, r = 0;
    for(const int& x : a){
        l = min(l, x);
        r = max(r, x);
        check[x] = 1;
    }

    vector<int> res;
    for(int i = l; i <= r; i++)
        if(!check[i]) res.push_back(i);

    for(const int& x : res)
        cout<<x<<" ";
    return 0;
}