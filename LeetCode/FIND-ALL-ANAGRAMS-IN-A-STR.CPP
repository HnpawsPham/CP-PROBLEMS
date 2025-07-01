#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s, p;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>p;
    int n = s.length(), m = p.length();

    vector<int> cnt_p(26, 0), cnt_s(26, 0);
    for(char x : p) cnt_p[x - 'a']++;

    vector<int> res;

    for(int i = 0; i < n; i++){
        cnt_s[s[i] - 'a']++;

        if(i >= m) cnt_s[s[i - m] - 'a']--;
        
        if(cnt_p == cnt_s) res.push_back(i - m + 1);
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}