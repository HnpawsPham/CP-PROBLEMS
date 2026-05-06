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
    int n;
    cin>>n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int j = 0; j < n; j++) cin>>b[j];
    sort(a, a + n);
    sort(b, b + n, greater<int>());

    ll sum = 0;
    for(int i = 0; i < n; i++)
        sum += max(a[i], b[i]);
    return sum;
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