#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int mxr=1<<17;
pair<int, pair<int, int> > ans[105][mxr]; 
int a[105];
int pr[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int v[60];
int getv(int x)
{
	int tmp=mxr-1;
	int k=0;
	for(int k=0; k<17; k++)
	{
		int t=0;
		while(x%pr[k]==0) 
		{
			x/=pr[k];
			t++;
		}
		if(t) tmp=tmp^(1<<k);
	}
	return mxr-1-tmp;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=n; i++)
    {
        for(int ii=0; ii<mxr; ii++)
        {
            ans[i][ii]=mp(INT_MAX, mp(INT_MAX, INT_MAX));
        }
    }
    for(int i=2; i<60; i++)
    {
    	v[i]=getv(i);
	}
    for(int i=1; i<=n; i++)
    {
        for(int ii=mxr-1; ii>=0; ii--)
        {
            for(int iii=2; iii<60; iii++)
            {
                int tmp=v[iii];
                if((ii&tmp)==tmp) 
                {
                    ans[i][ii^tmp] = min(ans[i][ii^tmp], 
                                            mp(ans[i-1][ii].fi + abs(iii-a[i]),
                                                mp(ii, iii)));
                }
            }
        	ans[i][ii] = min(ans[i][ii],
        	                mp(ans[i-1][ii].fi+a[i]-1,
        	                    mp(ii, 1)));
        }
        pair<int, pair<int, int> > mx=mp(INT_MAX, mp(INT_MAX, INT_MAX));
        for(int ii=mxr-1; ii>=0; ii--)
        {
        	if(mx.first>ans[i][ii].first) mx=min(mx, ans[i][ii]);
		}
    }
    pair<int, pair<int, int> > mx=mp(INT_MAX, mp(INT_MAX, INT_MAX));
    int mxi;
    for(int i=mxr-1;i>=0; i--)
    {
        if(mx>ans[n][i])
        {
            mx=ans[n][i];
            mxi=i;
        }
    }
    
    int i=n;
    vector<int> re;
    while(i)
    {
        re.push_back(ans[i][mxi].se.se);
        mxi=ans[i][mxi].se.fi;
        i--;
    }
    for(i=re.size()-1; i>=0; i--)
    {
    	cout<<re[i]<<' ';
	}
}
