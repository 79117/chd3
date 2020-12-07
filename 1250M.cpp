#include <bits/stdc++.h>

using namespace std;

// #define int long long
#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)
#define vi vector<int>
#define eb emplace_back
#define ii pair<int, int>
#define fi first
#define se second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define endl '\n'
#define rand rng
#define bitCnt __builtin_popcountll
#define bitClz __builtin_clzll

const int maxOper = 55;

struct oper
{
	vi row, col;
	bool empty() 
	{
		return (row.empty() or col.empty());
	}
} ans[maxOper];
ostream& operator << (ostream& os, oper& o)
{
	os << o.row.size() << ' ';
	for(int t: o.row) os << t << ' '; os << endl;
	os << o.col.size() << ' ';
	for(int t: o.col) os << t << ' '; os << endl;
	return os;
}
int N, Oper;

void solve(int l, int r, int d)
{
	if(l >= r) return;
	int mid = (l + r) / 2;
	loop(i, l, mid - 1)	
	{
		ans[4 * d].col.eb(i);
		ans[4 * d + 1].row.eb(i); 
	}
	loop(i, mid + 1, r) 
	{
		ans[4 * d].row.eb(i);
		ans[4 * d + 1].col.eb(i);
	}
	loop(i, l, r)
	{
		if(i != mid and i != mid - 1) 
		{
			ans[4 * d + 2].col.eb(i);  
		}
	}
	ans[4 * d + 2].row.eb(mid);
	loop(i, l, r) 
	{
		if(i != mid and i != mid + 1) 
		{
			ans[4 * d + 3].row.eb(i); 
		}
	}
	ans[4 * d + 3].col.eb(mid);
	solve(l, mid - 1, d + 1);
	solve(mid + 1, r, d + 1);
}
signed main()
{
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	solve(1, N, 0);
	loop(i, 0, maxOper - 1)
	{
		if(!ans[i].empty()) Oper++;	
	}
	cout << Oper << endl;
	loop(i, 0, maxOper - 1)
	{
		if(!ans[i].empty())
		{
			cout << ans[i];
		}
	}
}
 
