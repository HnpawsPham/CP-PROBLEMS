#include <bits/stdc++.h>
using namespace std;
#define el '\n'

vector<string> gennext(string& s){
    vector<string> res;
    for(int i = 0; i < 4; i++){
        char x = s[i];
        s[i] = (x == '9' ? '0' : x + 1);
        res.push_back(s);

        s[i] = (x == '0' ? '9' : x - 1);
        res.push_back(s);
        s[i] = x;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string target;
    int n;
    cin>>n>>target;
    vector<string> bad(n);
    for(int i = 0; i < n; i++) cin>>bad[i];

    queue<string> q;
    string st = "0000";
    q.push(st);
    unordered_set<string> check;
    unordered_map<string, int> dis;
    dis[st] = 0;

    for(const string& x : bad) check.insert(x);
    if(check.count(st)) return cout<<-1, 0;
    
    check.insert(st);

    while(!q.empty()){
        string cur = q.front();
        q.pop();

        for(string next : gennext(cur))
            if(!check.count(next)){
                check.insert(next);
                dis[next] = dis[cur] + 1;
                q.push(next);
            }
    }
    cout<<(dis.count(target) ? dis[target] : -1);
    return 0;
}