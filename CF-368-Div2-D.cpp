/*
    
    Note        :       My first persistent segtree problem. 
 
    Link        :       https://codeforces.com/contest/707/problem/D
 
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
 
const ll mod = 10000007;
const ll oo = 100000000099999;
const ll si = 10000007;

ll ful = (1LL<<50) - 1, brk,n,m,q; 

struct row{
    ll lin[21],col = m,tot;  
    row(){
        tot = 0; 
        memset(lin,0,sizeof(lin)); 
    }
    row(ll *ar, ll nt) : tot(nt){
        for(ll i = 0; i < 21; i++) lin[i] = ar[i]; 
    }
    row update(ll type,ll d){
        if(type == 1) return on(d); 
        else if(type == 2) return off(d); 
        else return inv(); 
    }
    row off(ll x){
        row res(lin,tot);  
        ll b = (x/50), m = x % 50;
        if(lin[b] & (1LL<<m)){
            res.lin[b] = lin[b] ^ (1LL<<m); 
            res.tot = tot - 1;
        }
        return res; 
    }
    row on(ll x){
        row res(lin,tot); 
        ll b = (x/50), m = x % 50;
        if(!(lin[b] & (1LL<<m))){
            res.lin[b] = lin[b] ^ (1LL<<m); 
            res.tot = tot + 1;
        }
        return res;  
    }
    row inv(){
        ll i,j; 
        row res(lin,tot); 
        for(i = 0, j = col; j - 50 >= 0 && i < 21; j -= 50, i++) res.lin[i] = lin[i] ^ ful; 
        if(j > 0) res.lin[i] = lin[i] ^ brk; 
        res.tot = col - tot; 
        return res; 
    }
}; 
 
struct str{
    row bok; 
    str *le, *ri; 
    ll prs; 
    str(ll x = 0, str* l = NULL, str *r = NULL): prs(x), le(l), ri(r) {}
    void bld(ll l,ll r){
        if(l == r) return; 
        le = new str(); 
        ri = new str(); 
        ll mid = l + (r - l)/2; 
        le -> bld(l,mid); 
        ri -> bld(mid+1,r); 
        return; 
    }
    str *upd(ll l,ll r,ll x, ll y,ll typ){
        if(x < l || x > r) return this; 
        if(l == r){
            str *res = new str(); 
            res -> bok = bok.update(typ,y);
            res -> prs = res -> bok.tot; 
            return res;  
        }
        ll mid = l + (r - l)/2; 
        str *res = new str(); 
        res -> le = le -> upd(l,mid,x,y,typ); 
        res -> ri = ri -> upd(mid+1,r,x,y,typ); 
        res -> prs = res -> le -> prs + res -> ri -> prs; 
        //if(l == 0 && r == n - 1) cout<<res -> prs el; 
        return res; 
    }
} *head[100002]; 

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/ 
    cin>>n>>m>>q; 
    brk = (1LL<<(m % 50)) - 1;
    ll up = 1; 
    head[0] = new str();
    head[0] -> bld(0,n-1);   
    while(q--){
        ll type; cin>>type; 
        if(type == 4){
            ll gen; cin>>gen; 
            head[up] = head[gen];  
        }else{
            ll l,r = -1; cin>>l; 
            if(type != 3) cin>>r; 
            l -= 1; r -= 1; 
            head[up] = head[up - 1] -> upd(0,n-1,l,r,type); 
        }
        cout<<head[up++] -> prs el;
    }
    return 0;
}
