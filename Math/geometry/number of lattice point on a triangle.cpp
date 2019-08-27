#include <bits/stdc++.h>
using namespace std;
#define pf                  printf
#define sc                  scanf
#define pb                  push_back
#define eb                  emplace_back
#define present(c,x)        ((c).find(x) != (c).end())
#define mp                  make_pair
#define xx                  first
#define yy                  second
#define endl                '\n'
#define SZ(v)               ((int) (v).size())
#define all(v)              (v).begin(), (v).end()
typedef long long           ll;
typedef long double         LD;
typedef unsigned long long  ull;
typedef pair<int,int>       pii;
const LD EPS =              1e-9;
const LD PI=                acos(-1.0);
const int MX=               6e5+5;
ll mod=                     1e9+7;

template<class T> T egcd(T a, T b, T &x,T &y){
    if(!b){
        x=1,y=0;return a;
    }
    T _g=egcd(b,a%b,x,y);
    T xt=x;x=y,y=xt-(a/b)*y;
    return _g;
}
inline int crt(vector<int>&ao,vector<int> &mo){
	int sz = (int) ao.size();
	int n = 1;for(int p : mo)n*=p; int res = 0;
	for(int i = 0;i<sz;i++)
	{
		ll m_i = n/mo[i];
		ll m_inv,ing;
		egcd(m_i,mo[i]*1LL,m_inv,ing);
		if(m_inv < 0)m_inv+=mo[i];
		res = (res + ((m_i * m_inv) % n) * ao[i])%n ; //be very carefull with overflow
	}
	return res;
}

bool vis[100001];
ll prime[9592];
vector<int> modu[100001];
int main()
{
	for(ll i=3;i*i <= 100000;i+=2){
		if(!vis[i])
			for(ll j = i*i;j<=100000;j+=i+i)
				vis[j] = 1;
	}
	prime[0] = 2;
	int pm = 1;
	for(int i = 3;i <= 100000; i+=2)
		if(!vis[i])
			prime[pm++] = i;
	memset(vis,0,sizeof(vis));
	for(int i = 0; i < pm ; i++){
		for(ll j = prime[i]; j<=100000;j*=prime[i])
			vis[j] = 1;
	}
	
	for(int i = 6; i<=100000;i++){
		if(!vis[i]){		
			int x = i;
			for(int j = 0; j<pm and prime[j]*prime[j] <= x;j++){
				if(x % prime[j] == 0){
					int c = 1;
					while(x % prime[j] == 0)
						c*=prime[j], x/=prime[j];
					modu[i].pb(c);
				}
			}
			if(x>1)modu[i].pb(x);
		}
	}
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int tc,ts=0;cin>>tc;while(tc--){
		int n;
		string s;cin>>s>>n;
		vector<int> ans(n+1,-1);
		ans[0]=ans[1] = 0; ll RES = 0;
		for(int i = 0; i < pm and prime[i] <= n; i++){
			ll x = prime[i];
			while(x * prime[i] <= n)
				x*=prime[i];
			ll res = 0;
			for(int j = 0;s[j];j++){
				res = (res * 10 + s[j] - '0');// % x;
				//while(res >= x)res-=x;
				if(res > 100000000000000000LL)res%=x;
			}
			res%=x;
			ans[x] = res;RES+=res;
			x/=prime[i];
			while(x >= prime[i]){
				ans[x] = res % x; RES+=ans[x];
				x/=prime[i];
			}
		}

		for(int i = 6; i<=n;i++){
			if(ans[i] == -1){
				vector<int> au(SZ(modu[i]));
				for(int j=0;j<SZ(modu[i]);j++)
					au[j] = ans[modu[i][j]];
				RES+=crt(au, modu[i]);

			}
		}
		cout<<"Case "<<++ts<<": "<<RES<<endl;
	}
    return 0;
}

/**
						Md. Tariqul Islam
							IIT,JU
						  fb/tariqiitju
					  tarik.amtoly@gmail.com
*/