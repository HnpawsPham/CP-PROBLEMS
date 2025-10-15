#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int k, t;
string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>k>>s>>t;
    string tmp = s;
    for(int i = 1; i < k; i++) s += tmp;
    int n = s.length();

    bool del[n] = {0};
    vi pos[26];
    for(int i = 0; i < n; i++)
        pos[s[i] - 'a'].push_back(i);

    while(t--){
        int p;
        char c;
        cin>>p>>c;
        del[pos[c - 'a'][p - 1]] = 1;
        pos[c - 'a'].erase(pos[c - 'a'].begin() + p - 1);
    }

    for(int i = 0; i < n; i++)
        if(!del[i]) cout<<s[i];
    return 0;
}