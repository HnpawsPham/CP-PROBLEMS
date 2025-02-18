#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define MOD 1000000007
#define pii pair<int, int>

int n, m;
ll res = -1, cnt;
const int maxn = (int)1e5 + 5;
ll a[maxn], b[maxn];
vector<pii> ans;

bool check(ll x){
    int i = 0, j = 0, t = 0;
    ll minn = LLONG_MAX;
    vector<pii> p;

    while(i < n && j < m){
        if(a[i] < x){
            if(a[i] + b[j] >= x){
                minn = min(a[i] + b[j], minn);
                p.push_back({i + 1, j + 1});
                i++;
                t++;
            }
            j++;
        }  
        else{
            minn = min(minn, a[i]);
            i++;
        }
    }

    for(; i < n; i++) minn = min(minn, a[i]);

    if(minn >= x){
        res = x;
        cnt = t;
        ans = p;
    }
    return minn >= x;
}

int main(){
    freopen(".\\txt\\WALL.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll mina = LLONG_MAX, maxb = -1;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        mina = min(mina, a[i]);
    }
    cin>>m;
    for(int i = 0;i<m;i++){
        cin>>b[i];
        maxb = max(maxb, b[i]);
    }
    
    ll l = mina, r = mina + maxb;
    while(l <= r){
        ll mid = l + (r - l)/2;

        if(check(mid)){
            l = mid + 1;
            res = mid;
        }
        else r = mid - 1;
    }
    cout<<res<<" "<<cnt<<el;
    for(pii x : ans){
        cout<<x.first<<" "<<x.second<<el;
    }

    return 0;
}