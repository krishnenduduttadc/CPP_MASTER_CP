#include<bits/stdc++.h>

using namespace std;

void TowerOfHanoi(int n, char from, char helper, char to) {

	if (n == 0) return;

	// cout << n << " " << from << " " << helper << " " << to << '\n';

	TowerOfHanoi(n - 1, from, to, helper);
	// reached here
	// nth rod to to
	cout << from << " -> " << to << '\n';

	TowerOfHanoi(n - 1, helper, from, to);

}

int main()
{
	

	int n=3;
	//cin >> n;

	TowerOfHanoi(n, 'A', 'B', 'C');


	return 0;
}