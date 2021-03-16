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

vector<ll> X = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll x[n]; zep(i, 0, n)cin >> x[i];

    ll m = X.size();

    ll ans = INF;
    zep(bit, 1, (1LL << m)){
        bool ok = true;
        zep(i, 0, n){
            ok = false;
            zep(j, 0, m){
                if(x[i] % X[j] == 0 && (bit & (1LL << j))){
                    ok = true;
                }
            }
            if(!ok)break;
        }
        if(ok){
            ll t = 1;
            zep(j, 0, m){
                if(bit & (1LL << j)){
                    t *= X[j];
                }
            }
            ans = min(ans, t);
        }
    }
    print(ans)
    
    return 0;
}