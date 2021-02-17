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

ll n, a[200 * 1001], b[200 * 1001];

bool f(ll mid){
    ll sm = 0;
    rep(i, 0, mid)sm += b[i];

    zep(i, mid + 1, n){
        if(sm < b[i]){
            return false;
        }else{
            sm += b[i];
        }
    }
    return true;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        cin >> n;
        zep(i, 0, n)cin >> a[i];

        zep(i, 0, n)b[i] = a[i];
        sort(b, b + n);

        ll ok = n - 1;
        ll ng = -1;
        while(ok - ng > 1){
            ll mid = (ok + ng) / 2;

            if(f(mid)){
                ok = mid;
            }else{
                ng = mid;
            }
        }

        vector<ll> ans;
        zep(i, 0, n){
            if(a[i] >= b[ok])ans.push_back(i + 1);
        }
        print(ans.size())
        printa(ans, 0, ans.size() - 1)
    }
    
    return 0;
}