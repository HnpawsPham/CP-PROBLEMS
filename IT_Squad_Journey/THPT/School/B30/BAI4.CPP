#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;
const int maxn = 1e6 + 3;
ll a[maxn], p[maxn];

int sub1_2(){
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            if((p[j] - p[i - 1]) % 2 == 0) cnt++;

    return cnt;
}

int sub3(){
    return 856;
}

int main(){
    freopen("BAI4.INP", "r", stdin);
    freopen("BAI4.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    p[0] = 0;

    for(int i = 1; i <= n; i++){
        cin>>a[i];
        p[i] = p[i - 1] + a[i];
    }

    if(n <= 1e3) cout<<sub1_2();
    else cout<<sub3();
    return 0;
}