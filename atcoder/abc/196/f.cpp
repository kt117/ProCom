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

complex<double> operator*(const complex<double> a, const complex<double> b)
{
    return complex<double>(a.real()*b.real()-a.imag()*b.imag(),a.real()*b.imag()+a.imag()*b.real());
}

void fft(vector<complex<double> >& a,bool rev = false)
{
    const double PI = 3.14159265358979324;
    unsigned int i, j, k, l;
    double r;
    complex<double> p, q, s;
    const unsigned int size = a.size();
    if(size == 1) return;
    vector<complex<double> > b(size);
    r = rev ? (- 2 * PI / size) : 2 * PI / size;
    vector<complex<double> > kp(size / 2 + 1, 1);
    for(i = 0; i <= size / 2; ++i) kp[i] = polar((double)1.0, i * r);
    for(i = 1, l = size / 2; i < size; i <<= 1, l >>= 1){
        for(j = 0, r = 0; j < l; ++j, r += i){
            for(k = 0, s = kp[i * j]; k < i; ++k){
                p = a[k + r], q = a[k + r + size / 2];
                b[k + 2 * r] = p + q, b[k + 2 * r + i] = (p - q) * s;
            }
        }
        swap(a, b);
    }
    if(rev){
        for(i = 0; i < size; i++){ a[i] /= size; }
    }
}
 
vector<int> mul(const vector<int>& a, const vector<int>& b)
{
    int s = (int)a.size() + (int)b.size() - 1, t = 1;
    while(t < s) t *= 2;
    vector<complex<double> > A(t), B(t);
    for(int i = 0; i < (int)a.size(); i++) A[i].real(a[i]);
    for(int i = 0; i < (int)b.size(); i++) B[i].real(b[i]);
    fft(A), fft(B);
    for(int i = 0; i < t; i++) A[i] *= B[i];
    fft(A, true);
    vector<int> res(s);
    for(int i = 0; i < s; i++) res[i] = round(A[i].real());
    return res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    string s, t; cin >> s >> t;
    ll n = s.size(), m = t.size();
    reverse(t.begin(), t.end());

    vector<int> sv(n), tv(m);
    zep(i, 0, n)sv[i] = s[i] - '0';
    zep(i, 0, m)tv[i] = t[i] - '0';
    
    auto p = mul(sv, tv);

    zep(i, 0, n)sv[i] = 1 - sv[i];
    zep(i, 0, m)tv[i] = 1 - tv[i];
    
    auto q = mul(sv, tv);

    int ans = 0;
    rep(i, m - 1, n - 1){
    	ans = max(ans, p[i] + q[i]);
    }
    print(m - ans)
    
    return 0;
}