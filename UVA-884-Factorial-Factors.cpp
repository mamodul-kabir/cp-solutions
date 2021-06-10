/*
    
    Note        :           My solution using Pollard-Rho. 
 
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
 
const ll mod = (1<<29);
const ll oo = 100000000099999;
const ll si = 100005;



vector<int> npf(1000006), ppf(1000006); 

ll mul(ll a,ll b,ll md){
    return ((__int128_t) a * b) % md; 
}
ll binex(ll a,ll b,ll md){
    ll ans = 1; 
    while(b){
        if(b%2) ans = mul(ans,a,md); 
        a = mul(a,a,md); 
        b /= 2; 
    }
    return ans; 
}
bool is_com(ll a,ll d,ll md,ll s){
    ll x = binex(a,d,md); 
    if(x == 1 || x == md - 1) return 0; 
    for(int i = 1; i < s; i++){
        x = mul(x,x,md); 
        if(x == md - 1) return 0; 
    }
    return 1; 
}
bool MRbin(ll a){
    if(a < 2) return 0;
    if(a != 2 && a % 2 == 0) return 0;  
    ll s = 0, d = a - 1; 
    while(!(d&1)){
        d >>= 1; 
        s += 1; 
    }
    for(ll r: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if(a == r) return 1; 
        if(is_com(r,d,a,s)) return 0; 
    }
    return 1; 
}
ll f(ll a, ll c,ll md){
    return (mul(a,a,md) + c) % md; 
}
ll rho(ll n){
    if(n % 2 == 0) return 2; 
    ll x0 = (rand() % (n - 1)) + 1, c = (rand() % n) + 1; 
    ll x = x0, y = x0,g = 1; 
    while(g == 1){
        x = f(x,c,n); 
        y = f(y,c,n); 
        y = f(y,c,n); 
        g =  __gcd(abs(x-y),n); 
    }
    return g; 
}
void do_do(ll n){
    if(n == 1) return; 
    if(MRbin(n)){
        npf[n] = 1; 
        return; 
    }
    ll d = rho(n);
    while(d == n) d = rho(n);
    npf[n] = npf[d] + npf[n/d]; 
    return; 
}

void ini(){
    for(int i = 2; i <= 1000000; i++){ 
        do_do(i); 
    }
    for(int i = 2; i <= 1000000; i++){
        ppf[i] = ppf[i-1] + npf[i]; 
    }
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
    ini(); 
    int n; 
    while(cin>>n){
        //cout<<npf[n] el; 
        cout<<ppf[n] el; 
    }
    return 0;
}
