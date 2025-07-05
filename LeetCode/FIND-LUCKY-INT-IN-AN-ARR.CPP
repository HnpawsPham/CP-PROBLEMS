#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt[501] = {0};
    for(int i = 0; i < n; i++) cnt[a[i]]++;

    int res = -1;
    for(int i = 0; i < n; i++)
        if(a[i] == cnt[a[i]]) res = max(res, a[i]);

    cout<<res;
    return 0;
}