#include<bits/stdc++.h>

using namespace std;

#define int long long

#define ii pair<int, int>
#define iii pair<ii, int>

#define mp make_pair
#define eb emplace_back

#define vi vector<int>
#define vii vector<ii>
#define viii vector<iii>

#define fi first
#define se second
#define xx fi.fi
#define yy fi.se
#define zz se
int arr[6000005], n, first_, sum, last;
bool check(int x)
{
	int cur = 1, rem = 0;
	for(int i=x; i<=60*n; i++) rem+=arr[i];
	for(int i=x-1; i>=0; i--){
		if((!i and cur>arr[i]+rem) or cur>1e14) return 0;
		if(cur>arr[i]){
			cur+=cur-arr[i];
		}
		else{
			rem+=arr[i]-cur;
		}
	}
	return 1;
}
signed main(){
// 	freopen(".inp", "r", stdin);
// 	freopen(".out", "w", stdout);
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0; i<=n-1; i++){
    	cin>>arr[i];
    	sum+=arr[i];
    	if(arr[i]) last = i;
	}
	if(sum==1)
	{
		cout<<(last==0? 1: last);
		return 0;
	}
	int l = 0, r = 60*n;
	while(l<r){
		int mid = (l+r+1)/2;
		if(check(mid)) l = mid;
		else r = mid-1;
	}
	cout<<l;
}
