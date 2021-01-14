/*
 
    Note        :      It was an amazing problem. I tried to solve it with map<double,int> but got TLE. In this problem, the parameters were swiched, THIS IS COMPLETELY NEW for me.
                       sum = sum of money in all banks. 
                       Not OC. 
                       The dp become for i th bank in 0...n-1 banks, for j (0 to sum dollar) find the minimum probability of getting caught.  

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
const ll si = 101;

int mn[si],n,sum;
double mamo[si * si],fin,pr[si];

int dp(){
    for(int i = 0; i <= sum; i++) mamo[i] = 100000000;
    mamo[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = sum; j >= mn[i]; j--){
            mamo[j] = min(mamo[j],mamo[j - mn[i]] + ((1 - mamo[j - mn[i]]) * pr[i]));
        }
    }
    for(int i = sum; i >= 0; i--){
        if(mamo[i] <= fin) return i;
    }
    return 0;
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
    for(int t = 1; t <= T; t++){
        scanf("%lf%d",&fin,&n);
        sum = 0;
        for(int i = 0; i < n; i++) scanf("%d %lf",&mn[i],&pr[i]), sum += mn[i];
        int ans = dp();
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
