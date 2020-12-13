/*
    
    Note        :   		Solved with Sparse Table. 

    Link        :       	https://drive.google.com/file/d/17bs-SaJQAMTvUBoqJTS9QMnnUoBeOBo0/view?usp=sharing

    Boka hoye gelum...
*/
#include "bits/stdc++.h"

#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end() 
#define pii pair<int,int> 


using namespace std;
using ll = long long;
using ld = long double;

const ll mod = 100000000;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;

int ar[500005][20];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/
    ll n,q,ans = 0; cin>>n>>q;
    for(int i = 0; i < n; i++) cin>>ar[i][0];
    for(int j = 1; j < 20; j++){
        for(int i = 0; i + (1<<j) <= n; i++){
            ar[i][j] = __gcd(ar[i][j-1],ar[i + (1<< (j -1))][j-1]);
        }
    }
    int lg = log2(q);
    for(int i = 0; i < (n - q) + 1; i++){
        int end = (i + q) - 1;
        //cout<<ar[i][lg] sp<<ar[end - lg][lg] el;
        ans += __gcd(ar[i][lg],ar[end - (1<<lg) + 1][lg]);
    }
    cout<<ans el;
    return 0;
}