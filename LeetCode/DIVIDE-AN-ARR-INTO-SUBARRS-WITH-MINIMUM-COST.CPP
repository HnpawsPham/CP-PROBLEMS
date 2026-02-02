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

    int minn = 205;
    for(int i = 1; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
                minn = min(minn, a[0] + a[i] + a[j]);
    cout<<minn;
    return 0;
}

// 3
// 5 4 3

// 4
// 10 3 1 1