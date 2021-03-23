/*
    
    Note        :       *print the value from 0 to 100 to see the value of f(i), you will see a pattern. 
                         solve it according to the pattern. 
 
    Link        :       https://toph.co/c/father-timm-memorial-1-0
                        //C. I Dont Like Polynomial
 
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
const ll ms = 4; 
const ll oo = 3372036000000000;
const ll si = 1000006;

struct Mat{
    ll a[ms][ms]; 
    Mat(){
        memset(a,0,sizeof(a)); 
    }
    Mat(bool x){
        memset(a,0,sizeof(a)); 
        a[0][0] = a[0][1] = a[3][0] = a[1][1] = a[2][2] = a[3][3] = 1; 
        a[1][2] = 2;  
    }
    Mat operator *(Mat other){     //ms^3 
        Mat res; 
        for(ll i = 0; i < ms; i++){
            for(ll j = 0; j < ms; j++){
                for(ll k = 0; k < ms; k++){
                    res.a[i][j] = (res.a[i][j] + ((a[i][k] * other.a[k][j]) % mod)) % mod;   
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

void mulmain(ll *ar,Mat &r){
    ll tem[4]; memset(tem,0,sizeof(tem)); 
    for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++){
        tem[i] = (tem[i] + (ar[j] * r.a[i][j])) % mod;
    }
    for(int i = 0; i < 4; i++) ar[i] = tem[i]; 
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
    int t; cin>>t; 
    while(t--){
        ll n, tem = 0; cin>>n; 
        if(n%2 == 0){
            __int128_t nx = (n + 4)/2;                  //used long long for the first try and got the WA for that reason. 
            __int128_t big = (nx * nx)/4; 
            tem = big % mod;
        }else n += 1; 
        n /= 2; 
        ll k1 = (n/2) + (n % 2), k2 = n/2; 
        ll a[4],b[4]; 
        a[2] = b[2] = 1; a[3] = b[3] = 0; 
        a[0] = 1; a[1] = 3; 
        b[0] = 2; b[1] = 4; 
        Mat tbx(1); 
        while(k1 || k2){
            if(k1 % 2) mulmain(a,tbx); 
            if(k2 % 2) mulmain(b,tbx); 
            tbx = tbx * tbx; 
            k1 /= 2; 
            k2 /= 2; 
        }
        //cout<<a[3] + b[3] el;
        ll ans = (a[3] + b[3]) % mod;
        ans = (ans * 2) % mod;
        ans = (ans + tem) % mod;
        cout<<ans el;
    }
    return 0;
}
