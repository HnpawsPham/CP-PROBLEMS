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
    int k, m, n;
    cin>>k>>m>>n;

    int b[m];
    for(int i = 0; i < m; i++) cin>>b[i];
    sort(b, b + m);

    pii a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i].fi>>a[i].se;
    sort(a, a + n);

    ll cnt = 0;
    int c = k, j = 0;

    for(int i = 0; i < n; i++){
        while(j < m && b[j] < a[i].fi){
            j++;
            c = k;
        }
        
        if(a[i].se <= c){
            c -= a[i].se;
            cnt += a[i].se;
        }
    }
    return cnt;
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