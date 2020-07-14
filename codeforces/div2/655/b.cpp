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
        
        ll d = -1;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                d = i;
                break;
            }
        }
        
        if(d == -1){
            cout << 1 << " " << n - 1 << endl;
        }else{
            cout << n / d << " " << n - n / d << endl;
        }
    }
    
    return 0;
}