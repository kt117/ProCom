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
    
    ll n, d; cin >> n >> d;
    ll l[n], r[n]; zep(i, 0, n)cin >> l[i] >> r[i];

    vector<P> rl(n); zep(i, 0, n)rl[i] = P(r[i], l[i]);
    sort(rl.begin(), rl.end());

    ll ans = 0, b = 0;
    zep(i, 0, n){
        if(rl[i].second > b){
            ans++;
            b = rl[i].first + d - 1;
        }
    }
    print(ans)
    
    return 0;
}