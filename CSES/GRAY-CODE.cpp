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
    if(n == 1) return cout<<"0\n1", 0;

    vector<string> tmp = {"00", "01", "11", "10"}, a;

    for(int i = 3; i <= n; i++){
        a = tmp;
        tmp.clear();

        for(string s : a) tmp.push_back('0' + s);
        reverse(a.begin(), a.end());

        for(string s : a) tmp.push_back('1' + s);
    }
    for(string s : tmp) cout<<s<<el;
    return 0;
}