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
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll a[n]; zep(i, 0, n)cin >> a[i];

        sort(a, a + n, greater<>());

        ll cnt = 0;
        zep(i, 0, n){
            if(i % 2 == 0){
                if(a[i] % 2 == 0)cnt += a[i];
            }else{
                if(a[i] % 2 == 1)cnt -= a[i];
            }
        }

        if(cnt > 0){
            print("Alice")
        }else if(cnt == 0){
            print("Tie")
        }else{
            print("Bob")
        }
    }
    
    return 0;
}