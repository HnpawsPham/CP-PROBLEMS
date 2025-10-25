#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc = 1;

string sol(){
    string s;
    cin>>s;
    int pos11 = s.find("11");
    int pos00 = s.rfind("00");
    if(pos00 != -1 && pos11 != -1 && pos11 < pos00) 
        return "NO";
    return "YES";
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