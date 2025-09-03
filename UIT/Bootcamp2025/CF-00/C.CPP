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

    int n, k;
    string s;
    cin>>n>>k>>s;

    ll res = 0;
    int cnt[26] = {0};
    int r = 0, d = 0;

    for(int l = 0; l < n; l++){
        while(r < n && d < k){
            if(cnt[s[r] - 'a'] == 0) d++;
            cnt[s[r] - 'a']++;
            r++;
        }
        if(d >= k) res += n - r + 1;
        
        if(cnt[s[l] - 'a'] == 1) d--;
        cnt[s[l] - 'a']--;
    }
    cout<<res;
    return 0;
}