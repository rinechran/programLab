#include "Runnable.h"

Eun::Runnable::Runnable() : is(false) {}

void Eun::Runnable::start() {
	is = true;
	_th = std::thread(&Runnable::run, this);
}

void Eun::Runnable::stop() {
	is = false;
	_th.join();
}

Eun::Runnable::~Runnable()
{
	stop();
}
