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

const int MOD = 1e9 + 7;

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

    int minn = INT_MAX, cnt = 0;
    for(int x : a){
        if(x < minn){
            minn = x;
            cnt = 1;
        }
        else if(x == minn) cnt++;
    }
    if(a[0] != minn || cnt > 1) return cout<<0, 0;

    int res = 1;
    for(int i = 2; i < n; i++)
        res = res * i % MOD;
    cout<<res;
    return 0;
}

// 3
// 1 2 3

// 6
// 3 3 3 4 4 4