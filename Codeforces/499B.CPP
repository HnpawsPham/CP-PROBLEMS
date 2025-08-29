#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

string comp(const string& a, const string& b){
    if(a.length() <= b.length()) return a;
    return b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;

    unordered_map<string, string> mp;
    while(m--){
        string a, b;
        cin>>a>>b; 
        mp[a] = comp(a, b);
    }

    while(n--){
        string s;
        cin>>s;
        cout<<mp[s]<<" ";
    }
    return 0;
}