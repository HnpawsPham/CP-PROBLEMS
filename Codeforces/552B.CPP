#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

ll ppow(int a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);

    if(b & 1) return 1LL * half * half * a;
    return 1LL * half * half;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    // for(ll i = 0; ;i++){
    //     ll x = ppow(10, i);
    //     if(x > n) {
    //         ll lim = x / 100 * 9;
    //         ll cnt = 0;
    //         ll j = i - 1, tmp = lim;
    //         while(j > 0){
    //             cnt += 1LL * j * tmp;
    //             j--;
    //             tmp/=10;
    //         }
    //         return cout<<cnt + 1LL * (n - x / 10 + 1) * i, 0;
    //     }
    // }
    ll cnt = 0;
    for(int i = 0; ; i++){
        ll x = ppow(10, i);
        if(x > n) return cout<<9LL * cnt + (n - x + 1) * i, 0;
        cnt += ppow(10, i) * (i + 1);
    }
    return 0;
}