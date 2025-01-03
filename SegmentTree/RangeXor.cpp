#include<bits/stdc++.h>
using namespace std;
#define maxn 100001

int seg[4*maxn];
void build(int v,int l,int r, vector<int> &a){
	if(l==r)
	{
		seg[v]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*v,l,mid,a);
	build(2*v+1,mid+1,r,a);
	seg[v]=seg[2*v]^seg[2*v+1];
}
int query(int v,int l,int r,int x,int y)
{
	if(y<x)
	{
		return 0;
	}
	if(x<=l && r<=y)
	{
		return seg[v];
	}
	int mid=(l+r)/2;
	return query(2*v,l,mid,x,min(mid,y))^query(2*v+1,mid+1,r,max(mid+1,x),y);
}
vector<int>solve(int n, vector<int>a, vector<vector<int>> queries){
    memset(seg,0,sizeof(seg));
	build(1,0,n-1,a);
	vector<int>ans;
    for(int i=0;i<queries.size();i++)
	{
	    int a=queries[i][0],b=queries[i][1];
		ans.push_back(query(1,0,n-1,a-1,b-1));
	}
	return ans;
}

int main() {
    // Hardcoded inputs
    int n = 5;  // Size of the array
    vector<int> a = {1, 2, 3, 4, 5}; // Input array

    // Queries as {start_index, end_index}
    vector<vector<int>> queries = {
        {1, 3}, // XOR of elements from index 1 to 3 (1-based)
        {2, 5}, // XOR of elements from index 2 to 5
        {1, 5}  // XOR of all elements
    };

    // Solve the problem and get results
    vector<int> result = solve(n, a, queries);

    // Print the results of the queries
    for (int res : result) {
        cout << res << endl;
    }

    return 0;
}