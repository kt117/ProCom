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

bool uses[2], uset[2];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    ll s[n]; zep(i, 0, n)cin >> s[i];
    ll t[m]; zep(i, 0, m)cin >> t[i];

    zep(i, 0, n)uses[s[i]] = true;
    zep(i, 0, m)uset[t[i]] = true;

    if(uset[0] && !uses[0]){print(-1) return 0;}
    if(uset[1] && !uses[1]){print(-1) return 0;}

    ll l[2], r[2];
    zep(k, 0, 2){
        zep(i, 0, n){
            if(s[(n - i) % n] == k){
                l[k] = i;
                break;
            }
        }

        zep(i, 0, n){
            if(s[i] == k){
                r[k] = i;
                break;
            }
        }
    }

    ll ans = 0;
    ans += min(l[t[0]], r[t[0]]) + 1;

    bool ok = false;
    if(s[0] != t[0])ok = true;
    
    zep(i, 1, m){
        ans++;
        if(t[i] != t[i - 1]){
            if(ok){
                ans++;
            }else{
                ans += min(l[t[i]], r[t[i]]);
                ok = true;
            }
        }
    }
    print(ans)
    
    return 0;
}