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

ll digitcnt(ll n){
    ll cnt = 0;
    for(int i = 0; ; i++){
        ll x = ppow(10, i);
        if(x > n) {
            cnt = 9LL * cnt + (n - x + 1) * i;
            break;
        }
        cnt += ppow(10, i) * (i + 1);
    }
    return cnt;
}

ll digitsum(ll n){
    ll sum = 0, x = 1;
    while(x <= n){
        ll left = n / x / 10;
        ll d = (n / x) % 10;
        ll r = n % x;

        sum += left * 45 * x;
        sum += 1LL * d * (d - 1) / 2 * x;
        sum += 1LL * d * (r + 1);
        x *= 10;
    }
    return sum;
}

ll sol(){
    ll n;
    cin>>n;

    ll l = 1, r = 1e15, mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(digitcnt(mid) >= n) r = mid - 1;
        else l = mid + 1;
    }

    ll res = digitsum(l - 1);
    ll left = digitcnt(l - 1);

    string s = to_string(l);
    for(int i = 0; i < n - left; i++)
        res += (s[i] - '0');
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