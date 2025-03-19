#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;

int main(){
    freopen("HORSE.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll a[n], b[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    sort(a, a + n);
    sort(b, b + n);

    int i = 0, j = 0, cnt = 0;
    while(i < n && j < n){
        if(a[i] > b[j]){
            cnt++;
            j++;
        }
        i++;
    }
    cout<<cnt;
    return 0;
}