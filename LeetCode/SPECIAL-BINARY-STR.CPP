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

string sol(string s){
    vector<string> a;
    int d = 0, n = s.size(), st = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '1') d++;
        else d--;

        if(d == 0){
            string tmp = s.substr(st + 1, i - 1 - st);
            st = i + 1;
            a.push_back('1' + sol(tmp) + '0');
        }
    }

    sort(a.begin(), a.end(), greater<string>());
    string res;
    for(const string& x : a)
        res = res + x;
    return res;
}

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
    cout<<sol(s);
    return 0;
}