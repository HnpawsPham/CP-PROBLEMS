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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    node tmp = head;
    int n = 0;
    while(tmp != nullptr){
        tmp = tmp->next;
        n++;
    }       

    if(n == 1) return nullptr;

    tmp = head;
    for(int i = 0; i < n / 2 - 1; i++)
        tmp = tmp->next;
    node x = tmp->next;

    if(x != nullptr)
        tmp->next = x->next;
    else tmp->next = nullptr;
    return 0;
}