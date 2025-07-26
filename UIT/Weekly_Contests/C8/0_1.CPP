#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int res = 0, maxx = INT_MIN, sum = 0;

    for(int i = 0; i < n; i++){
        res += a[i];
        int x = (a[i] == 0 ? 1 : -1);
        sum = max(sum + x, x);
        maxx = max(maxx, sum);
    }
    if(maxx <= 0) maxx = -1;
    
    cout<<res + maxx;
    return 0;
}