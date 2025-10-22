#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll sum = 0, maxx = 0;
    for(int i = 0; i < n; i++){
        sum = max((ll)a[i], sum + a[i]);
        maxx = max(maxx, sum);
    }
    cout<<maxx;
    return 0;
}

// 3
// 1 -3 3