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
    zep(i, 0, s.size() - 3){
        string z = "ZONe";

        bool ok = true;
        zep(j, 0, 4){
            if(s[i + j] != z[j])ok = false;
        }

        if(ok)ans++;
    }
    print(ans)
    
    return 0;
}