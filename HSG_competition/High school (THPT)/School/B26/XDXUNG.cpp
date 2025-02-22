#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string str, s = "|";
int n;

int main(){
    freopen(".\\txt\\XDXUNG.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>str;
    for(char x : str)
        s = s + x + '|';
    n = s.length();

    int res = 0, r = 0, c = 0;
    vector<int> p(n, 0);

    for(int i = 1; i < n; i++){
        if(i < r)
            p[i] = min(r - i, p[2 * c - i]);

        while(i - p[i] >= 0 && i + p[i] < n && s[i + p[i]] == s[i - p[i]])
            p[i]++;

        if(i + p[i] >= r){
            r = i + p[i];
            c = i;
        }
        res = max(res, p[i] - 1);
    }
    cout<<res;

    return 0;
}