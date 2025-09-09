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

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);

    ll w = 0, h = 0;
    for(int i = 0; i < n / 2; i++){
        h += a[i];
        w += a[n - i - 1];
    }
    if(n % 2) w += a[n / 2];
    cout<<1LL * w * w + 1LL * h * h;
    return 0;
}