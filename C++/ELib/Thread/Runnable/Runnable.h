#pragma once

#include <thread>
#include <atomic>

namespace Eun {

	class Runnable {
	public:
		Runnable();
		void start();
		void stop();
		~Runnable();
	protected:
		Runnable(const Runnable&& oth) = delete;
		Runnable& operator=(const Runnable && oth) = delete;
		virtual void run() = 0;
		std::atomic<bool> is;
		std::thread _th;
	};
}