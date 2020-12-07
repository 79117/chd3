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
int N, K, A, B;
int Ans = 0;
signed main()
{
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	cin >> N >> K >> A >> B;
	while(1)
	{
		if(N == 1) break;
		if(N < K or K == 1)
		{
			Ans += (N - 1) * A;
			N = 1;
		}
		else if(N % K)
		{
			int rem = N % K;
			Ans += rem * A;
			N -= rem;
		}
		else 
		{
			int del = N - N / K;
			Ans += min(A * del, B);
			N /= K;
		}
	}
	cout << Ans;
}
