#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];   
    sort(a, a + n);

    ll sum = 0, h = 0, keep = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        keep++;
        if(a[i] > h) h++;
    }
    cout<<sum - keep - a[n - 1] + h;
    return 0;
}