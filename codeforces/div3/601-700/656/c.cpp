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

        if(n == 1){
            print(0)
            continue;
        }

        bool f = false;
        rrep(i, n - 2, 0){
            if(f){
                if(a[i] > a[i + 1]){
                    print(i + 1)
                    break;
                }
            }else{
                if(a[i] < a[i + 1])f = true;
            }

            if(i == 0)print(0)
        }
    }
    
    return 0;
}