#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;
int k;
char f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>k>>f;
    int n = s.length();
    vector<string> res;

    int i = 0;
    for(;i < n; i += k)
        res.push_back(s.substr(i, k) + (n - i < k ? string(k - (n - i), f) : ""));
    
    for(string x : res) cout<<x<<el;
    return 0;
}
// abcdefghij 3 x