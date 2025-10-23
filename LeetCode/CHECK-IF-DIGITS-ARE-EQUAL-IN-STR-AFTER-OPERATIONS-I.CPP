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

    string s;
    cin>>s;
    string tmp;
    int n = s.length();

    while(n > 2){
        for(int i = 0; i < n - 1; i++)
            tmp.push_back((s[i] - '0' + s[i + 1] - '0') % 10 + '0');
        n--;
        s = tmp;
        tmp.clear();
        cout<<s<<el;
    }
    cout<<(s[0] == s[1]);
    return 0;
}