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
    ll a[2 * n]; zep(i, 0, 2 * n)cin >> a[i];

    P b[2 * n]; zep(i, 0, 2 * n)b[i] = P(a[i], i);
    sort(b, b + 2 * n);
    bool bg[2 * n]; memset(bg, 0, sizeof(bg));
    zep(i, n, 2 * n)bg[b[i].second] = true;
    
    // zep(i, 0, 2 * n)cout << bg[i] << " "; cout << endl;
    ll cnt = 0;
    bool ans[2 * n]; memset(ans, 0, sizeof(ans));
    zep(i, 0, 2 * n){
        if(bg[i]){
            if(cnt >= 0){
                ans[i] = true;
            }
            cnt++;
        }else{
            if(cnt <= 0){
                ans[i] = true;
            }
            cnt--;
        }
    }
    zep(i, 0, 2 * n){
        if(ans[i]){
            cout << '(';
        }else{
            cout << ')';
        }
    }
    cout << endl;

    return 0;
}