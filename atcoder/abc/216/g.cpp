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

const ll MAX = 2 * 101 * 1001;
ll n, m, l[MAX], r[MAX], x[MAX];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;
    zep(j, 0, m){
        cin >> l[j] >> r[j] >> x[j];
        l[j]--;
        r[j]--;
    }

    vector<vector<ll>> v;
    zep(j, 0, m)v.push_back({l[j], r[j], x[j]});
    sort(v.begin(), v.end(), greater<>());

    ll cnt = 0, d = -1;
    priority_queue<P, vector<P>, greater<P>> q;
    zep(i, 0, n){
        while(!v.empty() && v.back()[0] == i){
            auto x = v.back(); v.pop_back();
            q.push(P(x[1] - x[2] + 1 - cnt, x[1]));
        }

        while(!q.empty() && q.top().first + cnt == i){
            d = max(d, q.top().second);
            q.pop();
        }

        if(d >= i){
            cout << 1 << " ";
            cnt++;
        }else{
            cout << 0 << " ";
        }
    }
    cout << endl;
    
    return 0;
}