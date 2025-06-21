#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define fi first
#define se second

unordered_map<char, int> mp = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
    {'0', 0}
};

string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    s += '0';
    int n = s.length();
    int res = 0;

    for(int i = 0; i < n; i++){
        if(mp[s[i]] < mp[s[i + 1]])
            res -= mp[s[i]];

        else res += mp[s[i]];
    }
    cout<<res;
    return 0;
}