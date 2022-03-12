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
    
    ll n, x; cin >> n >> x;
    ll a[n], b[n]; zep(i, 0, n)cin >> a[i] >> b[i];

    ll ok[x + 1];
    ok[0] = true;

    zep(i, 0, n){
        rrep(j, x, 0){
            if(ok[j]){
                if(j + a[i] <= x)ok[j + a[i]] = true;
                if(j + b[i] <= x)ok[j + b[i]] = true;
            }
            ok[j] = false;
        }
    }
    print(ok[x]? "Yes" : "No")
    
    return 0;
}