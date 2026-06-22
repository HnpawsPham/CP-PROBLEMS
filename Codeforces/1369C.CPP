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

ll sol(){
    int n, m;
    cin>>n>>m;
    int a[n], b[m];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    sort(a, a + n);
    sort(b, b + m);
    ll res = 0;
    int r = n - 1, l = 0, i = 0;

    for(; i < m && b[i] == 1; i++)
        res += 2 * a[r--];
    
    for(int j = m - 1; j >= i; j--){
        res += (a[r--] + a[l++]);
        l += (b[j] - 2);
    }
    return res;
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
        cout<<sol()<<el;
    }
    return 0;
}