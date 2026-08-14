#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    
    int n = s.length();
    int cnt[26];
    memset(cnt, 0, sizeof cnt);
    
    int l = 0, res =0;
    for(int i = 0; i < n; i++){
        cnt[s[i] - 'a']++;
        
        while(l <= i && cnt[s[i] - 'a'] > 2){
            cnt[s[l] - 'a']--;
            l++;
        }
        res = max(res, i - l + 1);
    }
    cout<<res;
    return 0;
}