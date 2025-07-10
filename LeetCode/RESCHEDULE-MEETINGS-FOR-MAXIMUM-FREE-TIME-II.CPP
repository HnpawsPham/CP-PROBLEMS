#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>

int t, n;

int moveout(int maxx, int len, int l, int r){
    if(maxx >= len) return l + r + len;
    return max({l, r, maxx});
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t>>n;
    vi l(n), r(n);
    for(int i = 0; i < n; i++) cin>>l[i];
    for(int i = 0; i < n; i++) cin>>r[i];

    vi pm(n), sm(n + 1);
    pm[0] = l[0];
    sm[n] = t - r[n - 1];

    for(int i = 1; i < n; i++)
        pm[i] = max(pm[i - 1], l[i] - r[i - 1]);

    for(int i = n - 1; i > 0; i--)
        sm[i] = max(sm[i + 1], l[i] - r[i - 1]);

    int res = 0;
    for(int i = 0; i < n; i++){
        int gl = l[i] - (i > 0 ? r[i - 1] : 0);
        int rl = (i < n - 1 ? l[i + 1] : t) - r[i];
        int len = r[i] - l[i];

        res = max(res, gl + rl);

        int maxx = (i >= 1 ? pm[i - 1] : 0);
        res = max(res, moveout(maxx, len, gl, rl));

        maxx = (i < n - 1 ? sm[i + 2] : 0);
        res = max(res, moveout(maxx, len, gl, rl));
    }
    cout<<res;
    return 0;
}
// 5 2
// 1 3
// 2 5