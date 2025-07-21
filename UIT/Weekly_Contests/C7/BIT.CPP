#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define pii pair<int, int>
#define vi vector<int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    string s;

    int num = 0;
    while(n--){
        cin>>s;
        if(s[1] == '+') num++;
        else num--;
    }
    cout<<num;
    return 0;
}