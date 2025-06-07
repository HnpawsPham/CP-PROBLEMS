#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pci pair<char, int>
#define fi first
#define se second

string s;

struct comp{
    bool operator()(const pci& a, const pci& b) const{
        return a.fi > b.fi || (a.fi == b.fi && a.se < b.se);
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    int n = s.length();
    priority_queue<pci, vector<pci>, comp> pq;

    for(int i = 0; i < n; i++){
        if(!pq.empty() && s[i] == '*')
            pq.pop();
        
        else pq.push({s[i], i});
    }

    vector<char> res(n);

    while(!pq.empty()){
        pci x = pq.top();
        pq.pop();

        res[x.se] = x.fi;
    }

    string ss = "";
    for(const char& x : res) 
        if(x >= 'a') ss += x;
    cout<<ss;
    return 0;
}