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

ll n, k, a[200010];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> k;
    zep(i, 0, n)cin >> a[i];
    
	if(n == k){
		ll ans = 1;
		zep(i, 0, n){
			ans *= (MOD + a[i]) % MOD; ans %= MOD;
		} 
		print(ans) return 0;
	}

    vector<ll> u, v;
    zep(i, 0, n){
    	if(a[i] > 0){
    		u.push_back(a[i]);
    	}else{
    		v.push_back(-a[i]);
    	}
    }
    
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());
    
	if(k % 2 == 1 && v.size() == n){
		ll ans = 1;
		zep(i, 0, k){
			ans *= MOD - v[i]; ans %= MOD;
		}
		print(ans) return 0;
	}

	ll ans = 1;
	for(ll i = 0; i < k; i++){
		ll U = u.size(), V = v.size();

		if(i == k - 1){
			ans *= u.back(); ans %= MOD; u.pop_back();
			continue;
		}

		if(U < 2 || (V >= 2 && u[U - 1] * u[U - 2] < v[V - 1] * v[V - 2])){
			ans *= ((MOD - v[V - 1]) % MOD * (MOD - v[V - 2]) % MOD) % MOD; ans %= MOD;
			v.pop_back(); v.pop_back();
			i++;
			continue;
		}

		ans *= u.back(); ans %= MOD; u.pop_back();
	}
	
	print(ans)

    return 0;
}
