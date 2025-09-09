#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

bool check(int x){
    while(x > 0){
        if(x % 10 == 0) return 0;
        x /= 10; 
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vi res;
    for(int i = 1; i < n; i++)
        if(check(i))
            if(check(n - i)){
                res.push_back(i);
                res.push_back(n - i);
                break;
            }
    for(int x : res) cout<<x<<" ";
    return 0;
}