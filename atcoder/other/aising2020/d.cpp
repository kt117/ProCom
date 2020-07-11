#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll f(ll x){
	ll res = 0;
	while(__builtin_popcount(x) != 0){
		x %= __builtin_popcount(x);
		res++;
	}
	return res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    string x; cin >> x;
    
    ll cnt = 0; zep(i, 0, n)if(x[i] == '1')cnt++;
    //print(cnt)
    ll LMOD = cnt - 1, RMOD = cnt + 1;
    
    ll fac[n][2], l = 1, r = 1;
    zep(i, 0, n){
    	if(cnt > 1){
    		l %= LMOD; fac[i][0] = l; l *= 2;
    	}
    	r %= RMOD; fac[i][1] = r; r *= 2;
    	//cout << fac[i][0] << " " << fac[i][1] << endl;
    }
    
    ll L = 0, R = 0;
    zep(i, 0, n){
    	if(x[i] == '1'){
    		if(cnt > 1){
    			L += fac[n - 1 - i][0]; L %= LMOD;
    		}
    		R += fac[n - 1 - i][1]; R %= RMOD;
    	}
    }
    //cout << L << " " << R << endl;
    zep(i, 0, n){
    	if(x[i] == '1'){
    		if(cnt > 1){
    			ll q = (L + (LMOD - (fac[n - 1 - i][0] % LMOD))) % LMOD;
    			//cout << i << " " << q << endl;
    			print(f(q) + 1)
    		}else{
    			print(0)
    		}
    	}else{
    		ll q = (R + fac[n - 1 - i][1] % RMOD) % RMOD;
    		print(f(q) + 1)
    	}
    }
    //print(f(3905230))
    //print(3905230 % 14)
    return 0;
}