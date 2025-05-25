#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define fi first
#define se second

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    string a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    unordered_map<string, int> mp;
    int cnt = 0;
    bool first = 1;

    for(const string& s : a)
        mp[s]++;
    
    for(const auto& [s, freq] : mp){
        if(s[0] == s[1]){
            cnt += (freq / 2) * 4;
            if(freq % 2) mid = 1;
        }
        else{
            string rs = "";
            rs = rs + s[1] + s[0];

            if(mp.count(rs) && s < rs) 
                cnt += min(freq, mp[rs]) * 4;
        }
    }
    cout<<cnt + mid * 2;
    return 0;
}