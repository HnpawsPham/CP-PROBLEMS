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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, l, r;
    cin>>n>>l>>r;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int res = 1;
    for(int i = l - 1; i < r; i++)
        res = (res * (a[i] % 10)) % 10;
    cout<<res;
    return 0;
}

// 5 2 4
// 3 2 4 6 5