#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

const ll MAX = 3 * 1e5 + 10;
ll p[MAX], e[MAX], eb[MAX], ebb[MAX];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    string s[n]; zep(i, 0, n)cin >> s[i];
    ll N = n * m;

    p[0] = 1; rep(i, 1, N)p[i] = p[i - 1] * 2 % MOD;

    ll w = 0;
    zep(i, 0, n)zep(j, 0, m)if(s[i][j] == 'o')w++;
    
    rep(i, 0, N){
        if(w >= i)e[i] = (i / 2) * p[w - i] % MOD;
        if(w >= i + 1)eb[i] = (i / 2) * p[w - (i + 1)] % MOD;
        if(w >= i + 2)ebb[i] = (i / 2) * p[w - (i + 2)] % MOD;
    }
    rep(i, 1, N){e[i] += e[i - 1]; e[i] %= MOD;}
    rep(i, 1, N){eb[i] += eb[i - 1]; eb[i] %= MOD;}
    rep(i, 1, N){ebb[i] += ebb[i - 1]; ebb[i] %= MOD;}

    ll r[n][m];
    zep(i, 0, n){
        r[i][m - 1] = m - 1;
        rrep(j, m - 2, 0){
            if(s[i][j + 1] == '*'){
                r[i][j] = j;
            }else{
                r[i][j] = r[i][j + 1];
            }
        }
    }

    ll d[n][m];
    zep(j, 0, m){
        d[n - 1][j] = n - 1;
        rrep(i, n - 2, 0){
            if(s[i + 1][j] == '*'){
                d[i][j] = i;
            }else{
                d[i][j] = d[i + 1][j];
            }
        }
    }
    
    ll ans = 0;
    zep(i, 0, n){
        zep(j, 0, m){
            if(s[i][j] == 'o'){
                ll R = r[i][j] - j + 1;
                if(j == 0 || s[i][j - 1] == '*'){
                    if(R > 1){ans += eb[R - 1] + e[R] - e[R - 1]; ans %= MOD;}
                }else{
                    if(R > 1){ans += ebb[R - 1] + eb[R] - eb[R - 1]; ans %= MOD;}
                }
                
                
                ll D = d[i][j] - i + 1;
                if(i == 0 || s[i - 1][j] == '*'){
                    if(D > 1){ans += eb[D - 1] + e[D] - e[D - 1]; ans %= MOD;}
                }else{
                    if(D > 1){ans += ebb[D - 1] + eb[D] - eb[D - 1]; ans %= MOD;}
                }
            }
        }
    }

    print(ans)

    return 0;
}