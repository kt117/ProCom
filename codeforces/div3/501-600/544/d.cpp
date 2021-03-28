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
    ll a[n]; zep(i, 0, n)cin >> a[i];
    ll b[n]; zep(i, 0, n)cin >> b[i];

    ll cnt = 0, ans = 0;
    map<P, ll> mp;
    zep(i, 0, n){
        if(a[i] == 0 && b[i] == 0)cnt++;
        
        if(a[i] != 0 && b[i] == 0)ans++;

        if(a[i] != 0 && b[i] != 0){
            bool ng = false;
            if(a[i] < 0){ng = !ng; a[i] *= -1;}
            if(b[i] < 0){ng = !ng; b[i] *= -1;}

            ll g = gcd(a[i], b[i]);
            a[i] /= g;
            b[i] /= g;

            if(ng)a[i] *= -1;
            P p = P(a[i], b[i]);

            if(mp.find(p) == mp.end())mp[p] = 0;
            mp[p]++;
        }
    }
    
    for(auto it = mp.begin(); it != mp.end(); it++){
        ans = max(ans, (*it).second);
    }
    print(ans + cnt)

    return 0;
}