#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;
ll res = LLONG_MAX, total = 0;
const int maxn = 21;
int a[maxn];

void sol(int i, int cnt, ll sum){
    if(i == n || cnt == n - 1){
        res = min(res, abs(total - 2 * sum));
        return;
    }

    sol(i + 1, cnt + 1, sum + a[i]);
    sol(i + 1, cnt + 1, sum);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        total += a[i];
    }
    sol(0, 0, 0);
    cout<<res;
    return 0;
}