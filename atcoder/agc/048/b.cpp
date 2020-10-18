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

const ll MAX = 100008;
ll n, a[MAX], b[MAX];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, n)cin >> a[i];
    zep(i, 0, n)cin >> b[i];

    //zep(j, 1, 5)dp[0][j] = -INF;
    
    ll ans = 0, cnt = 0;
    vector<ll> p, m;
    
    zep(i, 0, n / 2){
        if(a[2 * i] > b[2 * i]){
            if(a[2 * i + 1] > b[2 * i + 1]){
                ans += a[2 * i] + a[2 * i + 1];
                p.push_back(b[2 * i + 1] - a[2 * i + 1]);
                m.push_back(b[2 * i] - a[2 * i]);
            }else{
                ans += a[2 * i] + b[2 * i + 1];
                cnt++;
                m.push_back(b[2 * i] - a[2 * i]);
                m.push_back(a[2 * i + 1] - b[2 * i + 1]);
            }
        }else{
            if(a[2 * i + 1] > b[2 * i + 1]){
                ans += b[2 * i] + a[2 * i + 1];
                cnt--;
                p.push_back(a[2 * i] - b[2 * i]);
                p.push_back(b[2 * i + 1] - a[2 * i + 1]);
            }else{
                ans += b[2 * i] + b[2 * i + 1];
                p.push_back(a[2 * i] - b[2 * i]);
                m.push_back(a[2 * i + 1] - b[2 * i + 1]);
            }
        }
    }

    if(cnt > 0){
        sort(m.begin(), m.end(), greater<>());
        zep(i, 0, cnt)ans += m[i];
    }else if(cnt < 0){
        sort(p.begin(), p.end(), greater<>());
        zep(i, 0, -cnt)ans += p[i];
    }

    print(ans);
    
    return 0;
}