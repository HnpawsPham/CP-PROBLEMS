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

struct que{
    int l, r, id, bid;
    que(){};
    que(int l1, int r1, int id1, int bid1) : l(l1), r(r1), id(id1), bid(bid1){};

    bool operator<(const que& other) const {
        if(bid != other.bid) return bid < other.bid;
        return (bid & 1) ? (r < other.r) : (r > other.r);
    }
};

int n, k;
int m = 0, bsz = 1;
const int maxn = 5e5 + 5;
int bid[maxn];
int cnt[maxn] = {0};
ll res = 0;

void add(int val){
    if(cnt[val] == 1) res++;
    else if(cnt[val] == 2) res--;
    cnt[val]++;
}

void del(int val){
    if(cnt[val] == 2) res--;
    else if(cnt[val] == 3) res++;
    cnt[val]--;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n + 1];
    vi v;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i = 1; i <= n; i++)
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;

    while(bsz * bsz < n) bsz++;
    for(int i = 1; i <=n; i+=bsz){
        m++;
        for(int j = i; j <= min(n, i + bsz - 1); j++)
            bid[j] = m;
    }

    que q[k];
    for(int i = 0; i < k; i++){
        cin>>q[i].l>>q[i].r;
        q[i].id = i;
        q[i].bid = bid[q[i].l];
    }
    sort(q, q + k);
    
    ll ans[k];
    int l = 1, r = 0;
    for(const que& x : q){
        while(l > x.l) add(a[--l]);
        while(r < x.r) add(a[++r]);
        while(l < x.l) del(a[l++]);
        while(r > x.r) del(a[r--]);
        
        ans[x.id] = res;
    }

    for(const ll& x : ans) 
        cout<<x<<el;
    return 0;
}