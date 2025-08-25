#include <bits/stdc++.h>
using namespace std;

int n;
string s;

string sol(){
    int cnt[10] = {0};227B.C
    for(char x : s) cnt[x - '0']++;
    
    if(!cnt[1] && !cnt[2] && !cnt[3]) return "NO";
    if(!cnt[1] && !cnt[4] && !cnt[7] && !cnt[0]) return "NO";
    if(!cnt[3] && !cnt[6] && !cnt[9] && !cnt[0]) return "NO";
    if(!cnt[7] && !cnt[0] && !cnt[9]) return "NO";
    return "YES";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    cout<<sol();
    return 0;
}