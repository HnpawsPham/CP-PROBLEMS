#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

vi convert(const string& s){
    int num = 0;
    vi a;
    for(char x : s){
        if(x == '.'){
            a.push_back(num);
            num = 0;
        }
        else num = num * 10 + int(x - '0');
    }
    a.push_back(num);
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin>>s>>t;
    vi a = convert(s), b = convert(t);
    int n = a.size(), m = b.size();

    while(n < m){
        a.push_back(0);
        n++;
    }

    while(m < n){
        b.push_back(0);
        m++;
    }
    
    for(int i = 0; i < n; i++){
        if(a[i] < b[i]) return cout<<-1, 0;
        else if(a[i] > b[i]) return cout<<1, 0;
    }
    cout<<0;
    return 0;
}