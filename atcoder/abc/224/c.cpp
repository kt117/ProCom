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

ll n, x[300], y[300];

bool f(ll i, ll j, ll k){
    if(x[i] == x[j] && x[j] == x[k])return false;
    // if(y[i] == y[j] && y[j] == y[k])return false;
    if((y[i] - y[j]) * (x[j] - x[k]) == (y[j] - y[k]) * (x[i] - x[j]))return false;
    return true;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, n)cin >> x[i] >> y[i];
    
    ll ans = 0;
    zep(i, 0, n){
        zep(j, 0, i){
            zep(k, 0, j){
                if(f(i, j, k))ans++;
            }
        }
    }
    print(ans)

    return 0;
}