/*
Input:
2
6 7
2 5 8 10 3 44
1 2 6
0 2 3
1 2 6
0 4 6
1 1 6
0 1 6
1 4 6
2 2
1 3
0 2 2
1 1 2
*/
#include<bits/stdc++.h>
using namespace std;

int buildSeg(int node,int st,int end,vector<int> v,int *tree)
        {
          
           if(st==end)
           {
           	tree[node]=v[st];
           	return tree[node];
           }
           
           	int mid=st+(end-st)/2;
           	tree[node]=max(buildSeg(2*node+1,st,mid,v,tree),buildSeg(2*node+2,mid+1,end,v,tree));
            return tree[node];
        }
//Build one for maximum leastprimedivisor
int rangeMax(int node,int *tree,int st,int end,int low,int high)
{
	if(end<low||st>high)
	return -1;
    if(low<=st&&end<=high)
    return tree[node];
    else
    {
            int mid=st+(end-st)/2;
            if(tree[node]!=1)
           	return max(rangeMax(2*node+1,tree,st,mid,low,high),rangeMax(2*node+2,tree,mid+1,end,low,high));
            else
            return 1;
    }
}
void updateTree(int node,int *tree,int st,int end,int low,int high,vector<int> &v,int *lp)
{
	if(end<low||st>high||st>end)
	return  ;
    if(st==end)
    {
      v[st]=v[st]/lp[v[st]];
      tree[node]=lp[v[st]];
      //cout<<tree[node]<<" ";
      return;
    }
   
            int mid=st+(end-st)/2;
            if(tree[node]!=1)
            {
            updateTree(2*node+1,tree,st,mid,low,high,v,lp);
            updateTree(2*node+2,tree,mid+1,end,low,high,v,lp);
           	tree[node]=max(tree[2*node+1],tree[2*node+2]); 
           	}   
}
 int main()
 {
    //least prime divisor means while updating the array only we mark them with number instead of 1
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        cin>>v[i];
      //Lets create a sieve
        int mm=*max_element(v.begin(),v.end());
        //cout<<mm<<"\n";
        //Sieve till m
        int lp[mm+1];
        memset(lp,0,sizeof(lp));
 
 
vector<int> pr;
 
for (int i=2; i<=mm; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back (i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=mm; ++j)
        lp[i * pr[j]] = pr[j];
}
  
        lp[0]=1;
        lp[1]=1;
 
//Now create a segment tree with leaf as the numbers of the array and further lets see

//SEGMENT TREE
        
    int x = (int)(ceil(log2(n))); 
 
    //Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1; 
 
    // Allocate memory
    int *tree = new int[max_size]; 
    //CREATION OF SEGMENT TREE 
    vector<int> val;
    for(int i=0;i<n;i++)
    val.push_back(lp[v[i]]);
   // for(int i=0;i<n;i++)
    //cout<<val[i]<<" ";
    //cout<<"\n";
    int valv=buildSeg(0,0,n-1,val,tree);
    /*cout<<"\n****************\n";
           for(int i=0;i<max_size;i++)
           cout<<tree[i]<<" ";
           cout<<"\n****************\n";
    */
        while(m--)
        {
            

            int type,l,r;
            cin>>type>>l>>r;
            switch(type)
            {
              case 0://Divide everyone with its smallest prime divisor
                     //We need a sieve till largest elemnt of v(n)
                     updateTree(0,tree,0,n-1,l-1,r-1,v,lp);
                     break;
              case 1://Get where get the max of the range's smallest prime divisor
                    cout<<rangeMax(0,tree,0,n-1,l-1,r-1)<<" ";
                     
            }
        /* cout<<"\n****************\n";
           for(int i=0;i<max_size;i++)
           cout<<tree[i]<<" ";
           cout<<"\n****************\n";
        */
        }
        cout<<"\n";
    }
    return 0;
 } 