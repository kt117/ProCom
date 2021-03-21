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

ll n;
string s[111];
bool use[111];

void dfs(ll at){
    if(use[at])return;
    use[at] = true;

    zep(j, 0, n){
        if(!use[j] && s[j][at] == '1')dfs(j);
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    s[n]; zep(i, 0, n)cin >> s[i];

    double ans = 0;
    zep(i, 0, n){
        memset(use, 0, sizeof(use));
        dfs(i);

        ll cnt = 0;
        zep(j, 0, n)if(use[j])cnt++;

        ans += double(1) / cnt;
    }

    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}