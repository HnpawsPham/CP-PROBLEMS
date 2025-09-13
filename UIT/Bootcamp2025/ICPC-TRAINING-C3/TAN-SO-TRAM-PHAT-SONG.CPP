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

    int cnt[205] = {0};
    for(int x : a) cnt[x]++;

    vector<pii> res;
    for(int i = 0; i < n; i++){
        if(cnt[a[i]] <= 1) continue;
        cnt[a[i]]--;
        for(int j = 1; j <= 100; j++)
            if(cnt[j] == 0){
                res.push_back({i + 1, j});
                cnt[j]++;
                break;
            }
    }

    cout<<res.size()<<el;
    for(auto x : res) cout<<x.fi<<" "<<x.se<<el;
    return 0;
}