#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define piii pair<pii, int>
#define pis pair<int, unordered_set<int>>
#define fi first
#define se second
//#define taskname ""

struct team{
    string name;
    int cnt, penalty;
    team(string name1, int cnt1, int penalty1) : 
        name(name1), cnt(cnt1), penalty(penalty1) {}
};

int n, m;
vector<team> a;
map<string, pis> mp;

int to_hour(const string& s){
    int sec = stoi(s.substr(6, 2));
    sec += stoi(s.substr(3, 2)) * 60;
    sec += stoi(s.substr(0, 2)) * 60 * 60;
    return sec / 60;
}

bool comp(const team& a, const team& b){
    if(a.cnt != b.cnt) return a.cnt > b.cnt;
    if(a.penalty != b.penalty) 
        return a.penalty < b.penalty;
    return a.name < b.name;
}

bool my_team(const string& s){
    return s == "NijeZivotJedanACM";
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    string name, s;
    for(int i = 0; i < n; i++){
        cin>>name;

        for(int j = 0; j < m; j++){
            cin>>s; 
            if(s[0] == '-' || my_team(name)) continue;
            
            int penalty = to_hour(s.substr(3)) + ((s[1] - '0') - 1) * 20;
   
            mp[name].fi += penalty;
            mp[name].se.insert(j);
        }
    }

    cin>>name;
    for(int j = 0; j < m; j++){
        cin>>s; 
        if(s[0] != '+') continue;

        int penalty = to_hour(s.substr(3)) + ((s[1] - '0') - 1) * 20;

        mp[name].fi += penalty;
        mp[name].se.insert(j);
    }

    vector<team> b;
    for(auto [name, status] : mp)
        b.push_back({name, (int)status.se.size(), status.fi});
        
    sort(b.begin(), b.end(), comp);

    int res = 1;
    for(const team& x : b)
        if(!my_team(x.name)) res++;
        else break;

    cout<<res;
    return 0;
}