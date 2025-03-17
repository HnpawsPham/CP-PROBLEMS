#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
vector<string> a;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int minlen = 205;
    for(int i = 0; i < n; i++){
        string str;
        cin>>str;
        minlen = min((int)str.length(), minlen);
        a.push_back(str);
    }

    string res = "";

    for(int i = 0; i < minlen; i++){
        for(int j = 1; j < n; j++)
            if(a[j][i] != a[0][i]) return cout<<res, 0;
        res += a[0][i];
    }
    cout<<res;
    return 0;
}