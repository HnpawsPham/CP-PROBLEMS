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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    if(n == 1) cout<<"Uphold integrity and ethics throughout the contest.";
    else if(n == 2) cout<<"Do not seek or receive external help from people, platforms, tools or AI.";
    else if(n == 3) cout<<"Follow all ICPC rules and guidelines, accept decisions made by organizers and judges as final.";
    else if(n == 4) cout<<"Show good sportmanship and treat competitors, volunteers, staff and judges with respect.";
    else if(n == 5) cout<<"Compete with creativity and teamwork, honor the contest spirit and pursue excellence.";

    return 0;
}