#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, k;
const int maxn = (int)1e6 + 5;
ll a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    ll sum_a = 0, sum_b = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        sum_a += a[i];
    }
    for(int i = 0; i < k; i++){
        int x; cin>>x;
        sum_b += a[x - 1];
    }

    double avg_a = (double)sum_a / n;
    double avg_b = (double)sum_b / k;
    cout<<fixed<<setprecision(5)<<avg_a<<el<<avg_b;

    return 0;
}