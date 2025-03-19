#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;
ll k;
const int maxn = (int)1e5 + 5;
ll a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);

    int cnt = 0;
    for(int i = 0; i < n; i++){
        k -= a[i];

        if(k < 0) break;
        cnt++;
    }

    cout<<cnt;

    return 0;
}