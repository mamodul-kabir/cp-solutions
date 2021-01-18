/*
 
    Note        :        OC bitmask solution. CPU time: 1150 ms

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
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
const ll si = (1<<10);

int mamo[si][1001],d,n,lim,c[10],tbd;
vector<int> di;
int dp(int mask,int rem){
    if(mask == lim - 1){
        return !(rem);
    }
    if(mamo[mask][rem] == -1){
        int ans = 0;
        for(int i = 0; i < n; i++) if(!(mask & (1<<i))){
            int nre = ((rem * 10) + di[i]) % d;
            ans += dp(mask | (1<<i),nre);
        }
        mamo[mask][rem] = ans;
    }
    return mamo[mask][rem];
}

int fac(int a){
    int ans = 1;
    for(int i = 1; i <= a; i++) ans *= i;
    return ans;
}

int fun(){
    int ans = 1;
    for(int i = 0; i <= 9; i++) ans *= fac(c[i]);
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
    int T; cin>>T;
    for(int t = 1; t <= T; t++){
        string s; cin>>s>>d;
        di.clear();
        n = s.size();
        lim = (1<<n);
        memset(c,0,sizeof(c)); memset(mamo,-1,sizeof(mamo));
        for(char r: s){
            di.pb(r - '0');
            c[r - '0']++;
        }
        tbd = fun();
        int ans = dp(0,0);
        ans /= tbd;
        cout<<"Case "<<t<<": "<<ans el;
    }
    return 0;
}
