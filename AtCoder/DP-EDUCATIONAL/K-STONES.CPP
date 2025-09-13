#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, k;
const int maxn = 105;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>a[i];

    bool dp[k + 1] = {0};
    for(int i = 1; i <= k; i++)
        for(int j = 0; j < n; j++)
            if(i >= a[j] && !dp[i - a[j]]) 
                dp[i] = 1;
    cout<<(dp[k] ? "First": "Second");
    return 0;
}