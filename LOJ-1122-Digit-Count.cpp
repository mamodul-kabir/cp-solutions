/*
 
    Note        :        pretty easy problem. added because fully OC. 

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
 
const ll mod = 100000007;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
const ll si = 1000006;

int n,m; 
vector<int> di;
int mamo[10][10];

ll dp(int i,int las){
    if(i == m) return 1;
    if(mamo[i][las] == -1){
        ll ans = 0;
        if(i == 0) for(int r = 0; r < n; r++) ans += dp(i+1,r);
        else for(int r = 0; r < n; r++) if(abs(di[r] - di[las]) <= 2) ans += dp(i+1,r);
        mamo[i][las] = ans;
    }
    return mamo[i][las];
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
    for(int T = 1; T <= t; T++){
        cin>>n>>m;
        di.clear();
        memset(mamo,-1,sizeof(mamo));
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            di.pb(x);
        }
        sort(all(di));
        ll ans = dp(0,0);
        cout<<"Case "<<T<<": "<<ans el;
    }
    return 0;
}
