/*
    
    Note        :           Important part here is the use of istringstream

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
#define pii pair<ll,ll> 
 
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 1000000009;
const ll ms = 200; 
const ll oo = 337203600000000000;
const ll si = 10005;


vector<pii> g[si]; 
ll dis = 0, dnode = -1; 

void clear(){
    for(int i = 1; i <= 10000; i++) g[i].clear(); 
}

void dfs(ll v,ll p,ll lvl){
    if(lvl > dis){
        dis = lvl; 
        dnode = v;
    } 
    for(pii r: g[v]){
        if(r.F == p) continue; 
        dfs(r.F,v,lvl + r.S); 
    }
    return; 
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
    string s; 
    while(getline(cin,s)){
        clear(); 
        ll p,q,r; istringstream pasa(s); 
        pasa>>p>>q>>r; 
        g[p].pb({q,r}); 
        g[q].pb({p,r}); 
        while(getline(cin,s)){
            if(s == "") break; 
            ll a,b,c; 
            istringstream iss(s) ;
            iss>>a>>b>>c;  
            g[a].pb({b,c}); 
            g[b].pb({a,c}); 
        }
        dis = 0; 
        dfs(1,0,0); 
        dis = 0; 
        dfs(dnode,0,0); 
        cout<<dis el;
    }
    return 0;
}
