#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, node = 1;
ll x;
const int maxn = 1e5 + 5;
ll a[maxn];
int t[4 * maxn];

void update(int i, int val){
    i += n;
    t[i] = max(t[i], val);

    while(i > 0){
        i /= 2;
        t[i] = max(t[2 * i], t[2 * i + 1]);
    }
    return;
}

int query(int l, int r){
    l += n;
    r += n;

    int res = 0;
    while(l <= r){
        if(l % 2){
            res = max(res, t[l]);
            l++;
        }
        if(r % 2 == 0){
            res = max(res, t[r]);
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return res;
}

void sub3(){
    vector<int> dp(n, 1);
    int res = 0;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++)
            if(abs(a[i] - a[j]) <= x)
                dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }

    cout<<res;
    return;
}

int main(){
    // freopen("INDEX.INP", "r", stdin);
    // freopen("INDEX.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>x;
    for(int i = 0; i < n; i++) cin>>a[i];

    if(n <= 5000){
        sub3();
        return 0;
    }

    vector<ll> b;
    for(int i = 0; i < n; i++){
        b.push_back(a[i]);
        b.push_back(a[i] - x);
        b.push_back(a[i] + x);
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    map<ll, int> mp;
    int m = b.size();

    for(int i = 0; i < m; i++)
        mp[b[i]] = i + 1;

    int res = 0;
    for(int i = 0; i < n; i++){
        int l = lower_bound(b.begin(), b.end(), a[i] - x) - b.begin() + 1;
        int r = lower_bound(b.begin(), b.end(), a[i] + x) - b.begin();

        int good = query(l, r);
        update(mp[a[i]], good + 1);

        res = max(res, good + 1);
    }
    cout<<res;
    return 0;
}