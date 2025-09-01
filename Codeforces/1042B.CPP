#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pis pair<int, string>
#define fi first
#define se second

int res = 1e9;
const int oo = 1e6 + 5;
unordered_map<string, int> mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, w;
    string s;
    cin>>n;
    pis a[n];
    for(int i = 0; i < n; i++){
        cin>>w>>s;
        sort(s.begin(), s.end());

        a[i] = {w, s};
        if(!mp.count(s)) mp[s] = oo;
        mp[s] = min(mp[s], w);
    }

    for(const string& s : {"A", "B", "C", "AB", "BC", "AC", "ABC"})
        if(!mp.count(s)) mp[s] = oo;

    res = min(res, mp["ABC"]);
    res = min(res, mp["A"] + mp["B"] + mp["C"]);
    res = min(res, mp["AB"] + mp["C"]); 
    res = min(res, mp["AC"] + mp["B"]); 
    res = min(res, mp["BC"] + mp["A"]);
    res = min(res, mp["AB"] + mp["BC"]); 
    res = min(res, mp["AB"] + mp["AC"]); 
    res = min(res, mp["BC"] + mp["AC"]);

    if(res == oo) cout<<-1;
    else cout<<res;
    return 0;
}