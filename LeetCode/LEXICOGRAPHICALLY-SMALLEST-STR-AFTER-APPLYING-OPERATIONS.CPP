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
    int a, b;
    cin>>s>>a>>b;
    int n = s.length();

    set<string> check;
    queue<string> q;
    q.push(s);

    while(!q.empty()){
        string t = q.front();
        q.pop();
        if(check.find(t) != check.end()) continue;
        check.insert(t);

        q.push(t.substr(n - b) + t.substr(0, n - b));

        for(int i = 1; i < n; i+=2)
            t[i] = (t[i] - '0' + a) % 10 + '0';
        q.push(t);
    }
    cout<<*check.begin();
    return 0;
}

// 5525 9 2

// 74 5 1