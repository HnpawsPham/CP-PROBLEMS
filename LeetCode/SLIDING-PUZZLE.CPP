#include <bits/stdc++.h>
using namespace std;
#define el '\n'

string change(string s, int pos, int d){
    swap(s[pos], s[pos + d]);
    return s;
}

vector<string> gennext(string s){
    int pos = s.find('0');
    vector<string> v;

    if(pos % 3 > 0) v.push_back(change(s, pos, -1)); 
    if(pos % 3 < 2) v.push_back(change(s, pos, 1)); 
    if(pos / 3 > 0) v.push_back(change(s, pos, -3)); 
    if(pos / 3 < 1) v.push_back(change(s, pos, 3));  

    return v;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 2, m = 3;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < m; j++) cin>>a[i][j];

    string st = "", target = "123450";
    for(const vector<int>& v : a)
        for(const int& x : v) st += char(x + '0');

    queue<string> q;
    q.push(st);
    unordered_map<string, int> dis;
    dis[st] = 0;

    while(!q.empty()){
        string cur = q.front();
        q.pop();

        if(cur == target) 
            return cout<<dis[cur], 0;

        for(string next : gennext(cur)){
            if(!dis.count(next)){
                dis[next] = dis[cur] + 1;
                q.push(next);
            }
        }
    }
    cout<<-1;
    return 0;
}