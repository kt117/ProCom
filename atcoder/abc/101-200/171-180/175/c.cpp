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
    
    ll x, k, d; cin >> x >> k >> d;
    
    ll res = x % d;
    
    if(abs(x - res) / d <= k){
        k -= abs(x - res) / d;
        
    	if(k % 2 == 0){
    		print(abs(res))
    	}else{
            print(abs(d - abs(res)));
    	}

    	return 0;
    }
    
    print(min(abs(x + k * d), abs(x - k * d)))
    
    return 0;
}