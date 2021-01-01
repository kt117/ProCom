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
    
    ll n, k; cin >> n >> k;
    ll a[n]; zep(i, 0, n)cin >> a[i];
    
    ll cnt[5001]; memset(cnt, 0, sizeof(cnt));
    ll c[n];
    bool ans = true;
    ll cur = 1;
    rep(j, 1, 5000){
        zep(i, 0, n){
            if(a[i] == j){
                cnt[a[i]]++;
                if(cnt[a[i]] > k)ans = false;
                c[i] = cur;
                cur++;
                if(cur > k)cur = 1;
            }
        }
    }

    if(ans){
        print("YES")
        printa(c, 0, n - 1)
    }else{
        print("NO")
    }

    return 0;
}