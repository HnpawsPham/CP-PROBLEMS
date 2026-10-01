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

string s;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    int n = s.length();
    int openbrack = -1, closebrack = -1;
    int ficolon = -1, secolon = -1;

    for(int i = 0; i < n; i++){
        if(openbrack == -1 && s[i] == '[')
            openbrack = i;
        if(openbrack != -1 && openbrack < i && s[i] == ':'){
            ficolon = i;
            break;
        }
    }

    for(int i = n - 1; i > ficolon; i--){
        if(closebrack == -1 && s[i] == ']')
            closebrack = i;
        if(closebrack != -1 && i < closebrack && s[i] == ':'){
            secolon = i;
            break;
        }
    }

    if(min(min(ficolon, secolon), min(closebrack, openbrack)) == -1)
        return cout<<-1, 0;

    int del = ficolon - openbrack - 1;
    del += closebrack - secolon - 1;
    for(int i = ficolon + 1; i < secolon; i++)
        if(s[i] != '|') del++;

    cout<<closebrack - openbrack + 1 - del;
    return 0;
}