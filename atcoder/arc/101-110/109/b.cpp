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

    ll ng = 15e8;
    ll ok = 0;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;

        if(mid * (mid + 1) / 2 <= n + 1){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    print(n + 1 - ok)
    
    return 0;
}