#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int n;
string ones[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string tens[9] = {"", "twen", "thir", "for", "fif", "six", "seven", "eigh", "nine"};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    if(n == 0) return cout<<"zero", 0;
    if(n == 11) return cout<<"eleven", 0;
    else if(n == 12) return cout<<"twelve", 0;
    else if(n == 10) return cout<<"ten", 0;
    else if(n == 14) return cout<<"fourteen", 0;

    int digit = n % 10, tenplace = n / 10;

    if(!tenplace) cout<<ones[digit - 1];
    else if(tenplace == 1) cout<<tens[digit - 1]<<"teen";
    else{
        cout<<tens[tenplace - 1]<<"ty";
        if(digit) cout<<'-'<<ones[digit - 1];
    }
    return 0;
}