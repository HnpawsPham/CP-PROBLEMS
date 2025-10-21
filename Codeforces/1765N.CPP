#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<char, int>
#define fi first
#define se second

int tc = 1;

string sol(){
    string s;
    int k;
    cin>>s>>k;
    int n = s.length();

    int j = 0;
    for(int i = 0; i <= k; i++)
        if(s[i] != '0' && s[i] < s[j]) j = i;
    k -= j;

    string res;
    res.push_back(s[j]);

    for(int i = j + 1; i < n; i++){
        while(k && res.length() > 1 && res.back() > s[i]){
            res.pop_back();
            k--;
        }
        res.push_back(s[i]);
    }

    while(k && !res.empty()){
        res.pop_back();
        k--;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}