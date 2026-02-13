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

int n;

int single(const string& s){
    int maxx = 0;
    for(int i = 0; i < n;){
        int j = i;
        while(j < n && s[i] == s[j]) j++;
        maxx = max(maxx, j - i);
        i = j;
    }
    return maxx;
}

int two(const string& s, char a, char b){
    unordered_map<int, int> mp, tmp;
    mp[0] = -1;
    int d = 0, maxx = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == a) d++;
        else if(s[i] == b) d--;
        else{
            mp = tmp;
            d = 0;
            mp[0] = i;
            continue; 
        }

        if(mp.find(d) != mp.end())
            maxx = max(maxx, i - mp[d]);
        else mp[d] = i;
    }
    return maxx;
}

int three(const string& s){
    int cnta = 0, cntb = 0, cntc = 0;
    map<pii, int> mp;
    mp[{0, 0}] = -1;
    int maxx = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == 'a') cnta++;
        else if(s[i] == 'b') cntb++;
        else cntc++;

        pii cur = {cntb - cnta, cntc - cnta};

        if(mp.find(cur) != mp.end())
            maxx = max(maxx, i - mp[cur]);
        else mp[cur] = i;
    }
    return maxx;
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
    n = s.length();

    int res = single(s);
    res = max(res, two(s, 'a', 'b'));
    res = max(res, two(s, 'b', 'c'));
    res = max(res, two(s, 'a', 'c'));
    cout<<max(res, three(s));
    return 0;
}