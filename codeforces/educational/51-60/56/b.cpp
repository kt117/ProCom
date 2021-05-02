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
	
	ll t; cin >> t;
	while(t--){
		string s; cin >> s;
		ll n = s.size();

		bool ok = true;
		zep(i, 0, n){
			if(s[i] != s[n - 1 - i]){
				ok = false;
			}
		}
		if(!ok){
			print(s)
			continue;
		}

		bool use[26]; memset(use, 0, sizeof(use));
		zep(i, 0, n)use[s[i] - 'a'] = true;
		
		ll cnt = 0;
		zep(j, 0, 26)if(use[j])cnt++;

		if(cnt <= 1){
			print(-1)
		}else{
			zep(i, 1, n){
				if(s[i] != s[0]){
					char tmp = s[0];
					s[0] = s[i];
					s[i] = tmp;
					break;
				}
			}

			print(s)
		}
	}
	
	return 0;
}