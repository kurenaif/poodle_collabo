#include <iostream>
#include <vector>

using namespace std;

int main(void){
	cout << 1 << endl;
	cout << 1 << endl;

	int num; cin >> num;
	vector<int> A(num);
	for(auto &a: A) cin >> a;
	for(auto &a: A) cout << a << " ";

	cout << endl;
	string res; cin >> res;
	cerr << res << endl;
}
