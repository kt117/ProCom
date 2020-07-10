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

ll n, gx, gy, x, y;
string s;

ll dst(){
	return abs(gx - x) + abs(gy - y);
}

void move(ll i){
	if(s[i] == 'U')y++;
	if(s[i] == 'D')y--;
	if(s[i] == 'L')x--;
	if(s[i] == 'R')x++;
}

void rmove(ll i){
	if(s[i] == 'U')y--;
	if(s[i] == 'D')y++;
	if(s[i] == 'L')x++;
	if(s[i] == 'R')x--;
}

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n >> s >> gx >> gy;
	
	if(dst() > n){print(-1) return 0;}

	zep(i, 0, n)move(i);
	
	if(dst() % 2 != 0){print(-1) return 0;}
	if(dst() == 0){print(0) return 0;}
	
	ll ok = n, ng = 0;
	while(ok - ng > 1){
		ll mid = (ok + ng) / 2;

		x = 0, y = 0;
		zep(i, mid, n){
			move(i);
		}

		bool f = false;
		if(dst() <= mid)f = true;
		zep(i, 0, n - mid + 1){
			move(i);
			rmove(i + mid);

			if(dst() <= mid)f = true;
		}

		if(f){
			ok = mid;
		}else{
			ng = mid;
		}
	}

	print(ok)

	return 0;
}