/*
    
    Note        :           Exponentiation of Matrix of Matrixes. 
                            for a power k, 
                            ans(k) = ans(k-1) + A^k;              //A and ans both are matrix. 
                            _        _   _       _          _     _
                           | idn   idn| | ans(i-1)|        | ans(i)|  
                                                        =                         // idn is identity matrix and nul is null matrix, they are equivanlent of 1 and O consecutively for Matrixs.
                           | null   A | |   A^i   |        |  A^i+1|
                           -          - -         -        -       -
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
 
const ll mod = 10;
const ll ms = 30; 
const ll oo = 3372036000000000;
const ll si = 1000006;


struct Mat{
    ll a[ms][ms]; 
    Mat(){
        memset(a,0,sizeof(a)); 
    }
    Mat(bool x){
        memset(a,0,sizeof(a)); 
        for(int i = 0; i < ms; i++) a[i][i] = 1; 
    }
    Mat operator *(Mat other){
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
    Mat operator +(Mat other){
        Mat res; 
        for(ll i = 0; i < ms; i++){
            for(ll j = 0; j < ms; j++){
                res.a[i][j] = (a[i][j] + other.a[i][j]) % mod; 
            }
        }
        return res;
    }
}; 

Mat tbn[2][2]; 

void exp(){
    Mat tm[2][2]; 
    for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++){
        tm[i][j] = tm[i][j] + (tbn[i][k] * tbn[k][j]); 
    }
    for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++){
        tbn[i][j] = tm[i][j]; 
    }
    return;
}

void mulmain(Mat *ar){
    Mat tm[2]; 
    for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++){
        tm[i] = tm[i] + (tbn[i][j] * ar[j]); 
    }
    ar[0] = tm[0]; 
    ar[1] = tm[1]; 
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
    for(int q = 1; q <= t; q++){
        int n,k; cin>>n>>k; 
        Mat wa(1),mn[2];
        tbn[0][0] = wa; tbn[0][1] = wa; 
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin>>mn[1].a[i][j]; 
        tbn[1][1] = mn[1]; 
        while(k){
            if(k%2) mulmain(mn); 
            exp();  
            //for(int i = 0; i < n; i++,cout el) for(int j = 0; j < n; j++) cout<<tbn[0][1].a[i][j] sp; cout el;
            k /= 2; 
        }
        cout<<"Case "<<q<<":" el;
        for(int i = 0; i < n; i++,cout el) for(int j = 0; j < n; j++) cout<<mn[0].a[i][j]; 
    }
    return 0;
}
