#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;
    string s;
    cin>>s>>m;

    vector<string> w(m);
    for(int i = 0; i < m; i++) cin>>w[i];

    int wlen = w[0].length();
    int sz = wlen * m;
    int n = s.length();

    unordered_map<string, int> cntw;
    for(const string& x : w) cntw[x]++;

    vector<int> res;
    int cnt = 0;

    for(int l = 0; l < n - sz; l++){
        unordered_map<string, int> mp;

        for(int r = l; r <= n - wlen; r += wlen){
            string x = s.substr(r, wlen);

            if(cntw.find(x) == cntw.end()){
                cnt = 0;
                mp.clear();
                l = r + wlen;
                continue;
            }

            mp[x]++;
            cnt++;

            while(mp[x] > cntw[x]){
                string head = s.substr(l, wlen);
                mp[head]--;
                l += wlen;
                cnt--;
            }

            if(cnt == m) res.push_back(l);
        }
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}

// barfoothefoobarman
// 2
// foo bar