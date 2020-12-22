/*
 
    Note        :      This problem is fked up. I got 20+ runtime errors just because I used cin, cout instead of scanf and printf. When I switched and used %I64d type specifier,
                       I got WA. I then switched to %lld then got AC. This is obnoxious. 
 
    Link        :      http://lightoj.com/volume_showproblem.php?problem=1140
 
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
 
ll mamo[15][15][2][2],n;
vector<ll> di;
 
ll dp(int i,int cnt,bool f,bool z){
    if(i == n){
        if(z) return 1;
        return cnt;
    }
    if(mamo[i][cnt][f][z] == -1){
        ll ans = 0,lim = f ? di[i] : 9;
        for(int r = 0; r <= lim; r++){
            bool nf = f && (r == di[i]), nz = z && (r == 0);
            ll nc = cnt;
            if(!z && r == 0) nc = cnt + 1;
            ans += dp(i+1,nc,nf,nz);
        }
        mamo[i][cnt][f][z] = ans;
    }
    return mamo[i][cnt][f][z];
}

ll do_dp(ll a){
	if(a < 0) return 0;
    di.clear();
    while(a > 0){
        di.pb(a % 10);
        a /= 10;
    }
    n = di.size();
    reverse(all(di));
    memset(mamo,-1,sizeof(mamo));
    ll ans = 0;
    ans = dp(0,0,1,1);
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
    int T; scanf("%d",&T);
    for(int t  = 1; t <= T; t++){
        ll a,b,dum; scanf("%lld%lld",&a,&b);
        ll ans = do_dp(b) - do_dp(a - 1);
        //cout<<"Case "<< t <<": "<<ans el;
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
