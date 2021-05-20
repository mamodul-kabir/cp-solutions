/*
    
    Note        :       1. prime factorize C and find the power of the primes.
                        2. for each prime factor of C, find the highest power of that prime that has a divisor in the range A....B
                        3. for each prime, divide the highest power(from #2) in range by the power in of that prime in C (from #1).
                        4. The answer is the minimum result found in #3.
                        
                        Got a few TLE for not using __int128_t for multiplications. 
    
    Link        :       https://toph.co/p/big-lcm
 
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
 
const ll mod = 1000000007;
const ll si = 200005;
const ll lim = 1000000000000000000; 

struct Pdi
{
    vector<ll> div,fin; 
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
    void factorize(ll n){
        if(n == 1) return; 
        if(MRbin(n)){
            div.pb(n); 
            return; 
        }
        ll d = rho(n); 
        factorize(d); 
        factorize(n/d); 
        return; 
    }
    void refine(){
        sort(all(div)); 
        fin.pb(div[0]); 
        ll sz = div.size(); 
        for(int i = 1; i < sz; i++){
            if(div[i] != div[i-1]) fin.pb(div[i]); 
        }
        return; 
    }
    Pdi(ll n){
        srand(time(0)); 
        factorize(n); 
        refine(); 
    }
    void reset(ll n){
        div.clear(); fin.clear(); 
        factorize(n); 
        refine(); 
    }
    void show(){
        for(ll r: fin) cout<<r sp; cout el; 
    }
};

Pdi di(2); 

int mrd(ll a){
    __int128_t x = a; 
    int p = 0; 
    while(x <= lim){
        x *= a; 
        p += 1; 
    }
    return p; 
}

bool in(ll a,ll b,ll cn){
    ll d = b/cn, num = d * cn; 
    return a <= num; 
}

int get_hp(ll a,ll b,ll c){
    ll li = mrd(c), cur = 1, pw = 0,ans = 0; 
    for(int i = 1; i <= li; i++){
        cur *= c; 
        if(in(a,b,cur)) ans = i; 
    }
    return ans; 
}

void f_ex(ll a,vector<ll> &f, vector<ll> &pw){
    for(ll r: f){
        int p = 0; 
        while(a % r == 0){
            a /= r; 
            p += 1; 
        }
        pw.pb(p); 
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
    int t; cin>>t; 
    while(t--){
        ll a,b,c; cin>>a>>b>>c; 
        di.reset(c); 
        vector<ll> fct,pw,pos; 
        for(ll r: di.fin) fct.pb(r); 
        f_ex(c,fct,pw); 
        for(ll r: fct) pos.pb(get_hp(a,b,r));
        ll sz = fct.size(),ans = 666; 
        for(int i = 0; i < sz; i++){
            ans = min(ans,pos[i]/pw[i]); 
        }
        cout<<ans el; 
    }
    return 0;
}
