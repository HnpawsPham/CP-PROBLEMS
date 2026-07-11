#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pil pair<int, ll>
#define fi first
#define se second
#define taskname "MARIO"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, pos, k;
    cin>>n>>pos>>k;
    pii b[n + 1];
    b[n] = {pos, 0};
    for(int i = 0; i < n; i++)
        cin>>b[i].fi>>b[i].se;
    sort(b, b + n + 1);

    vector<pil> a;
    a.push_back({b[0].fi, b[0].se});

    for(int i = 1; i <= n; i++)
        if(b[i].fi == b[i - 1].fi)
            a.back().se += b[i].se;
        else a.push_back({b[i].fi, b[i].se});

    int mid = 0;
    n = a.size();
    for(int i = 0; i < n; i++)
        if(a[i].fi == pos){
            mid = i;
            break;
        }

    ll p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] += p[i - 1] + a[i - 1].se;

    ll res = 0;
    
    int r = mid;
    for(int l = mid; l >= 0; l--){
        while(r + 1 < n && (a[mid].fi - a[l].fi) * 2 + a[r].fi - a[mid].fi <= k)
            r++;
        
        if((a[mid].fi - a[l].fi) * 2 + a[r].fi - a[mid].fi <= k)
            res = max(res, p[r + 1] - p[l]);
    }

    int l = mid;
    for(int r = mid; r < n; r++){
        while(l - 1 >= 0 && (a[r].fi - a[mid].fi) * 2 + a[mid].fi - a[l].fi <= k)
            l--;
        
        if((a[r].fi - a[mid].fi) * 2 + a[mid].fi - a[l].fi <= k)
            res = max(res, p[r + 1] - p[l]);
    }
    cout<<res;
    return 0;
}