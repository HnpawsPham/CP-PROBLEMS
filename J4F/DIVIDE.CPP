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

int n;
const int maxn = 1e5 + 5;
int a[maxn];
ll p[maxn];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    p[0] = 0;
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];

    ll res = p[n];
    int l = 1, r = 1;
    for(int mid = 2; mid <= n - 2; mid++){
        while(l + 1 < mid && abs(p[mid] - 2 * p[l]) > abs(p[mid] - 2 * p[l + 1]))
            l++;

        if(r <= mid) r = mid + 1;
        while(r + 1 < n && abs(p[n] - 2 * p[r] + p[mid]) > abs(p[n] - 2 * p[r + 1] + p[mid]))
            r++;
        
        ll g1 = p[l];
        ll g2 = p[mid] - p[l];
        ll g3 = p[r] - p[mid];
        ll g4 = p[n] - p[r];
        res = min(res, max(g1, max(g2, max(g3, g4))) - min(g1, min(g2, min(g3, g4))));
    }
    cout<<res;
    return 0;
}