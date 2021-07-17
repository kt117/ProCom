#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e18;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

long long COM(int n, int k){
    bool use[k + 1]; memset(use, 0, sizeof(use));
    ll r = 1;
    rrep(i, n, n - k + 1){
        r *= i;
        rep(j, 1, k){
            if(!use[j] & r % j == 0){
                r /= j;
                use[j] = true;
            }
        }
    }
    return r;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);

    ll a, b, k; cin >> a >> b >> k;
    ll m = a + b;
    zep(i, 0, m){
        if(a == 0){
            cout << 'b';
            b--;
        }else if(k <= COM(a + b - 1, b)){
            cout << 'a';
            a--;
        }else{
            cout << 'b';
            k -= COM(a + b - 1, b);
            b--;
        }
    }
    
    cout << endl;
    
    return 0;
}