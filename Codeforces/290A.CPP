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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    string a[41] = {"", 
        "Washington", "Adams", "Jefferson", "Madison", "Monroe", 
        "Adams", "Jackson", "Van Buren", "Harrison", "Tyler", 
        "Polk", "Taylor", "Fillmore", "Pierce", "Buchanan", 
        "Lincoln", "Johnson", "Grant", "Hayes", "Garfield", 
        "Arthur", "Cleveland", "Harrison", "Cleveland", "McKinley", 
        "Roosevelt", "Taft", "Wilson", "Harding", "Coolidge", 
        "Hoover", "Roosevelt", "Truman", "Eisenhower", "Kennedy", 
        "Johnson", "Nixon", "Ford", "Carter", "Reagan"};

    cout<<a[n];
    return 0;
}