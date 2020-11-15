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
    
    ll n, w; cin >> n >> w;
    ll s[n], t[n], p[n]; zep(i, 0, n)cin >> s[i] >> t[i] >> p[i];

    ll use[200010]; memset(use, 0, sizeof(use));
    
    zep(i, 0, n){
        use[s[i]] += p[i];
        use[t[i]] -= p[i];
    }
    
    zep(i, 0, 200000){
        use[i + 1] += use[i];
    }

    bool ans = true;
    rep(i, 0, 200000){
        if(use[i] > w)ans = false;
        //if(i <= 10)print(use[i])
    }

    print(ans? "Yes" : "No")

    return 0;
}