#include <iostream>
#include <cassert>
#include <algorithm>
#include <string>
#include <list>

using namespace std;


class Node {
public:
	void addChild(Node * oth) {
		node.push_back(oth);
	}
	void update(float T) {
		doUpdate(T);
		for_each(node.begin(), node.end(), [=](Node * node) {node->doUpdate(T);});
	}

	virtual void doUpdate(float T) {
		cout << "node" << endl;
	}
	virtual ~Node() {
		for_each(node.begin(), node.end(), [=](Node * node) {delete node;});
		node.clear();
	}

protected:
	list<Node*> node;
};

class Player : public Node {
	void doUpdate(float T) override {
		cout << "Player" << endl;
	}
	~Player() {
		cout << "~Player" << endl;

	}
};
class Bomb : public Node {
	void doUpdate(float T) override {
		cout << "Bomb" << endl;
	}
	~Bomb() {
		cout << "~Bomb" << endl;
	}
};
int main() {
	Node node;
	node.addChild(new Player);
	node.addChild(new Bomb);
	node.addChild(new Bomb);
	node.update(30);

}
