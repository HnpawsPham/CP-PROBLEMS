#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    stack<int> open;
    int n = s.length();
    vector<int> a(n, 0);

    for(int i = 0; i < n; i++){
        if(s[i] == '(') 
            open.push(i);

        else if(s[i] == ')' && !open.empty()){
            a[open.top()] = a[i] = 1;
            open.pop();
        }
    }

    int len = 0, cur = 0;
    for(int i = 0; i < n; i++){
        len = max(len, cur);
        if(a[i] == 1) cur++;
        else cur = 0;
    }
    len = max(len, cur);
    // for(int x : a) cout<<x<<" ";
    cout<<len;
    return 0;
}