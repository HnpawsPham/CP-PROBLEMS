#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    string a[n];
    int b[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    vector<string> res;
    bool last = b[0];
    res.push_back(a[0]);

    for(int i = 1; i < n; i++)
        if(b[i] != last){
            res.push_back(a[i]);
            last = b[i];
        }
    for(string x : res) cout<<x<<" ";
    return 0;
}