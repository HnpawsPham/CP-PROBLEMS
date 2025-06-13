#include <iostream>
using namespace std;
#define el "\n"

int t;
string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>s;
        int n = s.length();
        int pi[n + 1] = {0}, pu[n + 1] = {0};

        for(int i = 0; i < n; ++i){
            pi[i + 1] = pi[i] + (s[i] == 'I');
            pu[i + 1] = pu[i] + (s[i] == 'U');
        }

        bool ok = 0;
        for(int i = 0; i < n - 2; ++i){
            int j = i + 2;
            int cnti = pi[j + 1] - pi[i];
            int cntu = pu[j + 1] - pu[i];

            if(cnti != cntu && min(cnti, cntu) > 0){
                cout<<"Yes "<<i + 1<<" "<<j + 1<<el;
                ok = 1;
                break;
            }
        }
        if(!ok) cout<<"No"<<el;
    }

    return 0;
}