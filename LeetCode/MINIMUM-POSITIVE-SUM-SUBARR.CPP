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

    int n, l, r;
    cin>>n>>l>>r;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int p[n + 1];
    p[0] = 0;
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i - 1];
        
    int minn = 1e6 + 5;
    for(int len = l; len <= r; len++)
        for(int i = 1; i + len - 1 <= n; i++)
            if(p[i + len - 1] - p[i - 1] > 0)
                minn = min(minn, p[i + len - 1] - p[i - 1]);
    cout<<(minn == 1e6 + 5 ? -1 : minn);
    return 0;
}

// 4 2 3
// 3 -2 1 4