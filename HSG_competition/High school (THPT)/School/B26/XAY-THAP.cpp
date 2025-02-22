#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int t, n = 0, m = 0;
const int maxn = 5e5 + 5;
ll a[maxn], b[maxn];

int main(){
    freopen(".\\txt\\XAY-THAP.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        int x; cin>>x;
        if(x < 0) b[m++] = abs(x);
        else a[n++] = x;
    }

    if(m * n == 0) return cout<<1, 0;

    sort(a, a + n);
    sort(b, b + m);

    int dp_a[n][2], dp_b[m][2];
    dp_a[0][1] = dp_b[0][1] = 1;
    dp_a[0][0] = dp_b[0][0] = 0;

    for(int i = 1; i < n; i++){
        dp_a[i][0] = dp_a[i - 1][0] + 1;
        dp_a[i][1] = max(dp_a[i - 1][0], dp_a[i - 1][1]);
        
        int pos = upper_bound(b, b + m, a[i]) - b;
        if(pos < m)
            dp_a[i][1] = max(dp_a[i - 1][1] + 2, dp_a[i - 1][0]); 
    }
    
    return 0;
}