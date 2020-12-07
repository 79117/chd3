#include<bits/stdc++.h>

using namespace std;

 #define int long long
#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)
#define vi vector<int>
#define rb emplace_back
#define ii pair<int, int>
#define fi first
#define se second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define endl '\n'
#define rand rng
#define bitCnt __builtin_popcountll
#define bitClz __builtin_clzll

const int maxN = 1e5 + 5; 

int N, arr[maxN], diff[maxN], nowAdd, ans;

signed main()
{
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	cin >> N;
	loop(pos, 1, N) cin >> arr[pos];
	loop(pos, 2, N) diff[pos] = arr[pos] - arr[pos - 1];
	rloop(pos, N, 2)
	{
		if(diff[pos] < 0) ans -= diff[pos];
	}
	cout << ans;
}
