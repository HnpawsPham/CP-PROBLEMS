#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int res = 0;
    vector<int> minn(n), maxx(n);
    minn[0] = a[0];
    maxx[n - 1] = a[n - 1];

    for(int i = 1; i < n; i++)
        minn[i] = min(a[i], minn[i - 1]);
    
    for(int i = n - 2; i >= 0; i--)
        maxx[i] = max(a[i], maxx[i + 1]);

    for(int i = 0; i < n; i++)
        res = max(res, maxx[i] - minn[i]);

    cout<<(res == 0 ? -1 : res);

    return 0;
}