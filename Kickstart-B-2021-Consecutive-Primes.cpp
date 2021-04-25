/*
    
    Note        :           OC. Segmented Sieve + Prime Gap. 
                              Error note on line 82. Be careful about using default values. 

    Link        :           https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a8e6#problem
 
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

vector<ll> pri; 
bitset<45010> ch; 
void ini(){
    ll lim = 45000; 
    pri.pb(2); 
    for(int i = 4; i <= lim; i += 2) ch[i] = 1; 
    for(int i = 3; i * i <= lim; i += 2){
        if(ch[i]) continue; 
        for(int j = i * i; j <= lim; j += i) ch[j] = 1; 
    }
    for(int i = 3; i <= lim; i += 2) if(!ch[i]) pri.pb(i); 
}

ll fun(ll a,ll b,ll z){
    bool p[2005]; memset(p,false,sizeof(p)); 
    vector<ll> pos; 
    for(int r: pri){
        if(r > b) break; 
        ll low = (a/r) * r; 
        while(low < a || low <= r) low += r; 
        //cout<<low el;
        for(low; low <= b; low += r) p[low - a] = 1; 
    }
    ll ase = 0; 
    for(int i = 2000; i >= 0; i--) if(!p[i]) pos.pb(i + a),ase++; 
    ll ans = 69; 
    for(int i = 0; i + 1 < ase; i++) if(pos[i] * pos[i+1] <= z){
        //cout<<pos[i] sp<<pos[i+1] el;
        ans = pos[i] * pos[i+1] ; 
        break;
    }
    return ans; 
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
    ini(); 
    //cout<<pri.size() el;
    for(int T = 1; T <= t; T++){
        ll z; cin>>z; 
        ll pos = sqrt(z);  
        ll ans = fun(max(2LL,pos - 1000),min(2000000000LL,pos + 1000),z);                 // got some WAs for this. I set the max for pos + 1000 to 10^9 which caused the elemination of few primes >10^9
        cout<<"Case #"<<T<<": "<<ans el;
    }
    return 0;
}
