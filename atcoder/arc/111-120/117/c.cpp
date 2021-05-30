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

ll N, f[400005], g[400005];
string S, T = "WBR";
map<char, int> mp;

void init(){
    zep(i, 0, 3)mp[T[i]] = i;
    rep(i, 1, 400000){
        ll x = i;
        while(x % 3 == 0){x /= 3; f[i]++;}
        g[i] = x % 3;
    }
    g[0] = 1;
    rep(i, 1, 400000){
        f[i] += f[i - 1];
        g[i] *= g[i - 1];
        g[i] %= 3;
    }
}

int ncr(int n, int r){
    if(f[n] != f[r] + f[n - r])return 0;
    if(g[n] == 1 && g[r] * g[n - r] % 3 == 1)return 1;
    if(g[n] == 1 && g[r] * g[n - r] % 3 == 2)return 2;
    if(g[n] == 2 && g[r] * g[n - r] % 3 == 1)return 2;
    if(g[n] == 2 && g[r] * g[n - r] % 3 == 2)return 1;
    return -1;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);

    init();    
    cin >> N >> S;
    
    ll ans = 0;
    zep(i, 0, N){
        ans += ncr(N - 1, i) * mp[S[i]];
        ans %= 3;
    }

    if(N % 2 == 0)ans = (3 - ans) % 3;
    print(T[ans])
    
    return 0;
}