#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    unordered_map<string, int> mp;
    string s;

    while(n--){
        cin>>s;
        mp[s]++;
    }

    cin>>m;
    while(m--){
        cin>>s;
        cout<<(mp[s] ? "YES" : "NO")<<el;
    }

    return 0;
}