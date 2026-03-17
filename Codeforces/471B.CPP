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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i].fi;
        a[i].se = i;
    }

    int cnt[2005] = {0};
    for(const pii& x : a) cnt[x.fi]++;

    int dup = 0;
    for(const int& x : cnt)
        if(x > 1) dup += x;

    if(dup < 3) return cout<<"NO", 0;

    cout<<"YES"<<el;
    sort(a.begin(), a.end());

    vector<pii> v1 = a, v2;
    for(int i = 1, k = 3; i < n && k; i++)
        if(cnt[v1[i].fi] > 1 && v1[i].fi == v1[i - 1].fi){
            swap(v1[i], v1[i - 1]);
            if(k == 3) v2 = v1;
            k--;
        }

    for(pii x : a) cout<<x.se + 1<<" "; cout<<el;
    for(pii x : v1) cout<<x.se + 1<<" "; cout<<el;
    for(pii x : v2) cout<<x. se + 1<<" "; cout<<el;
    return 0;
}