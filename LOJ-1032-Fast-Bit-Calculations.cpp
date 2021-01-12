/*
 
    Note        :        It's digit dp, but for binary numbers. 

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
const ll si = (1<<21);

ll mamo[32][32][2][2],l;
vector<int> bin;

ll dp(int i, int re, bool p, bool f){
    if(i == l) return re;
    if(mamo[i][re][p][f] == -1){
        ll ans = 0, lm = f ? bin[i] : 1;
        for(int r = 0; r <= lm; r++){
            int nre = re + (p & r); 
            ans += dp(i+1,nre,r,f && r == bin[i]);
        }
        mamo[i][re][p][f] = ans;
    }
    return mamo[i][re][p][f];
}

ll do_dp(int x){
    memset(mamo,-1,sizeof(mamo));
    bin.clear();
    while(x){
        bin.pb(x%2);
        x /= 2;
    }
    reverse(all(bin));
    l = bin.size();
    return dp(0,0,0,1);
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
        int x; cin>>x;
        cout<<"Case "<<t<<": "<<do_dp(x) el;
    }
    return 0;
}
