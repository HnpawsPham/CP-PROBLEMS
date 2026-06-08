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

int tc = 1;

char sol(){
    int head1, head2, z1, z2;
    cin>>head1>>z1>>head2>>z2;

    int len1 = 0, len2 = 0;
    int tmp = head1;
    while(tmp > 0){
        len1++;
        tmp /= 10;
    }

    tmp = head2;
    while(tmp > 0){
        len2++;
        tmp /= 10;
    }

    if(len1 + z1 > len2 + z2) return '>';
    else if(len1 + z1 < len2 + z2) return '<';

    while(len1 < len2){
        len1++;
        head1 *= 10;
    }

    while(len2 < len1){
        len2++;
        head2 *= 10;
    }

    if(head1 > head2) return '>';
    else if(head1 < head2) return '<';
    return '=';
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}