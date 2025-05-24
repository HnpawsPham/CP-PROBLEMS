#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
char ch;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>ch;
    string a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<int> res;
    for(int i = 0; i < n; i++)
        for(char x : a[i])
            if(x == ch){
                res.push_back(i);
                break;
            }
    
    for(int x : res) cout<<x<<" ";
    return 0;
}