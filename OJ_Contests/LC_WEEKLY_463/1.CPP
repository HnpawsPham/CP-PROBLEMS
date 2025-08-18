#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    vi a(n), b(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    ll sum = 0;
    for(int i = 0; i < n; i++) 
        sum += 1LL * a[i] * b[i];

    ll keep = 0, sell = 0;
    for(int i = 0; i < k / 2; i++)
        keep += 1LL * a[i] * -b[i];

    for(int i = k / 2; i < k; i++)
        sell += 1LL * a[i] * (1 - b[i]);

    ll del = sell + keep;

    for(int i = k; i < n; i++){
        sell -= 1LL * a[i - k / 2] * (1 - b[i - k / 2]);
        sell += 1ll * a[i] * (1 - b[i]);

        keep -= 1LL * a[i - k] * -b[i - k];
        keep += 1LL * a[i - k / 2] * -b[i - k / 2];

        del = max(del, sell + keep);
    }
    cout<<sum + max(0LL, del);
    return 0;
}

// 3 2
// 4 2 8
// -1 0 1