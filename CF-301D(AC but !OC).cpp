/*
    
    Note        :           Tried MO's algo and got TLE. Not OC. 
 
    Link        :           https://codeforces.com/contest/301/problem/D
                            TLE submission with MO's algo:      https://github.com/Mahmudul-Kabir/cp-solutions/blob/main/CF-301D(TLE).cpp
 
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
const ll oo = 3372036000000000;
const ll si = 300005;

const ll bsi = 200005; // array size
class BIT{
private: 
    ll n = 200000,ftr[bsi]; 

public: 
    BIT(){
        memset(ftr,0,sizeof(ftr)); 
    }
    void add(int x){
        while(x <= n){
            ftr[x] += 1; 
            x += x & (-x); 
        }
    }
    ll get(int x){
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

struct que{
    int x,l,r,s,i; 
    bool operator<(que ono){
        return x < ono.x; 
    }
}; 

BIT f; 
int id[bsi];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/
    int n,m; cin>>n>>m; memset(id,0,sizeof(id)); 
    for(int i = 1; i <= n; i++){
        int x; cin>>x; 
        id[x] = i; 
    }
    vector<pii> v; 
    vector<que> qq; 
    int g = 0; 
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i){
            g += 1; 
            if(id[i] > id[j]) v.pb({id[j],id[i]}); 
            else v.pb({id[i],id[j]}); 
        }
    }
    int ans[m]; memset(ans,0,sizeof(ans)); 
    for(int i = 0; i < m; i++){
        int l,r; cin>>l>>r; 
        qq.pb({l-1,l,r,-1,i}); qq.pb({r,l,r,1,i}); 
    }
    sort(all(v)); 
    sort(all(qq)); 
    for(int i = 0, j = 0; i < (2 * m); i += 1){
        while(j < g && v[j].F <= qq[i].x) f.add(v[j].S),j++; 
        ans[qq[i].i] += (f.get(qq[i].l,qq[i].r) * qq[i].s); 
    }
    for(int i = 0; i < m; i++) cout<<ans[i] el;
    return 0;
}
