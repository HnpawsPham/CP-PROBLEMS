#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

string s, t;
unordered_map<char, int> cnts, cntt;

bool check(){
    for(auto x : cntt)
        if(cnts[x.fi] < x.se) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>t;
    for(char x : t) cntt[x]++;

    int n = s.length(), m = t.length();
    int l = 0, len = n;
    int bestl = 0;

    for(int r = 0; r < n; r++){
        cnts[s[r]]++;

        while(l <= r && check()) {
            if(r - l + 1 < len) {
                len = r - l + 1;
                bestl = l;
            }
            cnts[s[l++]]--;
        }
    }
    string res = "";
    if(len >= m) res = s.substr(bestl, len);
    cout<<res;
    return 0;
}

// ADOBECODEBANC
// ABC