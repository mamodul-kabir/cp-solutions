/*
 
    Note        :         Keep it cool, that's how you do it. 
                          
                          got rid of an extra dimension using difference array. 
                          had a little problem adjusting with mods. 

    Link        :      
 
 
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
const ll si = -2000006;


ll n,k,s,nad[15005],nas[15005],mamo[15005],add[15005],sub[15005],cp;

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
        cin>>n>>k>>s;
        memset(nad,0,sizeof(nad)); memset(add,0,sizeof(add)); memset(nas,0,sizeof(nas));
        memset(mamo,0,sizeof(mamo)); memset(sub,0,sizeof(sub));
        add[0] = 1;
        sub[1] = 1;
        for(int i = 0; i <= n; i++){
            cp = 0;
            for(int r = 0; r <= s; r++){
                cp = (cp + add[r]) % mod;
                cp = (cp - sub[r]) % mod;
                if(cp < 0) cp += mod;
                mamo[r] = cp;
                //cout<<cp sp;
                //cout<<mamo[r] sp;
                if(r + 1 <= s) nad[r+1] = cp;
                if(r + k + 1 <= s) nas[r+k+1] = cp;
                add[r] = nad[r];
                sub[r] = nas[r];
                nad[r] = 0; nas[r] = 0;
            }
        }
        ll ans = mamo[s] % mod;
        cout<<"Case "<<T<<": "<< ans el;
    }
    return 0;
}
