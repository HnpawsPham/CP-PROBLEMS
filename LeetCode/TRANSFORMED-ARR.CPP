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

    vi res(n);
    for(int i = 0; i < n; i++){
        if(a[i] == 0) res[i] = a[i];
        else res[i] = a[((i + a[i]) % n + n) % n];
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 4
// 3 -2 1 1