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

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	ll n, m; cin >> n >> m;
	vector<vector<ll>> v(m);
	
	zep(i, 0, n){
		ll s, r; cin >> s >> r;
		s--;
		v[s].push_back(r);
	}

	ll ans[n]; memset(ans, 0, sizeof(ans));

	zep(j, 0, m){
		sort(v[j].begin(), v[j].end(), greater<>());
		//print(v[j].size())
		zep(i, 0, v[j].size()){
			if(i != 0){
				v[j][i] += v[j][i - 1];
			}
			//print(v[j][i])
			if(v[j][i] > 0)ans[i] += v[j][i];
		}
	}
	//printa(ans, 1, n)
	ll res = 0;
	zep(i, 0, n){
		res = max(res, ans[i]);
	}
	print(res)
	
	return 0;
}