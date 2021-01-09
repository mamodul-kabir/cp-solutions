/*
 
    Note        :        My first OC digit dp. Remembered some parts (last city dimension) from a tutorial. 
                         

    Link        :      https://cses.fi/problemset/task/1690
 
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
const ll si = (1<<20);

ll n,m; 
ll mo[20][si+1],pa[20][20];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/    
    cin>>n>>m;
    memset(pa,0,sizeof(pa));
    memset(mo,0,sizeof(mo));
    for(int i = 0; i < m; i++){
        int a,b; cin>>a>>b;
        a -= 1; b -= 1;
        pa[a][b] += 1;
    }
    int lim = (1<<n);
    mo[0][1] = 1;
    for(int mask = 1; mask < lim; mask += 2){
        for(int j = 0; j < n; j++){
            if(mask & (1<<j)){
                for(int i = 0; i < n; i++){
                    if(!(mask & (1<<i)) && pa[j][i] > 0){
                        mo[i][mask | (1<<i)] = (mo[i][mask | (1<<i)] + ((mo[j][mask] * pa[j][i]) % mod)) % mod;
                    }
                }
            }
        }
    }
    cout<<mo[n-1][lim-1] el;
    return 0;
}
