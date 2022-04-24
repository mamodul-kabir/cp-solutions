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
 
const ll mod = 1000000007;
const ll oo = 3372036000000000;
const ll si = 100005;
 
ll mao[100001][4][4][4][4],n; 
string s; 
vector<int> man;  
 
ll point(ll a,ll b,ll c){
    ll ans = 3; 
    if(a == 0 || b == 0){
        if(a == 0) ans--; 
        if(b == 0) ans--; 
        if(b == c) ans--; 
        return ans; 
    }
    if(a == b && b == c) ans = 1; 
    else if(a == b) ans = 2; 
    else if(a == c) ans = 2; 
    else if(b == c) ans = 2; 
    return ans; 
}
 
ll dp(ll i, ll a1, ll a2, ll b1, ll b2){
    if(i == n) return 0; 
    if(mao[i][a1][a2][b1][b2] == -1){
        ll ans = 0, x = man[i]; 
        ans = max(dp(i + 1, a2, x, b1, b2) + point(a1,a2,x), dp(i + 1, a1, a2, b2, x) + point(b1,b2,x));
        mao[i][a1][a2][b1][b2] = ans;
    }
    return mao[i][a1][a2][b1][b2]; 
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/ 
    cin>>n>>s;  
    for(char r: s){
        if(r == 'F') man.pb(1); 
        else man.pb((r == 'M' ? 2 : 3)); 
    }  
    memset(mao,-1,sizeof(mao)); 
    cout<<dp(0,0,0,0,0) el;
    return 0;
}
/*
    check for: 
        *missed a break, continue ? 
        *corner cases, n = 1?
        *overflow.
        *unnecessary logics.
        *impreciseness caused by double or long double. 
 
*/
