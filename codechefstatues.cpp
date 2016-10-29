#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=(int)a;i<=(int)b;i++)
int main()
{
    
    while(1)
    {
    	int n;
        cin>>n;
        int sum=0;
        if(n==0)
        break;
    	vector<int> v(n);
    	F(i,0,n-1)
    	{
    		cin>>v[i];
    		sum+=v[i];
    	}
    	sort(v.rbegin(),v.rend());
        int val=sum/n;
        int low=0;
        int high=n-1;
        int moves=0;
        while(low<=high&&low<n&&high>=0)
        {
           
           if(val-v[high]<v[low]-val)
           {
           	moves+=val-v[high];
           	v[high]=val;
           	
           	v[low]-=(val-v[high]);
           }
           else
           if(val-v[high]==v[low]-val)
           {
           	moves+=val-v[high];
           	v[high]=val;
           	
           	v[low]=val;
           }
           else
           if(val-v[high]>v[low]-val)
           {
           	moves+=v[low]-val;
           	v[high]+=(v[low]-val);
           	
           	v[low]=val;
           }

           if(v[high]==val)
           	high--;
           if(v[low]==val)
           	low++;
        }
        cout<<moves<<"\n";
    }
	return 0;
}