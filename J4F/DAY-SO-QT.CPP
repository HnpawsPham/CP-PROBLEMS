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

const ll oo = 1e16 + 5;

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
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll smax[n], smin[n], sum = a[n - 1];
    int cntmax[n], cntmin[n];
    smax[n - 1] = smin[n - 1] = a[n - 1];
    cntmax[n - 1] = cntmin[n - 1] = 1;

    for(int i = n - 2; i > 0; i--){
        sum += a[i];
        smax[i] = smax[i + 1];
        smin[i] = smin[i + 1];

        cntmin[i] = cntmin[i + 1];
        cntmax[i] = cntmax[i + 1];

        if(sum >= smax[i + 1]){
            cntmax[i] = 1;
            if(sum == smax[i + 1])
                cntmax[i] += cntmax[i + 1];
            smax[i] = sum;
        }

        if(sum <= smin[i + 1]){
            cntmin[i] = 1;
            if(sum == smin[i + 1])
                cntmin[i] += cntmin[i + 1];
            smin[i] = sum;
        }
    }

    ll res = -3 * oo, cnt = 0, p = a[0];
    for(int i = 1; i < n; i++){
        int d = cntmin[i];
        ll maxx = abs(p - smin[i]);

        if(abs(p - smax[i]) > maxx){
            d = cntmax[i];
            maxx = abs(p - smax[i]);
        }

        if(maxx >= res){
            if(maxx > res) cnt = 0;
            cnt += d;
            res = maxx;
        }

        p += a[i];
    }
    cout<<res<<" "<<cnt;
    return 0;
}