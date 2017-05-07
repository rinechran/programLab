#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <future>
#include <functional>
#include <iostream>

using namespace std;

template <typename T>
class Eventer {
public:

	Eventer() = default;

	template <typename Func,typename ...Args>
	void AddListener(Func && func, Args && ... args) {
		auto tesk = [&]()->void {func(args...);  };
		event.push_back(Node {tesk} );
	}
	void start() {
		for (auto &i = event.begin(); i != event.end();++i) {
			i->func();
		}
	}

private:
	struct Node {
		std::function<void()> func;
	};
	std::vector<Node> event;

};

