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

    string s;
    getline(cin, s);
    int cnt[26] = {0};

    for(char x : s)
        if('a' <= x && x <= 'z') cnt[x - 'a']++;
    
    int res = 0;
    for(int x : cnt) res += (x > 0);
    cout<<res;
    return 0;
}