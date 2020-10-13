#include <iostream>
#include <sstream>

using namespace std;

struct node {
	int val;
	node* left;
	node* right;
	node() {
		left = NULL;
		right = NULL;
	}
};
node *res;
string str[105];
int t = 0;
void init(node *&res, int x) {
	if (res == NULL) {
		res = new node;
		res->val = x;
		return;
	}
	if (x < res->val) init(res->left, x);
	else init(res->right, x);
}

int num(int n) {
	stringstream temp;
	temp << n;
	string a;
	temp >> a;
	return a.length();
}

void post(node *res, int idx, int x) {
	if (res->right == NULL && res->left == NULL) {
		for (int i = 0; i < x - 1; i++) str[t] += ".";
		str[t] += "|-";
		stringstream s;
		s << res->val;
		string ss;
		s >> ss;
		str[t] += ss;
		t++;
		return;
	}
	if (res->right != NULL) {
		if (idx == 1)post(res->right, idx + 1, x + num(res->val) + 2);
		else post(res->right, idx + 1, x + num(res->val) + 3);
	}
	if (idx == 1) {
		stringstream s;
		s << res->val;
		string ss;
		s >> ss;
		str[t] += ss;
		str[t] += "-|";
		t++;
	}
	else {
		for (int i = 0; i < x - 1; i++) str[t] += ".";
		str[t] += "|-";
		stringstream s;
		s << res->val;
		string ss;
		s >> ss;
		str[t] += ss;
		str[t] += "-|";
		t++;
	}
	if (res->left != NULL) {
		if (idx == 1)post(res->left, idx + 1, x + num(res->val) + 2);
		else post(res->left, idx + 1, x + num(res->val) + 2);
	}
	return;

}

int main()
{
	int x,e,A[105],n=0;

	string s;
	getline(cin, s);
	istringstream ss(s);
	while (ss >> e) {
		A[n++] = e;
	}
	for(int i=0;i<n;i++){
		init(res, A[i]);
	}
	post(res, 1, 0);
	s = "-|";
	
	
	for (int i = 0; i < t; i++) {
		if (str[i].length() != 0) {
			cout << str[i] << endl;
		}
	}
	return 0;
}