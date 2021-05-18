/*
    
    Note        :           *seg_tree1 helps to find a valid range for a height.
                            *seg_tree2 helps to find the max coins available in a range.
                            *the set in the first iteration helps to find the groups of same height and add their coins.
                            *'' '' '' second iteration helps to find the right chronological order to find the values and update them without hampering anything. 
    
    Link        :           https://toph.co/p/video-game-pro
 
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
const ll lim = 1024; 
const ll oo = 337203600000000000;
const ll si = 100005;

ll n,m_smol[si],coin[si],hi[si],comb[si]; 
vector<ll> g[30004]; 
ll hold[30004]; 
set<ll> ind; 

ll st1[si * 4],st2[si * 4]; 

void make(int a,int b,int node){
    if(a == b){
        st1[node] = hi[a]; 
        return; 
    }
    int mid = a + (b - a)/2, lef = node * 2; 
    make(a,mid,lef); make(mid+1,b,lef + 1); 
    st1[node] = max(st1[lef],st1[lef + 1]); 
    return; 
}

int get_one(int a,int b,int l,int r,int x,int node,bool bam){
    if(b < l || a > r) return -1; 
    if(a >= l && b <= r){
        if(st1[node] <= x) return -1;
        while(a != b){
            int mid = a + (b - a)/2; 
            int lef = node * 2; 
            if(bam){
            	if(st1[lef + 1] > x){
                    node = lef + 1; 
                    a = mid + 1; 
                }else{
                    node = lef; 
                    b = mid; 
                }
            }else{
                if(st1[lef] > x){
                    node = lef; 
                    b = mid; 
                }else{
                    node = lef + 1; 
                    a = mid + 1; 
                }
            }
        } 
        return a; 
    }
    int mid = a + (b - a)/2, lef = node * 2; 
    int ans = bam ? get_one(mid+1,b,l,r,x,lef+1,bam) : get_one(a,mid,l,r,x,lef,bam);
    if(ans != -1) return ans; 
    return bam? get_one(a,mid,l,r,x,lef,bam) : get_one(mid+1,b,l,r,x,lef+1,bam); 
}

void update(int a,int b,int x, ll val, int node){
    if(a == b){
    	st2[node] = val; 
    	return; 
    } 
    int mid = a + (b - a)/2, lef = node * 2;
    if(x <= mid) update(a,mid,x,val,lef); 
    else update(mid+1,b,x,val,lef+1); 
    st2[node] = max(st2[lef],st2[lef + 1]); 
    return;  
}

ll get_max(int a,int b,int l,int r,int node){
	if(b < l || a > r) return 0; 
    if(a >= l && b <= r) return st2[node]; 
    int mid = a + (b - a)/2, lef = node * 2; 
    return max(get_max(a,mid,l,r,lef),get_max(mid+1,b,l,r,lef + 1)); 
}

ll dp(int i){
	int a = get_one(0,n-1,0,i,hi[i],1,1), b = get_one(0,n-1,i,n-1,hi[i],1,0); 
	if(a == -1 && b == -1){
		a = 0; b = n - 1; 
	}else if(a == -1){
		a = 0; b -= 1; 
	}else if(b == -1){
		b = n - 1; a += 1; 
	}else{
		a += 1; b -= 1; 
	}
	//cout<< i sp<<a sp<<b el;
	ll ans = get_max(0,n-1,a,b,1) + comb[i]; 
	return ans; 
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
    ll t; cin>>t; 
    while(t--){
        cin>>n; 
        for(ll i = 0; i < n; i++) cin>>hi[i]; 
        for(ll i = 0; i < n; i++) cin>>coin[i];  
        memset(m_smol,-1,sizeof(m_smol));
        memset(hold,0,sizeof(hold)); 
        memset(st2,0,sizeof(st2));  
        make(0,n-1,1); 
        for(ll i = 0; i < n; i++){
            ind.insert(hi[i]); 
            hold[hi[i]] += coin[i];
            g[hi[i]].pb(i); 
            vector<ll> tbd;  
            for(ll r: ind){
                if(r >= hi[i]) break; 
                tbd.pb(r); 
                for(ll x: g[r]){
                    comb[x] = hold[r]; 
                }
                g[r].clear(); 
                hold[r] = 0; 
            }
            for(ll r: tbd) ind.erase(r); 
        }
        for(ll r: ind){
            for(ll x: g[r]){
                    comb[x] = hold[r]; 
            }
            g[r].clear(); 
            hold[r] = 0; 
        }
        ind.clear();  
        for(ll i = 0; i < n; i++){
            ind.insert(hi[i]); 
            g[hi[i]].pb(i); 
            vector<ll> tbd;  
            for(ll r: ind){
                if(r >= hi[i]) break; 
                tbd.pb(r); 
                ll ans = -1; 
                bool f = 1; 
                for(ll x: g[r]){
                    if(f){
                        ans = dp(x); 
                        f = 0; 
                    }
                    m_smol[x] = ans; 
                    update(0,n-1,x,ans,1); 
                }
                g[r].clear(); 
            }
            for(ll r: tbd) ind.erase(r); 
        }
        for(ll r: ind){
            ll ans = -1; 
            bool f = 1; 
            for(ll x: g[r]){
                if(f){
                    ans = dp(x); 
                    f = 0; 
                }
                m_smol[x] = ans;
                update(0,n-1,x,ans,1); 
            }
            g[r].clear(); 
        }
        //for(ll i = 0; i < n; i++) m_smol[i] = dp(i); 
        //for(ll i = 0; i < n; i++) cout<<m_smol[i] sp; cout el;
        ll q; cin>>q; 
        while(q--){
            ll x; cin>>x; x -= 1; 
            cout<<m_smol[x] el; 
        }
    }
    return 0;
}
