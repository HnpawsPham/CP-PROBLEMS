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

int n, q;
const int maxn = 5e5 + 5;
ll a[maxn];
int bsz = 1, m = 0;
int bst[maxn], ben[maxn], bid[maxn], bpos[maxn];
ll sumb[maxn] = {0}, addb[maxn] = {0};

void update(int l, int r, int w){
    if(bid[l] == bid[r]){
        for(int i = l; i <= r; i++){
            a[i] += w;
            sumb[bid[l]] += w;
        }
        return;
    }

    for(int i = l; i <= ben[bid[l]]; i++){
        a[i] += w;
        sumb[bid[l]] += w;
    }

    for(int i = bid[l] + 1; i <= bid[r] - 1; i++)
        addb[i] += w;

    for(int i = bst[bid[r]]; i <= r; i++){
        a[i] += w;
        sumb[bid[r]] += w;
    }
    return;
}

ll query(int l, int r){
    ll res = 0;

    if(bid[l] == bid[r]){
        for(int i = l; i <= r; i++)
            res += a[i] + addb[bid[i]];
        return res;
    }

    for(int i = l; i <= ben[bid[l]]; i++)
        res += a[i] + addb[bid[l]];

    for(int i = bid[l] + 1; i <= bid[r] - 1; i++)
        res += sumb[i] + addb[i] * (ben[i] - bst[i] + 1);

    for(int i = bst[bid[r]]; i <= r; i++)
        res += a[i] + addb[bid[r]];
    
    return res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i = 1; i <= n; i++) cin>>a[i];

    while(bsz * bsz < n) bsz++;

    for(int i = 1; i <= n; i += bsz){
        m++;
        bst[m] = i;
        ben[m] = min(i + bsz - 1, n);

        for(int j = bst[m], pos = 0; j <= ben[m]; j++){
            bid[j] = m;
            bpos[j] = ++pos;
            sumb[m] += a[j];
        }
    }

    while(q--){
        int opt, l, r;
        cin>>opt>>l>>r;

        if(opt == 1){
            int w;
            cin>>w;
            update(l, r, w);
        }
        else cout<<query(l, r)<<el;
    }
    return 0;
}