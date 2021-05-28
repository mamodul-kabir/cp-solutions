/*
    
    Note        :           
 
    Link        :       https://cses.fi/problemset/task/2081
 
    Boka hoye gelum...
*/
#include "iostream"
#include "algorithm"
#include "iomanip"
#include "vector"
#include "set"
#include "sstream"
#include "fstream"
#include "cstring"
#include "stack"
#include "cmath"
#include "utility"
#include "map"
#include "bitset"
#include "cassert"
#include "deque"
 
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
 
const ll mod = 1000000007;
const ll oo = 3372036000000000;
const ll si = 200005;
 
const ll bsi = 200005; // array size
class BIT{
private: 
    ll n = 200001,ftr[bsi]; 
 
public: 
    BIT(){
        memset(ftr,0,sizeof(ftr)); 
    }
    void add(int x,int val){
        x += 1; 
        while(x <= n){
            ftr[x] += val; 
            x += x & (-x); 
        }
    }
    ll get(int x){
        x += 1; 
        if(x <= 0) return 0; 
        ll ans = 0; 
        while(x){
            ans += ftr[x]; 
            x -= x & (-x); 
        }
        return ans; 
    }
    ll get(int a,int b){
        return get(b) - get(a-1); 
    }
};
 
#define vvi vector<vector<ll>> 
 
struct cen_dec{
    vvi &g; 
    ll n,mcen,ans = 0,sol,a,b,mxd;  
    BIT cnt; 
    bitset<si> ded; 
    void dfs(ll v,ll p,vector<ll> &sz){
        sz[v] = 1; 
        for(ll r: g[v]){
            if(r == p || ded[r]) continue; 
            dfs(r,v,sz); 
            sz[v] += sz[r]; 
        }
        return; 
    }
    ll find_cen(ll v, ll p, ll lim, vector<ll> &sz){
        for(ll r: g[v]){
            if(r == p || ded[r]) continue; 
            if(sz[r] > lim) return find_cen(r,v,lim,sz); 
        }
        return v; 
    }
    void count(ll v,ll p,ll dep,bool ad){
        if(dep > b) return; 
        mxd = max(dep,mxd);
        if(ad) cnt.add(dep,1);
        else ans += cnt.get(a-dep,b-dep);
        for(ll r: g[v]){
            if(r == p || ded[r]) continue; 
            count(r,v,dep+1,ad); 
        }
        return; 
    }
    ll decompose(ll root){
        static vector<ll> sz(n); 
        dfs(root,-1,sz);
        ll lim = (sz[root])/2;  
        ll cen = find_cen(root,-1,lim,sz);   
        ded[cen] = 1;
        mxd = 0;
        cnt.add(0,1);
        for(ll r: g[cen]){
            if(!ded[r]){
                count(r,cen,1,0); 
                count(r,cen,1,1);
            }
        }
        for(int i = 0; i <= mxd; i++) cnt.add(i,-cnt.get(i));
        for(ll r: g[cen]){
            if(!ded[r]) decompose(r); 
        }
        return cen; 
    }
    cen_dec(vvi &tree,ll x,ll y) : g(tree){ 
        a = x;
        b = y;   
        n = g.size();   
        mcen = decompose(1); 
        return;  
    }
};
 
vvi g; 
ll n,k1,k2; 
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
/*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/
    cin>>n>>k1>>k2; 
    g.assign(n+1,{}); 
    for(ll i = 1; i < n; i++){
        ll a,b; cin>>a>>b; 
        g[a].pb(b); 
        g[b].pb(a); 
    }
    cen_dec mau(g,k1,k2); 
    cout<<mau.ans el; 
    return 0;
}
