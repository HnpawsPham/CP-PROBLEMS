#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    unordered_set<int> res, cur, tmp;
    for(char x : a){
        tmp.insert(x);

        for(int y : cur)
            tmp.insert(y | x);
        
        cur = tmp;
        res.insert(cur.begin(), cur.end());
        tmp.clear();
    }
    cout<<res.size();
    return 0;
}