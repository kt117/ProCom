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
    ll t[n], l[n], r[n]; zep(i, 0, n)cin >> t[i] >> l[i] >> r[i];

    zep(i, 0, n){
        l[i] *= 2;
        r[i] *= 2;
        if(t[i] == 2)r[i]--;
        if(t[i] == 3)l[i]++;
        if(t[i] == 4){l[i]++; r[i]--;}
    }

    ll ans = 0;
    zep(i, 0, n){
        zep(j, 0, i){
            if(!(r[i] < l[j] || r[j] < l[i]))ans++;
        }
    }
    print(ans)
    
    return 0;
}