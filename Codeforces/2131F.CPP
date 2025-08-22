#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc;

ll sol(){
    int n;
    string s;
    cin>>n>>s;
    int a[n], b[n];
    for(int i = 0; i < n; i++) 
        a[i] = int(s[i] - '0');

    cin>>s;
    for(int i = 0; i < n; i++)
        b[i] = int(s[i] - '0');

    ll res = 1LL * n * n * 1LL * (n + 1) / 2;
    
    int pa[n + 1] = {0}, pb[n + 1] = {0};
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < n; i++){
        cnt0 += 1 * (1 - a[i]);
        cnt1 += 1 * a[i];
        pa[i + 1] = cnt0 - cnt1; 
    }

    cnt0 = cnt1 = 0;
    for(int i = 0; i < n; i++){
        cnt0 += 1 * (1 - b[i]);
        cnt1 += 1 * b[i];
        pb[i + 1] = cnt1 - cnt0; 
    }
    sort(pa + 1, pa + n + 1);
    sort(pb + 1, pb + n + 1);

    ll sum = 0;
    for(int i = 1; i <= n; i++){
        int cnt = lower_bound(pb + 1, pb + n + 1, pa[i]) - pb - 1;
        sum += 1LL * pa[i] * (2 * cnt - n);
        cnt = upper_bound(pa + 1, pa + n + 1, pb[i]) - pa - 1;
        sum += 1LL * pb[i] * (2 * cnt - n);
    }
    return res - sum / 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }

    return 0;
}