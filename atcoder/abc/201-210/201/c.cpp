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
    
    
    string s; cin >> s;

    ll ans = 0;
    rep(i, 0, 9999){
        bool use[10]; memset(use, 0, sizeof(use));

        ll x = i;
        zep(j, 0, 4){
            use[x % 10] = true;
            x /= 10;
        }

        bool ok = true;
        zep(j, 0, 10){
            if(s[j] == 'o' && !use[j])ok = false;
            if(s[j] == 'x' && use[j])ok = false;
        }

        if(ok)ans++;
    }

    print(ans)
    
    return 0;
}