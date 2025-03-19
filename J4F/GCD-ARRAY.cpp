#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
const int maxn = 2* (int)1e5 + 5;
int a[maxn], b[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < n; ++i) cin>>a[i];
    for(int i = 0; i < m; ++i) cin>>b[i];

    int p = 0;
    for(int i = 1; i < n; ++i)
        p = __gcd(p, abs(a[i] - a[0]));

    for(int i = 0; i < m; ++i)
        cout<<__gcd(abs(b[i] + a[0]), p)<<" ";

    return 0;
}