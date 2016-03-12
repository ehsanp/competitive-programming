#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

class CliqueParty
{
public:
	int maxsize(vector <int> a, int k)
	{
		int n = a.size();
		sort(a.begin(), a.end());
		int ans = 1;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
			{
				int x = (a[j] - a[i] + k - 1) / k;
				int ptr = i + 1, lst = a[i], cans = 2;
				while (ptr < j)
				{
					if (a[ptr] - lst >= x && a[j] - a[ptr] >= x)
					{
						lst = a[ptr];
						cans ++;
					}
					ptr ++;
				}
				ans = max(ans, cans);
			}
		return ans;
	}
};
