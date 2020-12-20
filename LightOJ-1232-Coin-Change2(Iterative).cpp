/*
   
    Note        :         I had practiced this problem before, but still it is an OC, right? Gotta do the recursive one by myself. 
                          CPU time        :           0.211 ms
                          
                          Edit:           "𝘛𝘩𝘦𝘳𝘦 𝘪𝘴 𝘯𝘰 𝘳𝘦𝘤𝘶𝘳𝘴𝘪𝘷𝘦 𝘢𝘤𝘤𝘦𝘱𝘵𝘦𝘥 𝘴𝘰𝘭𝘶𝘵𝘪𝘰𝘯"-𝘔𝘰𝘥𝘦𝘳𝘢𝘵𝘰𝘳 𝘴𝘢𝘪𝘥.
                                          link  :  https://codeforces.com/blog/entry/15450
 
    Link        :         http://lightoj.com/volume_showproblem.php?problem=1232
 
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
 
ll ar[101],mamo[10005],n,k;
 
 
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
        cin>>n>>k;
        for(int i = 0; i < n; i++) cin>>ar[i];
        sort(ar,ar+n);
        memset(mamo,0,sizeof(mamo));
        mamo[0] = 1;
        for(int i = 0; i < n; i++){
            for(int r = 0; r + ar[i] <= k; r++){
                if(mamo[r] > 0){
                    mamo[r + ar[i]] = (mamo[r + ar[i]] + mamo[r]) % mod;
                }
            }
        }
        ll ans = mamo[k];
        cout<<"Case "<<t<<": "<<ans el;
    }
    return 0;
}
