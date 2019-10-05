#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
using namespace std;

class Node {
public:
	char value;
	int count;
	Node* left;
	Node* right;

	Node(Node* left, Node* right, int count) {
		this->left = left;
		this->right = right;
		this->count = count;
		value = 0;
	}

	Node(char value, int count) {
		this->value = value;
		this->count = count;
		left = 0;
		right = 0;
	}

	Node(int count) {
		this->count = count;
		value = 0;
		left = 0;
		right = 0;
	}

	Node* merge(Node* right) {
		return new Node(this, right, count + right->count);
	}

	string getCode(Node* cur, char c, string code = "") {
		if (cur->left != 0 || cur->right != 0) {
			string leftCode = getCode(cur->left, c, code + "0");
			string rightCode = getCode(cur->right, c, code + "1");
			if (leftCode == "")
				return rightCode;
			return leftCode;
		}
		else {
			if (cur->value == c)
				return code;
			else
				return "";
		}
	}

	string shifr(string s) {
		ostringstream str;
		for (int i = 0; i < s.size(); i++) {
			str << getCode(this, s[i]) << " ";
		}
		return str.str();
	}
};

bool compare(pair<char, int> a, pair<char, int> b) {
	return a.second < b.second;
}

Node* buildTree(string s) {
	int mas[256] = {};
	vector<pair<char, int>> mas2;
	vector<Node*> nodes;
	for (int i = 0; i < s.size(); i++) {
		mas[s[i]]++;
	}
	for (int i = 0; i < 256; i++) {
		if (mas[i] != 0) {
			mas2.push_back(make_pair(i, mas[i]));
		}
	}
	sort(mas2.begin(), mas2.end(), compare);
	for (int i = 0; i < mas2.size(); i++) {
		nodes.push_back(new Node(mas2[i].first, mas2[i].second));
	}
	while (nodes.size() > 1) {
		vector<Node*> bufNodes;
		Node* a = nodes[0];
		Node* b = nodes[1];
		Node* res = b->merge(a);
		bool buf = false;
		for (int i = 2; i < nodes.size(); i++) {
			if (res->count > nodes[i]->count)
				bufNodes.push_back(nodes[i]);
			else {
				if (!buf) {
					bufNodes.push_back(res);
					buf = true;
				}
				bufNodes.push_back(nodes[i]);
			}
		}
		if (!buf)
			bufNodes.push_back(res);
		nodes = bufNodes;
	}
	return nodes[0];
}

int main() {
	string s;
	cin >> s;
	Node* tree = buildTree(s);
	cout << tree->shifr(s);
}