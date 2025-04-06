#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    sort(a, a + n);
    int dp[n], parent[n];
    int maxx = 0;

    for(int i = 0; i < n; i++){
        dp[i] = 1;
        parent[i] = -1;

        for(int j = 0; j < i; j++){
            if(a[i] % a[j] == 0 && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }

            if(dp[i] > dp[maxx]) maxx = i;
        }
    }

    vector<int> res;
    for(int i = maxx; i >= 0; i = parent[i]) 
        res.push_back(a[i]);
    
    for(int x : res) cout<<x<<" ";
    return 0;
}