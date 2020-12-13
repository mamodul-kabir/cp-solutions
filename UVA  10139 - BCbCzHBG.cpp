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
#define pii pair<ll,ll> 


using namespace std;
using ll = long long;
using ld = long double;

const ll mod = 100000000;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;

vector<pii> fun(ll n){
    vector<pii> ans;
    int cnt = 0;
    while(!(n % 2)){
        n /= 2;
        cnt +=1;
    }
    if(cnt > 0) ans.pb({2,cnt});
    for(int i = 3; i * i <= n; i += 2){
        cnt = 0;
        while(!(n % i)){
            n /= i;
            cnt += 1;
        }
        if(cnt > 0) ans.pb({i,cnt});
    }
    if(n > 1) ans.pb({n,1});
    return ans;
}

ll binex(ll a, ll b){
    ll ans = 1;
    while(b > 0){
        if(b&1) ans *= a;
        a *= a;
        b /= 2;
    }
    return ans;
}

bool solve(ll n,ll m){
    vector<pii> dnp = fun(m);
    for(auto r: dnp){
        ll pw = 0;
        for(int i = 1; i < 31; i++){
            ll num = binex(r.F,i);
            if(num > n) break;
            pw += n/num;
        }
        if(pw < r.S) return false;
    }
    return true;
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
    ll n,m; 
    while(cin>>n>>m){
        if(n == 0) m == 1 ? cout<<"1 divides 0!" el : cout<<m<<" does not divide 0!" el;
        else if(m == 0) cout<<"0 divides "<<n<<"!\n";
        else solve(n,m) ? cout<<m sp<<"divides" sp<<n<<"!\n" : cout<<m sp<<"does not divide "<<n<<"!\n";
    }
    return 0;
}