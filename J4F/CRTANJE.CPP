#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;
string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    int cntp = 0, cntm = 0;
    for(char x : s){
        cntp += (x == '+');
        cntm += (x == '-');
    }

    int m = 2 * n + 1;
    char a[m][n];

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) a[i][j] = '.';

    int i = n;
    for(int j = 0; j < n; j++){
        if(s[j] == '=') a[i][j] = '_';
        else if(s[j] == '+') {
            a[i][j] = '/';
            i--;
        }
        else{
            i++;
            a[i][j] = '\\';
        }
    }
    
    for(int i = 0; i < m; i++){
        bool ok = 0;
        for(int j = 0; j < n; j++)
            if(a[i][j] != '.'){
                ok = 1;
                break;
            }

        if(!ok) continue;
        for(int j = 0; j < n; j++) cout<<a[i][j];
        cout<<el;
    }
    return 0;
}

// 6
// --+++-

// 7
// ---+++-