#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc, x;
unordered_set<int> st;

string sol(){
    st.clear();

    while(x != 1 && x != 7){
        int sum = 0;
        while(x > 0){
            sum += (x % 10) * (x % 10);
            x /= 10;
        }
        if(st.count(sum)) return "NO";
        x = sum;
        st.insert(x);
    }
    return "YES";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cin>>x;
        cout<<sol()<<el;        
    }

    return 0;
}