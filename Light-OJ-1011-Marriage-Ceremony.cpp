/*
    
    Note        :       Not OC. 
    
                        Had to learn bitmask dp for this.
                        and also took the help from an almost similar problem. 
                        https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/tutorial/
                 

    Link        :       http://lightoj.com/volume_showproblem.php?problem=1011
    
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
const ll oo = 3372036000000000;
const ll si = (1<<16);

ll mamo[si],ar[16][16];

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
    	int n; cin>>n;
    	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin>>ar[i][j];
    	fill(mamo,mamo+si,-2000000000);
    	mamo[0] = 0;
    	int lim = 1<<n;
    	for(int i = 0; i < lim; i++){
    		for(int j = 0; j < n; j++){
    			int x = __builtin_popcount(i);
    			if(!(i & (1<<j))){
    				mamo[i | (1<<j)] = max(mamo[i | (1<<j)],mamo[i] + ar[x][j]);
    			}
    		}
    	}
    	cout<<"Case "<<t<<": "<<mamo[lim-1] el;
    }
    return 0;
}
