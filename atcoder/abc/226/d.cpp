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

long long gcd(long long a, long long b){return (b == 0)? a : gcd(b, a % b);}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll x[n], y[n]; zep(i, 0, n)cin >> x[i] >> y[i];

    set<P> ans;
    zep(i, 0, n){
        zep(j, 0, n){
            if(i != j){
                ll a = x[j] - x[i], b = y[j] - y[i];
                ll g = gcd(abs(a), abs(b));
                ans.insert(P(a / g, b / g));
            }
        }
    }
    print(ans.size())

    return 0;
}