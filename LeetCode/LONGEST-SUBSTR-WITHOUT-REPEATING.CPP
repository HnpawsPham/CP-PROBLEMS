#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    n = s.length();
    unordered_map<char, int> mp;
    int i = 0, j = 0, maxlen = 0, n = s.length();

    while(j < n){
        if(mp.find(s[j]) != mp.end())
            i = max(i, mp[s[j]] + 1);
        
        mp[s[j]] = j;
        maxlen = max(maxlen, j - i + 1);
        j++;
    }

    cout<<maxlen;
    return 0;
}