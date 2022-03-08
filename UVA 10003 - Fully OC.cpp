/*
    
    Note        :            Knuth Optimization, babyyy
 
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
const ll si = 1000005;

ll dp[52][52], cut[52][52];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/ 
    int l; 
    while(cin>>l){
        if(l == 0) break; 
        int n; cin>>n;  
        int ar[n + 2]; ar[0] = 0; ar[n + 1] = l; 
        for(int i = 1; i <= n; i++) cin>>ar[i];
        for(int i = 0; i < n + 1; i++){
            dp[i][i+1] = 0; 
            cut[i][i+1] = i+1; 
        }
        n += 1; 
        for(int i = 2; i <= n; i++){
            for(int j = 0; i + j <= n; j++){
                int end = i + j; 
                int lb = cut[j][end - 1], rb = cut[j+1][end]; 
                pii ans = {mod,lb}; 
                for(int k = lb; k <= rb; k++) ans = min(ans,{dp[j][k] + dp[k][end],k}); 
                dp[j][end] = ans.F + ar[end] - ar[j];
                cut[j][end] = ans.S; 
                //cout<<j sp<<end sp<<dp[j][end] el; 
            }
        }
        cout<<"The minimum cutting is" sp<<dp[0][n]<<"." el; 
    } 
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
