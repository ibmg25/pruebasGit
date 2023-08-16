#include <bits/stdc++.h>
//#include <ext/rope>
 
using namespace std;
//using namespace __gnu_cxx;
 
#define ffor(i,o,f)        for(int i = o; i < f; i++)
#define bfor(i,f,o)        for(int i = f; i >= o, i--)
#define pb                 push_back
#define pf                 push_front
#define all(a)             (a).begin(), (a).end()
#define F                  first
#define S                  second
#define PI                 3.14159265358979323846264338327950
#define endl               '\n'
#define lcm(a,b)           (a*b)/__gcd(a,b)
#define mem(a, h)       memset(a, (h), sizeof(a))
#define setp(a)            fixed << setprecision(a)
typedef long long          ll;
typedef long double        ld;  
typedef pair < int, int >  pii;
typedef pair < ll, ll >    pll;
typedef vector < int >     vi;
typedef vector < pii >     vii;
typedef vector < vi >      gi;
typedef vector < ll >      vll;
typedef map < int, int >   mii;
const int INF = int(1e9 + 7);
const int MOD = 998244353;
const double EPS = double(1e-9);
const int tam = 200005;

int main() //IBMG
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int t, n, m, d, a;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> d;
        vi v;
        bool ult = true, prim = true;
        int ans = 0, cant;
        ffor(i, 0, m)
        {
            cin >> a;
            if (i == 0 && a != 1)
                v.pb(1), v.pb(a), prim = false;
            else
                v.pb(a);
        }
        ans = v.size();
        if (v[ans-1] < n)
            v.pb(n), ult = false;
        cant = v.size();
        if (!ult)
            cant--;
        if (!prim)
            cant--;
        int cantAux = cant;
        ffor(i, 1, v.size())
            ans += (v[i]-v[i-1]-1) / d;
        ffor(i, 1, v.size())
        {
            if (v[i] != n)
            {
                int aux = v[i-1] + ((v[i]-v[i-1]-1)/d)*d, one = 1;
                if (v[i+1] == n && !ult)
                    one = 0;
                if ((v[i+1] - aux - one) / d > (v[i+1] - v[i] - one) / d)
                    cant--;
                cout << aux << " " << v[i] << " " << v[i+1] << endl;
            }
            else if (ult)
            {
                int aux = v[i-1] + ((v[i]-v[i-1]-1)/d)*d;
                if ((n - aux - 1) > d)
                    cant--;
                cout << aux << " " << v[i] << " " << n << endl;
            }
        }
    }
    return 0;
}