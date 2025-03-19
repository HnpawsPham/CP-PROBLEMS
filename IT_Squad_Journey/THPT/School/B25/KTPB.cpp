#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string str;
int n;
int cnt[27];

int main(){
    freopen(".\\txt\\KTPB.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>str;
    n = str.length();

    memset(cnt, 0, sizeof(cnt));
    unordered_set<char> s;
    
    for(int i = 0; i < n; i++)
        s.insert(str[i]);
    
    int k = s.size();

    for(int i = 0; i < n; ++i){
        s.clear();
        for(int j = i; j < n; ++j){
            s.insert(str[j]);
            cnt[s.size()]++;
        }
    }
    for(int i = 1; i<=k;i++) cout<<cnt[i]<<el;
    return 0;
}