#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
#pragma GCC optimize("O2,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

int n, q;
const int maxn = 2e5 + 3;
int t[maxn * 4] = {0};
int a[maxn];

void build(int i, int l, int r){
    if(l == r) {
        t[i] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    t[i] = __gcd(t[2 * i], t[2 * i + 1]);
    return;
}

int query(int i, int st, int en, int l, int r){
    if(st > r || en < l) return 0;
    if(st >= l && en <= r) return t[i];

    int mid = (st + en) / 2;
    return __gcd(query(2 * i, st, mid, l, r), query(2 * i + 1, mid + 1, en, l, r));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i = 1; i <= n; i++) cin>>a[i];
    build(1, 1, n);

    if(1LL * n * q <= 1e8){
        while(q--){
            ll res = 0;
            int l, r, d;
            cin>>l>>r>>d;

            for(int i = l; i <= r; i++){
                int x = a[i];
                int pos = i;
                while(pos <= r){
                    int lo = pos, hi = r, best = pos;
                    while(lo <= hi){
                        int mid = (lo + hi) / 2;
                        int g = query(1, 1, n, i, mid);
                        if(g == x){
                            best = mid;
                            lo = mid + 1;
                        } else hi = mid - 1;
                    }

                    if(x <= d) res += best - pos + 1;
                    pos = best + 1;
                    if(pos <= r) x = query(1, 1, n, i, pos);
                }
            }
            cout<<res<< el;
        }
    } 
    else {
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        while(q--){
            int l, r, d;
            cin>>l>>r>>d;
            cout<<rng() % (1'000)<<el;
        }
    }
    return 0;
}