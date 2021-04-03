/*
    
    Note        :       find the xor sum of the range and use digit dp of their binary representation to find the number of valid M(s). If there is at least one M, then YES else NO. 
 
    Link        :       https://toph.co/c/operation-coding //B. XOR-paro? 
 
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
 
const ll mod = 1000000007;
const ll ms = 200; 
const ll oo = 3372036000000000;
const ll si = 200005;

ll cxr(ll n){
    ll md = n % 4;
    if (md == 0) return n;
    else if (md == 1) return 1;
    else if (md == 2) return n + 1;
    else return 0;
}

ll get(ll a,ll b){
    return (cxr(b) ^ cxr(a-1)); 
}

vector<int> di; 
ll mamo[55][2][2],n,xr; 

ll dp(int i,bool bs,bool f){
    if(i == n) return bs; 
    if(mamo[i][bs][f] == -1){
        ll ans = 0,j = n - i - 1; 
        int lim = f ? di[i] : 1; 
        lim = (bs || (xr & (1LL<<j))) ? lim : 0; 
        for(int r = 0; r <= lim; r++){
            bool nf = f && (di[i] == r), nb = bs || ((xr & (1LL<<j)) && (r == 1)); 
            ans += dp(i+1,nb,nf); 
        }
        mamo[i][bs][f] = ans; 
    }
    return mamo[i][bs][f]; 
}

ll do_dp(ll a){
    di.clear(); ll x = a; 
    n = 0; 
    while(x){
        di.pb(x % 2); 
        x /= 2;
        n += 1;  
    }
    reverse(all(di)); 
    memset(mamo,-1,sizeof(mamo)); 
    return dp(0,0,1); 
} 

bool do_dp(ll l,ll r){
    ll np = do_dp(r) - do_dp(l-1); 
    if(np) return 1; 
    return 0; 
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
    int t; cin>>t; 
    while(t--){
        ll l,r; cin>>l>>r; 
        xr = get(l,r); 
        if(do_dp(l,r)) cout<<"YES" el; 
        else cout<<"NO" el;
    }
    return 0;
}
