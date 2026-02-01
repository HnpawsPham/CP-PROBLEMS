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
    int minn = 1e9 + 5;
    for(int i = 0; i < n; i++) cin>>a[i];

    // int cur = min(a[0], a[n - 1]) / (n - 1);
    // if(pos != 1) cur = min(cur, minn / (pos - 1));
    // if(pos != n) cur = min(cur, minn / (n - pos));
    for(int i = 0; i < n; i++){
        if(i > 0) minn = min(minn, a[i] / i);
        if(n - i - 1 > 0) minn = min(minn, a[i] / (n - i - 1));
    }
    cout<<minn;
    return 0;
}