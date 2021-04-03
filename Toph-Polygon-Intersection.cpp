/*
    
    Note        :           
 
    Link        :       https://toph.co/c/operation-coding // D. Polygon Intersection
 
    Boka hoye gelum...
*/




#include "bits/stdc++.h"
 
#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end() 
//#define pii pair<ll,ll> 
 
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 1000000007;
const ll ms = 200; 
const ll oo = 3372036000000000;
const ll si = 200005;

ld pi = 3.1415926535897932; 

ld tor(ld a){
    return a * (pi/180); 
}

ld fang(ld n,ld x){
    int side = (int ) n; 
    ld ang = (side - 2) * ((ld) 180/side); 
    ld a = 360 - (ang * 2), b = 180 - a; a /= 2; 
    a = tor(a); b = tor(b); 
    ld k = (x / ((2 * sin(a)) + sin(b))); 
    ld ans = k * sin(b); 
    return ans; 
}

ld area(ld n,ld a){
    ld A = (a * a * n) / (4 * tan((180 / n) * pi / 180));
    return A; 
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
        ld n,s; cin>>n>>s; 
        ld a = fang(2 * n,s); 
        ld fin = area(2 * n,a); 
        cout<<showpoint<<setprecision(10)<<fixed<<fin el;
    }
    return 0;
}
