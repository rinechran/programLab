#include <iostream>
#include <cassert>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;
class AI {
public:
	virtual ~AI() = default;
	virtual void think() = 0;
};
class EasyAi : public AI {
public:
	virtual void think() override {
		cout << "Easy Ai" << endl;
	}
};
class NormalAi : public AI {
public:
	virtual void think() override {
		cout << "Normal Ai" << endl;

	}
};

class HardAi : public AI {
public:
	virtual void think() override {
		cout << "Hard Ai" << endl;
	}
};

class ComPlayer {
public:
	ComPlayer(AI * ai):ai(ai) {
	}
	void think() {
		ai->think();
	}

	ComPlayer() {
		delete ai;
	}

private:
	AI * ai;
};
int main() {
	ComPlayer CP(new HardAi);

	CP.think();


}
