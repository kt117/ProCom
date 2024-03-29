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
        ll w, h, n; cin >> w >> h >> n;

        ll cnt = 1;
        while(w % 2 == 0){
            w /= 2;
            cnt *= 2;
        }
        while(h % 2 == 0){
            h /= 2;
            cnt *= 2;
        }
        // print(cnt)
        print((cnt >= n)? "YES" : "NO")
    }
    
    return 0;
}