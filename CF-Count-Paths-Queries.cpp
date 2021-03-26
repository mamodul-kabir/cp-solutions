/*
    
    Note        :       Precomputation was my own idea. But had to take a hint for the part of considering only the array. 
 
    Link        :       https://codeforces.com/gym/102644/problem/I
 
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
const ll ms = 200; 
const ll oo = 3372036000000000;
const ll si = 1000006;

struct Mat{
    ll a[ms][ms]; 
    Mat(){
        memset(a,0,sizeof(a)); 
    }
    Mat operator *(Mat other){     //ms^3 
        Mat res; 
        for(ll i = 0; i < ms; i++){
            for(ll j = 0; j < ms; j++){
                for(ll k = 0; k < ms; k++){
                    res.a[i][j] = (res.a[i][j] + (a[i][k] * other.a[k][j])) % mod;   
                }
            }
        }
        return res; 
    }
    Mat operator +(Mat other){   //ms^2 
        Mat res; 
        for(ll i = 0; i < ms; i++){
            for(ll j = 0; j < ms; j++){
                res.a[i][j] = (a[i][j] + other.a[i][j]); 
            }
        }
        return res;
    }
};

int n,m,q; 
Mat ar[30]; 


void mul(ll *vec,int p){
    ll nw[n]; memset(nw,0,sizeof(nw)); 
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        nw[i] = (nw[i] + (vec[j] * ar[p].a[j][i])) % mod; 
    }
    for(int i = 0; i < n; i++) vec[i] = nw[i];  
    return; 
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
    cin>>n>>m>>q; 
    Mat mn; 
    for(int i = 0; i < m; i++){
        int a,b; cin>>a>>b; a -= 1; b -= 1; 
        mn.a[a][b] += 1; 
    }
    ar[0] = mn; 
    for(int i = 1; i < 30; i++){
        mn = mn * mn; 
        ar[i] = mn; 
        //for(int i = 0; i < n; i++,cout el) for(int j = 0; j < n; j++) cout<<mn.a[i][j] sp; cout el;
    }
    while(q--){
        int a,b,k; cin>>a>>b>>k; a -= 1; b -= 1; 
        ll ans[n]; bool pos = 1;  
        for(int p = 0; p < 30; p++){
            if(k & (1<<p)){
                if(pos){
                    pos = 0; 
                    for(int k = 0; k < n; k++) ans[k] = ar[p].a[a][k]; 
                }else{
                    mul(ans,p);
                } 
            }
        }
        cout<<ans[b] el; 
    }
    return 0;
}
