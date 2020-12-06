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



int N, arr[maxN], cc[maxN], Sort[maxN], Size[maxN], ans, ccNum; 
bool on[maxN];
int findCC(int i)
{
	if(cc[i] == i) return i;
	else cc[i] = findCC(cc[i]);
	return cc[i];
}
void merge(int i, int j)
{
	i = cc[i]; j = cc[j];
	if(i == j) return;
	if(Size[i] < Size[j]) swap(i, j);
	Size[i] += Size[j];
	cc[j] = i;
	ccNum--;
}
void turnOn(int i)
{
	on[i] = 1;
	ccNum++;
}
bool cmp(int i, int j)
{
	return arr[i] < arr[j];
}
signed main()
{
	cin >> N;
	loop(i, 1, N)
	{
		cin >> arr[i];
		Sort[i] = i;
		cc[i] = i;
		Size[i] = 1;
	}
	sort(Sort + 1, Sort + N + 1, cmp);
	loop(i, 1, N) 
	{
		if(i == N) break;
		if(arr[Sort[i]] != arr[Sort[i + 1]])
		{
			int ptr = i;
			while(ptr and arr[Sort[ptr]] == arr[Sort[i]]) 
			{
				int id = Sort[ptr];
				turnOn(id);
				if(id > 1 and on[id - 1]) merge(id - 1, id);
				if(id < N and on[id + 1]) merge(id + 1, id);
				ptr--;
			}
			ans += (arr[Sort[i + 1]] - arr[Sort[i]]) * ccNum;
		}
	}
	cout << ans;
}
