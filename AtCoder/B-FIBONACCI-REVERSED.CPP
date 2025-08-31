#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

ll f(ll x){
    ll res = 0;
    while(x > 0){
        res = res * 10 + (x % 10);
        x /= 10;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll fibo[10];
    cin>>fibo[0]>>fibo[1];
    for(int i = 2; i < 10; i++)
        fibo[i] = f(1LL * fibo[i - 1] + fibo[i - 2]);

    cout<<fibo[9];
    return 0;
}