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

    bool use[n + 1]; memset(use, 0, sizeof(use));
    ll ans = -1;
    zep(i, 0, n){
        if(use[a[i]])ans = a[i];
        use[a[i]] = true;
    }

    if(ans == -1){
        print("Correct")
    }else{
        rep(i, 1, n){
            if(!use[i]){
                cout << ans << " " << i << endl;
                return 0;
            }
        }
    }
    
    return 0;
}