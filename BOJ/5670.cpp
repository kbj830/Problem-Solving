#include <iostream>
#include <string>
#include <vector>
#include <map>

#define endl '\n'

using namespace std;

struct Trie {
	bool isFinished;
	map<char, Trie> child;
};

void insert(Trie &node, string &word, int idx) {
	if (idx == word.size()) {
		node.isFinished = true;
		return;
	}
	
	if (node.child.count(word[idx]) == 0) {
		node.child[word[idx]] = Trie();
		node.child[word[idx]].isFinished = false;
	}
	
	insert(node.child[word[idx]], word, idx + 1);
}

int cntInput(Trie &node, string &word, int idx) {
	if (idx == word.size())
		return 0;
	
	if (node.child.size() > 1 || idx == 0)
		return cntInput(node.child[word[idx]], word, idx + 1) + 1;
	
	if (node.child.size() == 1 && node.isFinished == true)
		return cntInput(node.child[word[idx]], word, idx + 1) + 1;
	
	return cntInput(node.child[word[idx]], word, idx + 1);
}

void solve() {
	int n;
	
	while (cin >> n) {
		vector <string> words;
		int sum = 0;
		
		Trie trie;
		for (int i = 0; i < n; i++) {
			string word;
			cin >> word;
			words.push_back(word);
			insert(trie, word, 0);
		}
		
		for (int i = 0; i < words.size(); i++)
			sum += cntInput(trie, words[i], 0);
		
		cout << fixed;
		cout.precision(2);
		cout << double(sum)/words.size() << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
