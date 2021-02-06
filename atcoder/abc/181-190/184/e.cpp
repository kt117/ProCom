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

int h, w, s, g;
vector<int> tr[26];
bool use[2000 * 2000]; 
//vector<vector<int>> G;
string a[2000]; 

int encode(int i, int j){
    return i * w + j;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> h >> w;
    zep(i, 0, h)cin >> a[i];
    //G.resize(h * w);
   
    zep(i, 0, h){
        zep(j, 0, w){
            if(a[i][j] == 'S')s = encode(i, j);
            if(a[i][j] == 'G')g = encode(i, j);
            if('a' <= a[i][j] && a[i][j] <= 'z')tr[a[i][j] - 'a'].push_back(encode(i, j));
        }
    }
    
    queue<pair<int, int>> q; q.push(make_pair(s, 0));
    use[s] = true;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while(!q.empty()){
        int at = q.front().first;
        int i = at / w;
        int j = at % w;
        int dst = q.front().second; q.pop();

        zep(k, 0, 4){
            if(0 <= i + dx[k] && i + dx[k] < h && 0 <= j + dy[k] && j + dy[k] < w){
                if(a[i + dx[k]][j + dy[k]] != '#'){
                    ll nx = encode(i + dx[k], j + dy[k]);

                    if(nx == g){
                        print(dst + 1) return 0;
                    }

                    if(!use[nx]){
                        use[nx] = true;
                        q.push(make_pair(nx, dst + 1));
                    }
                }
            }
        }

        if('a' <= a[i][j] && a[i][j] <= 'z'){
            int idx = a[i][j] - 'a';
            while(!tr[idx].empty()){
                if(at != tr[idx].back()){
                    ll nx = tr[idx].back();

                    if(nx == g){
                        print(dst + 1) return 0;
                    }

                    if(!use[nx]){
                        use[nx] = true;
                        q.push(make_pair(nx, dst + 1));
                    }
                }
                tr[idx].pop_back();
            }
        }
    }
    print(-1)

    return 0;
}