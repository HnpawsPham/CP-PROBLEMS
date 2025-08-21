#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc;

ll ppow(ll a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b/ 2);
    if(b & 1) return 1LL * half * half * a;
    return 1LL * half * half;
}

ll sol(){
    int n;
    cin>>n;
    int i = 0;
    ll res = 0;
    while(n > 0){
        int x = n % 3;
        if(x > 0){
            if(!i) res += 1LL * x * 3;
            else res += 1LL * x * (ppow(3, i + 1) + 1LL * i * ppow(3, i - 1)); 
        }
        n /= 3;
        i++;
    }
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