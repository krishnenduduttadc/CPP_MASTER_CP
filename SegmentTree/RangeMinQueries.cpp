#include<bits/stdc++.h>
using namespace std;
#define maxn 100001
#define inf 2e9 

int seg[4*maxn];
void build(int v,int l,int r, vector<int>&a){
	if(l==r)
	{
		seg[v]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*v,l,mid,a);
	build(2*v+1,mid+1,r,a);
	seg[v]=min(seg[2*v],seg[2*v+1]);
}
int query(int v,int l,int r,int x,int y)
{
	if(y<x)
	{
		return inf;
	}
	if(x<=l && r<=y)
	{
		return seg[v];
	}
	int mid=(l+r)/2;
	return min(query(2*v,l,mid,x,min(mid,y)),query(2*v+1,mid+1,r,max(mid+1,x),y));
}
void update(int v,int l,int r,int x,int val)
{
	if(l==r)
	{
		seg[v]=val;
		return;
	}
	int mid=(l+r)/2;
	if(mid>=x)
	{
		update(2*v,l,mid,x,val);
	}
	else
	{
		update(2*v+1,mid+1,r,x,val);
	}
	seg[v]=min(seg[2*v],seg[2*v+1]);
}
vector<int> solve(int n, vector<int>arr, vector<vector<int>> queries){
    memset(seg,0,sizeof(seg));
    build(1,0,n-1,arr);
    vector<int>ans;
	for(int i=0;i<queries.size();i++)
	{
		int type=queries[i][0],y=queries[i][1],z=queries[i][2];
		if(type==1)
		{
			y--;
			update(1,0,n-1,y,z);
		}
		else
		{
			y--;
			z--;
			ans.push_back(query(1,0,n-1,y,z));
		}
	}
	return ans;
}


int main() {
    // Hardcoded input
    int n = 5; // Size of the array
    vector<int> arr = {5, 3, 8, 6, 2}; // Initial array

    // Queries: {type, y, z}
    // type 1: Update arr[y-1] to z
    // type 2: Find minimum in range [y, z]
    vector<vector<int>> queries = {
        {2, 1, 3}, // Find minimum in range [1, 3]
        {1, 2, 1}, // Update arr[2-1] (index 1) to 1
        {2, 1, 3}, // Find minimum in range [1, 3] again
        {2, 3, 5}, // Find minimum in range [3, 5]
        {1, 5, 0}, // Update arr[5-1] (index 4) to 0
        {2, 4, 5}  // Find minimum in range [4, 5]
    };

    // Solve and get results
    vector<int> result = solve(n, arr, queries);

    // Print results of range queries
    for (int res : result) {
        cout << res << endl;
    }

    return 0;
}