#include <iostream>


using namespace std;

class Widget {
public:
	virtual void draw() = 0;
	virtual ~Widget() {}
};

class TextField : public Widget {
private:
	int width, height;
public:
	TextField(int w, int h) : width(w), height(h) {

	}
	void draw() {
		std::cout << "TextFiled : " << width << " ." << height << std::endl;
	}
};

class Decorator : public Widget {
private:
	Widget * wid;
public:
	Decorator(Widget*w) : wid(w) {

	}

	void draw() {
		wid->draw();
	}
	Decorator() {
		delete wid;
	}
};

class BorderDecorator : public Decorator {

public:
	BorderDecorator(Widget* w) : Decorator(w) { }
	void draw() {
		Decorator::draw();
		cout << "   BorderDecorator" << '\n';
	}
};
class ScroolDecorator : public Decorator{
public:
	ScroolDecorator(Widget * w) : Decorator(w) {

	}
	void draw() {
		Decorator::draw();
		cout << "   ScrollDecorator" << '\n';
	}

};

int main() {
	Widget * widget = new BorderDecorator(new TextField(10, 20));

	widget->draw();

	delete widget;

}