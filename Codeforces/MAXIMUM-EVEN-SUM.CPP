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

int tc;
ll a, b;

vll div(ll x){
    vll res;
    for(int i = 1; i <= sqrt(x); i++)
        if(x % i == 0){
            res.push_back(i);
            if(i != x / i) res.push_back(x / i);
        }
    return res;
}

ll sol(){
    cin>>a>>b;  

    ll res = -1;
    if((a + b) % 2 == 0) res = a + b;
    
    if(a % 2 && b % 2) res = max(res, a * b + 1);
    else if(b % 2 == 0 && (b % 4 == 0 || a % 2 == 0)) 
        res = max(res, a * b / 2 + 2);
    return res;
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