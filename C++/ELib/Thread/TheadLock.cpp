#include "TheadLock.h"

 Eun::TheadLock::SpinLock::SpinLock() : _object(false) {
}

void Eun::TheadLock::SpinLock::enterSection() {
	while (InterlockedExchange(&this->_object, 1) == 1) continue;
}

void Eun::TheadLock::SpinLock::leaveSection() {
	InterlockedExchange(&this->_object, 0);
}
