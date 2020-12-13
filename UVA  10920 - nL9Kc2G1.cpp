/*
    
    Note        :   

    Link        :       

    Boka hoye gelum...
*/
#include "bits/stdc++.h"

#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end() 
#define pii pair<int,int> 


using namespace std;
using ll = long long;
using ld = long double;

const ll mod = 100000000;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;

bool sb(ll i){
    ll sr = sqrt(i);
    sr *= sr;
    return i == sr;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/
    ll s,i; 
    while(cin>>s>>i){
        if(s == i && i == 0) break;
        ll x,y,ns = sqrt(i);
        if(sb(i)){
            if(ns&1) x = y = ns;
            else x = y = 1;
        }else{
            ll ps = ns, pos = i - (ps * ps); ns += 1;
            if(ns&1){
                x = min(ns,pos);
                y = max(1LL,(pos - x) + 1);
            }else{
                x = max(0LL,ns - pos) + 1;
                y = ns - max(0LL,pos - ns);
            }
        }
        ll rem = s - ns;
        if(rem&1) y += 1;
        rem /= 2;
        x += rem;
        y += rem;
        cout<<"Line = "<<y<<", column = "<<x<<".\n";
    }
    return 0;
}