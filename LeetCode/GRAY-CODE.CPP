#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<string> tmp = {"0", "1"}, a;
    vector<int> res;

    for(int i = 2; i <= n; i++){
        a = tmp;
        tmp.clear();

        for(string s : a) tmp.push_back('0' + s);
        reverse(a.begin(), a.end());

        for(string s : a) tmp.push_back('1' + s);
    }
    for(string s : tmp) res.push_back(stoi(s, nullptr, 2));
    for(int x : res) cout<<x<<" ";
    return 0;
}