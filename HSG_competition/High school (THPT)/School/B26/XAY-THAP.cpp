#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int t, n = 0, m = 0;
const int maxn = 5e5 + 5;
ll a[maxn], b[maxn];

int sol(bool start_red){
    int res = 0, cur_w = -1, last_a = 0, last_b = 0;;
    bool cur_color = start_red;

    // red = 1, blue = 0
    while(1){
        if(cur_color){
            int pos = upper_bound(b + last_b, b + m, cur_w) - b;
            if(pos == m) break;
            cur_w = b[pos];
            last_b = pos + 1;
        }
        else{
            int pos = upper_bound(a + last_a, a + n, cur_w) - a;
            if(pos == n) break;
            cur_w = a[pos];
            last_a = pos + 1;
        }
        res++;
        cur_color = !cur_color;
    }
    return res;
}

int main(){
    freopen(".\\txt\\XAY-THAP.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        int x; cin>>x;
        if(x < 0) b[m++] = -x;
        else a[n++] = x;
    }

    if(m * n == 0) return cout<<1, 0;

    sort(a, a + n);
    sort(b, b + m);

    return cout<<max(sol(1), sol(0)), 0;
}