//#include<bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <vector>

#define N 102
using namespace std;


int main()
{
	int a[N], b[N];
	int n = 0, i, j, k,e, sum = 0;
	//存储小和尚
	string s;
	getline(cin, s);
	istringstream ss(s);
	while (ss >> e) {
		a[n++] = e;
	}
	//进行Nim博弈的转换
	for (i = 1; i < n; i++)
		b[i - 1] = a[i] - a[i - 1] - 1;
	//进行异或
	for (i = 0; i < n - 1; i+=2)
		sum ^= b[i];
	//若开始局面为0，必输
	if (sum == 0)
		cout << -1 << endl;
	else {
		for(i=0;i<n-1;++i)
			for (j = 1; a[i] + j < a[i + 1]; ++j) {
				b[i] -= j;
				if (i != 0)
					b[i - 1] += j;
				sum = 0;
				for (k = 0; k < n - 1; k += 2)
					sum ^= b[k];
				if (sum == 0) {
					cout << a[i] << " " << a[i] + j << endl;
					break;
				}
				b[i] += j;
				if (i != 0)
					b[i - 1] -= j;
			}
	}
	
	return 0;
}