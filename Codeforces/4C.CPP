#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    unordered_map<string, int> mp;

    while(n--){
        string s;
        cin>>s;
        mp[s]++;

        if(mp[s] == 1) cout<<"OK"<<el;
        else cout<<s<<mp[s] - 1<<el;
    }

    return 0;
}