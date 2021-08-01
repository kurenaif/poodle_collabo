#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 16個ずつの配列に変換する
vector<vector<int> > divide_blocks(vector<int> C) {
  vector<vector<int> > blocks(1);
  for (int i = 0; i < C.size(); ++i) {
    if (blocks.back().size() == 16) {
      blocks.push_back(vector<int>());
    }
    blocks.back().push_back(C[i]);
  }
  return blocks;
}

// 16こずつに区切った配列をマージする
vector<int> merge_blocks(vector<vector<int> > blocks) {
  vector<int> res;
  for (const auto &a : blocks) {
    for (const auto &b : a) {
      res.push_back(b);
    }
  }
  return res;
}

bool solve() {
  // prefix
  cout << 10 << endl;
  // suffix
  cout << 0 << endl;

  // cipher input
  int num;
  cin >> num;
  vector<int> C(num);
  for (auto &a : C) cin >> a;
  auto blocks = divide_blocks(C);

  // ここでblocksを編集してね
  // わかった！
  // 最初から2ブロック目の最後のバイトを特定したい(c2の末尾)
  auto &last_block = blocks[blocks.size() - 1];
  last_block = blocks[1];  // c2

  // debug output
  for (const auto &a : blocks) {
    for (const auto &b : a) {
      fprintf(stderr, "0x%02X ", b);
    }
    fprintf(stderr, "\n");
  }

  C = merge_blocks(blocks);

  // cipher output
  for (const auto &a : C) cout << a << " ";
  cout << endl;

  // result
  string res;
  cin >> res;
  if (res.find("ok") == string::npos) {
    cerr << "ng" << endl;
    return false;
  }
  cerr << "ok" << endl;

  // うまくいったとき == 最後のブロックを書き換えて、verificationも通った！
  // → 最後のひとつ前のブロックの最後のバイトをxとしたときに
  // c2をAESに通したあと(XORの前)のバイトをyとしたときに
  // y = x ^ 16
  // これにc1の最後のバイトzをxorしてあげると、c2に対応する平文(m2)の最後のバイトaが得られる
  auto &c1 = blocks[0];
  auto x = blocks[blocks.size() - 2].back();
  auto y = x ^ 16;
  auto a = y ^ c1.back();
  fprintf(stderr, "ans: %c\n", a);

  return true;
}

int main(void) {
  for (int i = 0; i < 1000; i++) {
    if (solve()) {
      break;
    }
  }
}
