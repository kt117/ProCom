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

ll n, l, a[100008], b[100008];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> l;
    rep(i, 1, n)cin >> a[i];
    rep(i, 1, n)cin >> b[i];
    a[0] = 0;
    b[0] = 0;
    a[n + 1] = l + 1;
    b[n + 1] = l + 1;
    n += 2;

    vector<ll> f;
    zep(i, 0, n)if(a[i] == b[i])f.push_back(i);

    ll m = f.size();
    
    ll ans = 0;
    zep(i, 0, m - 1){
        ll B = f[i];
        bool flag = false;
        rep(j, f[i] + 1, f[i + 1] - 1){
            if(b[j] < a[j]){
                if(flag){print(-1) return 0;}
                B = j;
            }else{
                flag = true;
            }
        }

        map<ll, ll> L;
        L[b[f[i]] - f[i]] = f[i];
        rep(j, f[i] + 1, B){
            if(L.find(b[j] - j) == L.end()){
                print(-1) return 0;
            }else{
                ans += j - L[b[j] - j];
                L[b[j] - j] = j;
            }

            L[a[j] - j] = j;
        }
        //print(ans)

        map<ll, ll> R;
        R[b[f[i + 1]] - f[i + 1]] = f[i + 1];
        rrep(j, f[i + 1] - 1, B + 1){
            if(R.find(b[j] - j) == R.end()){
                print(-1) return 0;
            }else{
                ans += R[b[j] - j] - j;
                R[b[j] - j] = j;
            }

            R[a[j] - j] = j;
        }
        //print(ans)
    }
    
    print(ans)

    return 0;
}