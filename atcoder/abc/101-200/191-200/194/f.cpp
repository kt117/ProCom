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

string s;
ll k, n;
vector<ll> v;

long long powmod(long long a, long long x){
    if(x == 0)return 1;
    long long r = powmod(a, x / 2);
    return (x%2)? (r * r % MOD) * a % MOD : r * r % MOD;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> s >> k;
    n = s.size();
    zep(i, 0, n){
        if('0' <= s[i] && s[i] <= '9'){
            v.push_back(s[i] - '0');
        }else{
            v.push_back(s[i] - 'A' + 10);
        }
    }

    ll bit = 0;
    ll dp[n][20]; memset(dp, 0, sizeof(dp));
    dp[0][1] = v[0] - 1;
    bit |= (1LL << v[0]);
    
    zep(i, 1, n){
        rep(j, 0, 16){
            dp[i][j] += j * dp[i - 1][j] % MOD;
            dp[i][j] %= MOD;
        }
        
        zep(j, 0, 16){
            dp[i][j + 1] += (16 - j) * dp[i - 1][j] % MOD;
            dp[i][j + 1] %= MOD;
        }
        
        dp[i][1] += 15;
        dp[i][1] %= MOD;
        
        zep(j, 0, v[i]){
            ll d = __builtin_popcount(bit | (1LL << j));
            dp[i][d] += 1;
            dp[i][d] %= MOD;
        }
        
        bit |= (1LL << v[i]);
    }

    ll d = __builtin_popcount(bit);
    dp[n - 1][d] += 1;
    dp[n - 1][d] %= MOD;

    print(dp[n - 1][k])

    return 0;
}