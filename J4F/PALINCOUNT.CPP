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

ll A(int n, int k){
    ll mul = 1;
    for(int i = n - k + 1; i <= n; i++)
        mul *= i;
    return mul;
}

ll sol(){
    ll n, m;
    cin>>n>>m;

    ll res = 0;
    if(n >= 3) res += A(n, 3); //aaa
    if(m >= 3) res += A(m, 3); //bbb

    if(n > 0 && m > 1) //bab
        res += n * m * (m - 1);
    if(m > 0 && n > 1) //aba
        res += n * (n - 1) * m;
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