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
    ll a[n]; zep(i, 0, n)cin >> a[i];

    ll cnt = 0;
    bool flag = true;
    while(flag){
        zep(i, 0, n)if(a[i] % 2)flag = false;
        if(flag)cnt++;
        if(flag)zep(i, 0, n)a[i] /= 2;
    }

    ll sm = 0;
    zep(i, 0, n)sm += a[i];

    bool dp[sm + 1]; memset(dp, 0, sizeof(dp));
    dp[0] = true;

    zep(i, 0, n){
        rrep(j, sm, 0){
            if(dp[j]){
                dp[j + a[i]] = true;
            }
        }
    }
    
    if(sm % 2){
        print(0)
    }else if(dp[sm / 2]){
        print(1)
        zep(i, 0, n)if(a[i] % 2){
            print(i + 1)
            break;
        }
    }else{
        print(0)
    }

    return 0;
}