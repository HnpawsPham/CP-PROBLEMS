#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

unordered_map<string, string> mp = {
    {"1", "one"},
    {"2", "two"},
    {"3", "three"},
    {"4", "four"},
    {"5", "five"},
    {"6", "six"},
    {"7", "seven"},
    {"8", "eight"},
    {"9", "nine"},
    {"10", "ten"},
    {"11", "eleven"},
    {"12", "twelve"},
    {"13", "thirteen"},
    {"14", "fourteen"},
    {"15", "fifteen"},
    {"16", "sixteen"},
    {"17", "seventeen"},
    {"18", "eighteen"},
    {"19", "nineteen"},
    {"20", "twenty"}
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n = s.length();

    if('0' <= s[0] && s[0] <= '9') cout<<mp[s];
    else{
        for(auto x : mp){
            if(x.se.length() != n) continue;
            int cnt = 0;
            bool ok = 1;
            for(int i = 0; i < n; i++){
                if(s[i] != x.se[i]) cnt++;
                if(cnt > 1) {
                    ok = 0;
                    break;
                }
            }
            if(ok) return cout<<x.fi, 0;
        }
    }
    return 0;
}

// 8
// aight