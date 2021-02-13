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
    
    double x, y, r; cin >> x >> y >> r;

    ll ans = 0;
    rep(i, floor(x - r), ceil(x + r)){
        ll ok = ceil(y);
        ll ng = ceil(y + r);
        

        while(ng - ok > 1){
            double mid = (ok + ng) / 2;
            if(f(mid)){
                ok = mid;
            }else{

            }
        }
    }
    
    return 0;
}