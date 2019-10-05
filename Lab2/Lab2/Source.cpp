#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

class Node {
public:
	char value;
	int count;
	Node* left;
	Node* right;

	Node(Node*& left, Node*& right, int count) {
		this->left = left;
		this->right = right;
	}

	Node(char value, int count) {
		this->value = value;
		this->count = count;
		left = 0;
		right = 0;
	}

	Node(int count) {
		this->count = count;
	}

	Node* operator()(Node*& left, Node*& right) {
		return new Node(left, right, left->count + right->count);
	}
};

Node* buildTree(vector<Node*> nodes) {
	vector<Node*> bufNodes;
	Node* a = nodes[0];
	Node* b = nodes[1];
	Node* res = (a, b);
	for (vector<Node*>::iterator i = nodes.begin(); i != nodes.end(); i++) {
		if (res->count > )
	}
}

bool compare(pair<char, int> a, pair<char, int> b) {
	return a.second < b.second;
}

int mas[256];
vector<pair<char, int>> mas2;
list<Node<char>*> nodes;

int main() {
	string s;
	cin >> s;
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
		nodes.push_back(new Node<char>(mas2[i].first, mas2[i].second));
	}

}