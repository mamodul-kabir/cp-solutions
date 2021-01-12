/*
 
    Note        :        This is an inefficient solution. To fully understand, please check the efficient one under the same name. 
                         Pragma comments are too much powerful. 
                         
                         CPU time: 957ms

    Link        :      
 
    Boka hoye gelum...
*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

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
const ll si = (1<<21);

ll mamo[200][10][20],m,n,d,ar[200],mar[200];

ll dp(ll i,ll t,ll rem){
    if(t == m) return !(rem);
    if(i == n || (n - i) < (m - t)) return 0;
    if(mamo[i][t][rem] == -1){
        ll ans = 0;
        for(ll r = i; r < n; r++){
            ll nr = (rem + mar[r]);
            if(nr >= d) nr %= d;
            ans += dp(r+1,t+1,nr);
        }
        //if(t > 0) cout<<ar[i] sp<<ans el;
        mamo[i][t][rem] = ans;
    }
    return mamo[i][t][rem];
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
        ll q; cin>>n>>q;
        for(ll i = 0; i < n; i++) cin>>ar[i];
        cout<<"Case "<<t<<":\n";
        for(int i = 0; i < q; i++){
            cin>>d>>m;
            for(int r = 0; r < n; r++){
                int x = ar[r] % d;
                if(x < 0) x = x + d;
                mar[r] = x;
            }
            memset(mamo,-1,sizeof(mamo));
            cout<<dp(0,0,0) el;
        }
    }
    return 0;
}
