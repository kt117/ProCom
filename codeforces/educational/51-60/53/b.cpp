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
	
	ll n; cin >> n;
	ll a[n]; zep(i, 0, n)cin >> a[i];
	ll b[n]; zep(i, 0, n)cin >> b[i];

	ll ra[n + 1]; zep(i, 0, n)ra[a[i]] = i;
	ll rb[n + 1]; zep(i, 0, n)rb[b[i]] = i;
	ll ans[n]; memset(ans, -1, sizeof(ans));

	ll at = 0;
	zep(i, 0, n){
		if(ans[i] == -1){
			ll cnt = 0;
			while(a[at] != b[i]){
				ans[rb[a[at]]] = 0;
				cnt++;
				at++;
			}
			
			ans[i] = cnt + 1;
			at++;
		}
	}
	printa(ans, 0, n - 1)
	
	return 0;
}