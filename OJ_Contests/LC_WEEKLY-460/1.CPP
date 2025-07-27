#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    sort(a.begin(), a.end());
    ll sum = 0;
    for (int i = n - 2; i >= n / 3; i -= 2)
        sum += a[i];
    cout<<sum;
    return 0;
}