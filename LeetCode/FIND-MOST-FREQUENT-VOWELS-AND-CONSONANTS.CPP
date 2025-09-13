#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

bool isvow(char x){
    if(x == 'a' || x == 'e' || x == 'i' || x == 'u' || x == 'o') return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int cnt[26] = {0};

    for(const char& x : s) cnt[x - 'a']++;
    
    int s1 = 0, s2 = 0;
    for(int i = 0; i < 26; i++)
        if(isvow(char(i + 'a'))) s1 = max(s1, cnt[i]);
        else s2 = max(s2, cnt[i]);

    cout<<s1 + s2;
    return 0;
}