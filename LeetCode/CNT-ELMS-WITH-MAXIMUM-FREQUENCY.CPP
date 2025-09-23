#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
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

    int cnt[101] = {0};
    for(int x : a) cnt[x]++;
    int maxx = *max_element(cnt, cnt + 101);

    int res = 0;
    for(int x : a)
        if(cnt[x] == maxx) res++;
    cout<<res;
    return 0;
}