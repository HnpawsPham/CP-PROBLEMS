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

int tc = 1;

string sol(){
    int n, m;
    cin>>n>>m;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    if(n > m) return "NO";

    ll sum = accumulate(a, a + n, 0LL);
    if(1LL * n + sum - 1LL * *min_element(a, a + n) + 1LL * *max_element(a, a + n) <= m)
        return "YES";
    return "NO";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}