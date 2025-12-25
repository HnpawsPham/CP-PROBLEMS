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

int tc = 1;

void sol(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt[n + 1] = {0};
    bool check[n + 1] = {0};
    for(int x : a)cnt[x]++;
 
    int mex = 0;
    vi res;
    for(int x : a){
        cnt[x]--;
        check[x] = 1;
        while(check[mex]) mex++;
        
        if(!cnt[mex]){
            res.push_back(mex);
            memset(check, 0, sizeof check);
            mex = 0;
        }
    }

    cout<<res.size()<<el;
    for(const int& x : res) cout<<x<<" ";
    return;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        sol();
        cout<<el;
    }
    return 0;
}