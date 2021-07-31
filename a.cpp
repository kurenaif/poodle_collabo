#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 16個ずつの配列に変換する
vector<vector<int> > divide_blocks(vector<int> C) {
	vector<vector<int> > blocks(1);
	for(int i=0;i<C.size();++i) {
		if(blocks.back().size() == 16){
			blocks.push_back(vector<int>());
		}
		blocks.back().push_back(C[i]);
	}
	return blocks;
}

// 16こずつに区切った配列をマージする
vector<int> merge_blocks(vector<vector<int> > blocks) {
	vector<int> res;
	for(const auto &a:blocks){
		for(const auto &b:a){
			res.push_back(b);
		}
	}
	return res;
}

void solve() {
	// prefix
	cout << 9 << endl;
	// suffix
	cout << 1 << endl;

	// cipher input
	int num; cin >> num;
	vector<int> C(num);
	for(auto &a: C) cin >> a;
	auto blocks = divide_blocks(C);

	// ここでblocksを編集してね

	// debug output
	for(const auto &a:blocks){
		for(const auto &b:a){
			cerr << b << " ";
		}
		cerr << endl;
	}

	C = merge_blocks(blocks);

	// cipher output
	for(const auto &a: C) cout << a << " ";
	cout << endl;

	// result
	string res; cin >> res;
	if(res.find("ok") != string::npos){
		cerr << "true" << endl;
	} else{
		cerr << "false" << endl;
	}
}

int main(void){
	for(int i=0;i<1000;i++){
		solve();
	}
}
