#pragma once
#include <Windows.h>

namespace Eun {

	namespace TheadLock {
		class SpinLock {
		public:
			SpinLock();
			void enterSection();
			void leaveSection();
			volatile unsigned _object;
		};
	}
}