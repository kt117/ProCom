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
        ll q[n]; zep(i, 0, n){cin >> q[i]; q[i]--;}

        ll mx[n], mn[n];
        priority_queue<ll> qmx;
        priority_queue<ll, vector<ll>, greater<ll>> qmn;
        bool use[n]; memset(use, 0, sizeof(use));

        zep(i, 0, n){
            if(i == 0 || q[i] != q[i - 1]){
                mx[i] = q[i];
                mn[i] = q[i];

                use[q[i]] = true;
                rrep(j, q[i] - 1, 0){
                    if(use[j])break;
                    use[j] = true;
                    qmx.push(j);
                    qmn.push(j);
                }
            }else{
                mx[i] = qmx.top(); qmx.pop();
                mn[i] = qmn.top(); qmn.pop();
            }
        }

        zep(i, 0, n)cout << mn[i] + 1 << " "; cout << endl;
        zep(i, 0, n)cout << mx[i] + 1 << " "; cout << endl;
    }
    
    return 0;
}