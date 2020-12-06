#include<bits/stdc++.h>

using namespace std;

#define int long long

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)
#define vi vector<int> 
#define eb emplace_back
#define ii pair<int, int> 
#define fi first
#define se second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand rng
#define endl '\n'
#define bitCnt __builtin_popcountll
#define bitClz __builtin_clzll

const int maxN = 1e5 + 5;

int N, posAdd, arr[maxN], diff[maxN], ans; 

signed main()
{
	cin >> N;
	if(N == 1) return cout << 0, 0;
	loop(i, 1, N) cin >> arr[i];
	loop(i, 2, N) diff[i] = arr[i] - arr[i - 1];
	rloop(i, N, 2) // add 1 from l to r <=> diff[l]++, diff[r + 1]-- (1 <= l < r + 1 <= n + 1), our goal is to make diff[i] = 0 (2 <= i <= n)
	{
		if(diff[i] > 0) posAdd += diff[i]; 
		else 
		{
			int dec = min(posAdd, -diff[i]);
			posAdd -= dec;
			ans -= diff[i];
		}
	}
	ans += posAdd;
	cout << ans;
}
