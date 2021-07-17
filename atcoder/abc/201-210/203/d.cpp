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

ll n, k, a[1000][1000], cnt[2000][2000];

bool f(ll x){
    memset(cnt, 0, sizeof(cnt));

    zep(i, 0, n){
        zep(j, 0, n){
            if(a[i][j] <= x){
                cnt[max(i - k + 1, 0LL)][max(j - k + 1, 0LL)]++;
                cnt[max(i - k + 1, 0LL)][j + 1]--;
                cnt[i + 1][max(j - k + 1, 0LL)]--;
                cnt[i + 1][j + 1]++;
            }
        }
    }
    zep(i, 0, n)zep(j, 0, n)cnt[i + 1][j] += cnt[i][j];
    zep(i, 0, n)zep(j, 0, n)cnt[i][j + 1] += cnt[i][j];
    // zep(i, 0, n){zep(j, 0, n)cout << cnt[i][j] << " "; cout << endl;}
    rep(i, 0, n - k){
        rep(j, 0, n - k){
            if(cnt[i][j] >= (k * k + 1) / 2)return true;
        }
    }
    return false;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> k;
    zep(i, 0, n)zep(j, 0, n)cin >> a[i][j];

    ll ok = INF;
    ll ng = -1;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;

        if(f(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    print(ok)
    //print(f(5));
    
    return 0;
}