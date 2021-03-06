//https://practice.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number/0
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
#define test ll t;cin>>t;while(t--)
#define input(a,b) vector<ll>v(b);for(auto i=a;i<b;i++)cin>>v[i]
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef unordered_map<ll,ll> mpp;
typedef pair<ll,ll> ii;

vector<ll>num;
ll n;
ll ans=0;
ll recApproach(ll i,ll j,ll sum)
{
    
    if(j>=n)
    {
        if(i+1>=n)
        {
            return 0;
        }
        else
            return sum+recApproach(i+1,i+1,0);
        
    }
    ll res=0,s=0;
    s=(sum*10)+num[j];
    ans+=s;
    res=recApproach(i,j+1,s);
    return res;
    
}

ll sumSubstring()
{
    vector<ll>sos(n);
    sos[0]=num[0];ll res=sos[0];
    for(auto i=1;i<n;i++)
    {
        sos[i]=(i+1)*num[i]+(sos[i-1]*10);
        res+=sos[i];
    }
    return res;
    
}

ll sumOfSubstring()
{
    ll mf=1;ans=0;
    for(auto i=n-1;i>=0;i--)
    {
        ans+=num[i]*(i+1)*mf;
        mf=(mf*10)+1;
    }
    return ans;
}


int32_t main()
{
	fast;
	test
	{
	    string s;
	    cin>>s;
	    n=s.length();
	    num.resize(s.length());
	    for(auto i=0;i<s.length();i++)
	    {
	        num[i]=(ll)(s[i]-48);
	    }
	    /*ll a=recApproach(0,0,0);
	    cout<<ans<<endl;
	    ans=0;*/
	    cout<<sumOfSubstring()<<endl;
	    
	}


	return 0;
}
