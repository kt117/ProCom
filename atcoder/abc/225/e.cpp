#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double, double> P;
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
    ll x[n], y[n]; zep(i, 0, n)cin >> x[i] >> y[i];
    
    vector<P> task(n);
    zep(i, 0, n){
        if(x[i] == 1){
            task[i] = P(INF, double(y[i] - 1) / x[i]);
        }else{
            task[i] = P(double(y[i]) / (x[i] - 1), double(y[i] - 1) / x[i]);
        }
    }
    sort(task.begin(), task.end());

    ll ans = 0;
    double now = 0;
    zep(i, 0, n){
        if(task[i].second >= now){
            ans++;
            now = task[i].first;
        }
    }
    print(ans)

    return 0;
}