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
const int maxp = 25;
ll ppow(ll a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b/ 2);
    if(b & 1) return 1LL * half * half * a;
    return 1LL * half * half;
}

ll calc(int x){
    return ppow(3, x + 1) + 1LL * x * ppow(3, x - 1);
}

ll sol(){
    int n, k;
    cin>>n>>k;

    int cnt[maxp] = {0};
    int minn = 0, tmp = n;
    for(int i = 0; tmp > 0; i++){
        cnt[i] += tmp % 3;
        minn += cnt[i];
        tmp /= 3;
    }
    if(k < minn) return -1;

    ll res = 0;
    for(int i = 0; i < maxp; i++)
        res += cnt[i] * calc(i);

    int free = k - minn;
    for(int i = maxp - 1; i >= 1 && free >= 2; i--){
        int split = min(cnt[i], free / 2);
        if(split == 0) continue;

        res -= split * ppow(3, i - 1);
        free -= split * 2;
        cnt[i] -= split;
        cnt[i - 1] += split * 3;
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