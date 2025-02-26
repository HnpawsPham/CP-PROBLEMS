#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, x;

int main(){
    freopen("TUONGDONG.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>x;
    int a[n];
    for(int i = 0; i <n; ++i) cin>>a[i];
    sort(a, a + n);
    
    int cnt = 0, j = 1;
    for(int i = 0; i < n; ++i){
        while(j < n && a[j] - a[i] <= x) j++;
        cnt += (j - i - 1);
    }
    cout<<cnt;
    return 0;
}