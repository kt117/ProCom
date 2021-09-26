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
    
    ll n; cin >> n;

    ll d = 0, x = n;
    while(x){
        x /= 10;
        d++;
    }
    
    ll ans = 0;
    zep(i, 0, d - 1){
        ans += pow(10, i) * (d - 1 - i);
    }
    
    ll cnt = 0;
    zep(i, 0, d)cnt += pow(10, i);
    // print(ans)
    zep(i, 0, d){
        ans += max(min(ll(pow(10, i)), n - cnt + 1), 0LL);
        // print(n - cnt + 1)
        cnt -= pow(10, i);
    }
    print(ans)
    
    return 0;
}