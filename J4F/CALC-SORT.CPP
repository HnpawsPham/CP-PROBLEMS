#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

bool check(int a, int b, int c){
    if(a + b - c == 0) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 2; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(check(a, b, c) || check(a, c, b) || check(b, c, a)) cout<<"yes"<<el;
        else cout<<"no"<<el;
    }

    return 0;
}

// 4 9 5
// 342 533 2425