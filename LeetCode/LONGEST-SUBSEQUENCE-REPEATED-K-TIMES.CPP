#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s = "", res = "";
int k, n, maxlen = 0;
int cnt[26] = {0};

bool check(string& t){
    if(t.empty()) return 1;

    int cnt = 0;
    int j = 0;
    int m = t.length();

    for(int i = 0; i < n; i++){
        if(s[i] == t[j]) j++;
        
        if(j == m){
            cnt++;
            if(cnt == k) return 1;
            j = 0;
        }
    }
    return 0;
}

void sol(string& ss){
    if(!check(ss)) return;

    int len = ss.length();
    if(len > maxlen || (len == maxlen && ss > res)){
        res = ss;
        maxlen = len;
    }

    if(len + (8 - len) < maxlen || len == 8) return;
    
    for(int j = 25; j >= 0; j--){
        if(cnt[j] >= k){
            cnt[j] -= k;
            ss.push_back(char(j + 'a'));

            sol(ss);

            ss.pop_back();
            cnt[j] += k;
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string inp;
    cin>>inp>>k;

    for(const char& x : inp)
        cnt[x - 'a']++;

    for(const char& x : inp)
        if(cnt[x - 'a'] >= k) s += x;
        
    n = s.length();

    string tmp = "";
    sol(tmp);

    cout<<res;
    return 0;
}