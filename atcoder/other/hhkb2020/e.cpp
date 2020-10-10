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
    
    ll h, w; cin >> h >> w;
    string s[h]; zep(i, 0, h)cin >> s[i];

    ll cnt[h][w]; memset(cnt, 0, sizeof(cnt));

    zep(i, 0, h){
        ll cur = 0;
        zep(j, 0, w){
            cur = (s[i][j] == '.')? cur + 1 : 0;
            cnt[i][j] += cur;
        }

        cur = 0;
        rrep(j, w - 1, 0){
            cur = (s[i][j] == '.')? cur + 1 : 0;
            cnt[i][j] += cur;
        }
    }

    zep(j, 0, w){
        ll cur = 0;
        zep(i, 0, h){
            cur = (s[i][j] == '.')? cur + 1 : 0;
            cnt[i][j] += cur;
        }

        cur = 0;
        rrep(i, h - 1, 0){
            cur = (s[i][j] == '.')? cur + 1 : 0;
            cnt[i][j] += cur;
        }
    }

    zep(i, 0, h)zep(j, 0, w)cnt[i][j] -= 3;

    //zep(i, 0, h){zep(j, 0, w)cout << cnt[i][j]; cout << endl;}
    ll k = 0;
    zep(i, 0, h)zep(j, 0, w)if(s[i][j] == '.')k++;

    ll p[k + 1];
    p[0] = 1;
    rep(i, 1, k)p[i] = 2 * p[i - 1] % MOD;

    ll ans = 0;
    zep(i, 0, h){
        zep(j, 0, w){
            if(s[i][j] == '.'){
                ans += p[k] + (MOD - p[k - cnt[i][j]]);
                ans %= MOD;
            }
        }
    }

    print(ans)
    
    return 0;
}