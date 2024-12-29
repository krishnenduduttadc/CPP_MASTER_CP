#include<bits/stdc++.h>
using namespace std;
#define maxn 100001

int bit[maxn];
void update(int index,int val)
{
	while(index<maxn)
	{
		bit[index]+=val;
		index+=index&-index;
	}
}
int get(int index)
{
	int ans=0;
	while(index>0)
	{
		ans+=bit[index];
		index-=index&-index;
	}
	return ans;
}
vector<int> solve(int n, vector<int> nums, vector<vector<int>> queries){
    memset(bit,0,sizeof(bit));
    vector<int>ans;
    for(int i=0;i<queries.size();i++)
    {
        int type=queries[i][0];
        if(type==1)
        {
            int a=queries[i][1],b=queries[i][2],u=queries[i][3];
            update(b+1,-u);
            update(a,u);
        }
        else
        {
            int k=queries[i][1];
            ans.push_back(get(k)+nums[k-1]);
        }
    }
    return ans;
}


int main() {
    int n = 5; // Number of elements in the array
    vector<int> nums = {1, 2, 3, 4, 5}; // Base array

    // Queries: 
    // Type 1 -> Range update: [1, 2, 3, u]
    // Type 2 -> Point query: [2, k]
    vector<vector<int>> queries = {
        {1, 2, 4, 10}, // Add 10 to range [2, 4]
        {1, 3, 5, 5},  // Add 5 to range [3, 5]
        {2, 1},        // Query value at index 1
        {2, 3},        // Query value at index 3
        {2, 5}         // Query value at index 5
    };

    vector<int> result = solve(n, nums, queries);

    // Print results of the queries
    for (int r : result) {
        cout << r << endl;
    }

    return 0;
}