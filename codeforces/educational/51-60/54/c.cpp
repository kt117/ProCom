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
		ll d; cin >> d;

		if(0 < d && d < 4){
			print("N")
		}else{
			double a = (d + sqrt(d * d - 4 * d)) / 2;
			double b = (d - sqrt(d * d - 4 * d)) / 2;

			cout << fixed << setprecision(20) << "Y " << a << " " << b << endl;
		}
	}
	
	return 0;
}