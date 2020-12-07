//	ZapZu's code hohoho
//	#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define dfs_black 1
#define dfs_white -1
#define pr pair
#define vt vector
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long li;
typedef long double ld;

typedef pr<int, int> ii;
typedef pr<ld,ld> dd;

typedef vt<int> vi;
typedef vt<li> vli;
typedef vt<ld> vld;
typedef vt<ii> vii;

typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<int, char> mic;

typedef set<int> s_i;
typedef set<char> s_c;

const int MOD = 998244353;
const li INF = 1e18;
const ld PI = 4*atan((ld)1);
#define viii vector<pair<ii, int> >
int ans=1;
viii qr;
int n, m, k;
int ex[500005], rng[500005], dp[500005], dp2[500005], dp3[500005], sdp[500005], pf[500005];
void solve(int bit)
{
	viii Q;
	for(int i=1; i<=n; i++) ex[i] = rng[i] = dp[i] = dp2[i] = dp3[i] = sdp[i] = pf[i] = 0;
	for(auto q: qr)
	{
		Q.pb({q.fi, !(q.se&(1<<bit-1))});
	}
	for(auto q: Q)
	{
		if(!q.se) 
		{
			pf[q.fi.fi]++;
			pf[q.fi.se+1]--;
		}
	}
	int mxid = 0; dp2[0]=0, dp3[n+1] = n+1;
	for(int i=1; i<=n; i++)
	{
		pf[i]+=pf[i-1];
		if(!pf[i]) ex[i] = ++mxid;
		dp2[i] = !pf[i]? i: dp2[i-1];
	}
	for(int i=n; i>=1; i--) dp3[i] = !pf[i]? i: dp3[i+1];
	for(auto q: Q)
	{
		if(q.se)
		{
			int l = dp3[q.fi.fi], r = dp2[q.fi.se];
			if(l>r) 
			{
				ans=0;
				return;
			}
		 	rng[ex[r]] = ex[l];
		 }
	}
	for(int i=1; i<=mxid; i++) rng[i] = max(rng[i], rng[i-1]);
	dp[0] = sdp[0] = 1;
	for(int i=1; i<=mxid; i++)
	{
		dp[i] = (sdp[i-1] - (rng[i-1]==0? 0: sdp[rng[i-1]-1]))%MOD;
		sdp[i] = (sdp[i-1] + dp[i])%MOD;
	}
	int re = mxid==0? 1: (sdp[mxid] - (rng[mxid]==0? 0: sdp[rng[mxid]-1]))%MOD;
	ans = ans*re%MOD;
}
signed main()
{
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);
	fastio;
	cin>>n>>k>>m;
	for(int i=1; i<=m; i++)
	{
		int l, r, val;
		cin>>l>>r>>val;
		qr.pb({{l, r}, val});
	}
	sort(begin(qr), end(qr));
	for(int i=1; i<=k; i++) solve(i);
	while(ans<0) ans+=MOD;
	cout<<ans;
}

 
