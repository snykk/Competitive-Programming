#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll m,n,max_a,max_b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
    cin>>m;
    while(m--) {
        max_a=max_b=0;
        
        cin>>n;
        
        ll a[n],b[n];
        
        for(ll i=0; i<n; i++)
        {
            cin>>a[i];
            max_a=max(max_a,a[i]);
        }
        for(ll i=0; i<n; i++)
        {
            cin>>b[i];
            max_b=max(max_b,b[i]);
        }
        
        if(max_a>max_b)
        {
            for(ll i=0; i<n; i++)
            {
                if(a[i]<b[i]) swap(a[i],b[i]);
            }
            
            sort(b,b+n);
            cout<<b[n-1]*max_a<<endl;
        } else {
            for(ll i=0; i<n; i++)
            {
                if(a[i]>b[i]) swap(a[i],b[i]);
            }
            
            sort(a,a+n);
            cout<<a[n-1]*max_b<<endl;
        }
    }
    
    return 0;
}
