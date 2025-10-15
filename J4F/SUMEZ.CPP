#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    ll p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];

    while(m--){
        int l, r;
        cin>>l>>r;
        cout<<p[r] - p[l - 1]<<el;
    }
    return 0;
}

// 3 2
// -1 -1 1
// 2 3
// 1 1

// 2 3
// -6 -5
// 1 1
// 1 2
// 2 2

// 4 4
// 17 -17 -21 6
// 1 3
// 4 4
// 4 4
// 2 4
