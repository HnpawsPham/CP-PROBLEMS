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

int tc = 1;

int sol(){
    string s;
    cin>>s;
    int n = s.length();

    string t = "";
    for(int i = n - 1; i >= 0; i--){
        if(!t.empty() && t.back() == 'p' && s[i] == 'a'){
            t.pop_back();
            t += "ptp";
        }
        else t.push_back(s[i]);
    }
    reverse(t.begin(), t.end());

    n = t.size();
    s.clear();
    for(int i = 0; i < n; i++){
        if(i < n - 1 && !s.empty() && s.back() == 'p' && t[i] == 't' && t[i + 1] == 'p'){
            s.pop_back();
            s += "ap";
            i++;
        }
        else s.push_back(t[i]);
    }
    return s.size();
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}