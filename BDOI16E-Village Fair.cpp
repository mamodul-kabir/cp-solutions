/*
    
    Note        :           venice technique and dsu on tree. 
 
    Link        :           https://www.spoj.com/problems/BDOI16E/
 
    Boka hoye gelum...
*/

#include "bits/stdc++.h"

#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end() 
#define pii pair<ll ,ll > 

 
using namespace std;
using ll = long long; 
using ld = long double;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const ll mod = 100000000007;
const ll si = 100005;
const ll inf = 7000; 

ll n,head; 
vector<ll> in, g[si], chn, sz, bc, ans; 
unordered_set<ll> man; 
bitset<si> bon; 

void dfs(int u,int val){
    in[u] += val; 
    sz[u] = 1; 
    int big = 0; 
    for(int r: g[u]){
        dfs(r,val + chn[r]);
        sz[u] += sz[r]; 
        if(sz[r] > big){
            big = sz[r]; 
            bc[u] = r; 
        }
    } 
    return; 
}

void add(int v){
    man.insert(in[v]); 
    for(int r: g[v]) if(!bon[r]) add(r); 
}

void dasu(int v,bool clear){
    for(int r: g[v]) if(r != bc[v]) dasu(r,1);
    if(bc[v] != -1){
        dasu(bc[v],0); 
        bon[bc[v]] = 1; 
    }
    add(v); 
    ans[v] = man.size(); 
    if(bc[v] != -1) bon[bc[v]] = 0;
    if(clear) man.clear(); 
    return; 
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/ 
    cin>>n; 
    ans.resize(n+1); 
    in.resize(n+1); sz.resize(n+1); bc.assign(n+1,-1); 
    chn.resize(n+1); 
    for(int i = 1; i <= n; i++) cin>>in[i]; 
    for(int i = 1; i <= n; i++){
        int x; cin>>x; 
        if(x == 0) head = i; 
        else g[x].pb(i); 
    }
    for(int i = 1; i <= n; i++) cin>>chn[i]; 
    dfs(head,0); 
    dasu(head,1); 
    for(int i = 1; i <= n; i++) cout<<ans[i] el; 
    return 0;
}
