#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define MOD 1000000007

int n;
const int maxn = 3 * (int)1e5 + 5;
int a[maxn];
int cnt[maxn];
int dp[maxn];

int main(){
    freopen(".\\txt\\SEGDIV.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }


    return 0;
}