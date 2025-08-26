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

    int n, m;
    cin>>n>>m;

    if((n > m + 1) || (m > 2 * (n + 1))) return cout<<-1, 0;

    string s = "";
    while(n > 0 || m > 0){
        if(m > n){
            if(m >= 2 && m - 2 >= n){ 
                s += "11";
                m -= 2;
            } 
            else {
                s += "1";
                m--;
            }
            if(n > 0){
                s += "0";
                n--;
            }
        } 
        else {
            if(n > 0){
                s += "0";
                n--;
            }
            if(m > 0){
                s += "1";
                m--;
            }
        }
    }
    cout<<s;
    return 0;
}