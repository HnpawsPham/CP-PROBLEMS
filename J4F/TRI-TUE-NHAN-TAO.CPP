#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    // freopen("TTNT.INP", "r", stdin);
    // freopen("TTNT.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    

    int a, b, t;
    cin>>a>>b>>t;
    if((t - 1) % (a + b) + 1 > a) cout<<0;
    else cout<<1;
    return 0;
}

// 5
// 7
// 5

// 5
// 7
// 20