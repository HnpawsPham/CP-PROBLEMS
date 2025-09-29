#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    
    string res = "";
    for(int i = 0; i * 4 <= n; i++){
        int k = n - i * 4;
        if(k % 7) continue;
        for(int j = 0; j < i; j++) res += '4';
        for(int j = 0; j < k / 7; j++) res += '7';
        cout<<res;
        return 0;
    }
    cout<<-1;
    return 0;
}