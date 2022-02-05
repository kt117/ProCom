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
    
    vector<P> v(n);
    zep(i, 0, n)v[i] = P(a[i], a[i + n]);
    sort(v.begin(), v.end());
    if(v[0].second <= v[0].first){
        cout << v[0].first << " " << v[0].second << endl; return 0;
    }

    vector<P> u(n);
    zep(i, 0, n)u[i] = P(a[i], i);
    sort(u.begin(), u.end());

    vector<ll> ans;
    ans.push_back(u[0].second);
    bool check = false, add = false;
    ll lb = u[0].second;
    zep(i, 1, n){
        if(u[i].first < a[n + ans[0]]){
            if(u[i].second > lb){
                ans.push_back(u[i].second);
                lb = u[i].second;
            }
        }else if(u[i].first == a[n + ans[0]]){
            if(!check){
                zep(j, 0, ans.size()){
                    if(a[n + ans[j]] != a[n + ans[0]]){
                        if(a[n + ans[j]] > a[n + ans[0]]){
                            add = true;
                        }
                        break;
                    }
                }
                check = true;
            }

            if(add){
                if(u[i].second > lb){
                    ans.push_back(u[i].second);
                    lb = u[i].second;
                }
            }
        }else{
            break;
        }
    }

    zep(i, 0, ans.size())cout << a[ans[i]] << " ";
    zep(i, 0, ans.size())cout << a[n + ans[i]] << " ";
    cout << endl;

    return 0;
}