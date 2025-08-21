#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc;

string sol(){
    int n, m;
    string a, b, c;
    cin>>n>>a>>m>>b>>c;

    deque<char> dq(a.begin(), a.end());
    for(int i = 0; i < m; i++){
        if(c[i] == 'V') dq.push_front(b[i]);
        else dq.push_back(b[i]);
    }
    string res(dq.begin(), dq.end());
    return res;
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