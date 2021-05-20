/*
                *Take the highest power of the primes in range [1,1000] and merge them till they are not >10^9. 
                *for each query input multiply them to ans (initially set to 1).  

*/


#include "iostream"
#include "vector"

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

const ll mod = 1000000009;
const ll ms = 200;
const ll oo = 3372036000000000;
const ll si = 200005;
const ll lim = 1000000000;

vector<ll> pri = {2,   3,   5,   7,  11,  13,  17,  19,  23,  29,  31,  37,  41, 43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211,
 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313,317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509,
 521, 523, 541, 547, 557, 563, 569,571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643,647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733,739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823,827, 829, 839, 853, 857,
 859, 863, 877, 881, 883, 887, 907, 911,919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
vector<ll> prs,vec;

void ini(){
    for(ll r: pri){
        ll cur = r;
        while(cur * r <= 1000){
            cur *= r;
        }
        //cout<<cur sp<<r el;
        prs.pb(cur);
    }
    ll cur = 1;
    for(int r: prs){
        if(cur * r > lim){
            vec.pb(cur);
            cur = 1;
        }
        cur *= r;
    }
    if(cur != 1) vec.pb(cur);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ini();
    int t; cin>>t;
    while(t--){
        ll ans = 1;
        for(ll r: vec){
            cout<<"?" sp<<r el;
            cout.flush();
            ll gc; cin>>gc;
            ans *= gc;
        }
        cout<<"!" sp<<ans el;
        cout.flush();
    }
    return 0;
}
