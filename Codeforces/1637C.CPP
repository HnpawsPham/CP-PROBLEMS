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
    int a[n];
    bool has1 = 1;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(i > 0 && i < n - 1 && a[i] > 1) has1 = 0; 
    }
    if(has1 || (n == 3 && a[1] % 2)) return -1;

    ll res = 0;
    for(int i = 1; i < n - 1; i++)
        res += (a[i] + 1) / 2;
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