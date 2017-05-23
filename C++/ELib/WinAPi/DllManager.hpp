#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

using namespace std::string_literals;

namespace KUDE {
	class Dllmanager {
		using WinFuncAddr = WINBASEAPI FARPROC WINAPI;
	public:
		Dllmanager();

		template <class T>
		void loadDll(T && filePath);
		void FreeDll();
		template <class T>
		WinFuncAddr getProcAddress(T && functionName);
		~Dllmanager();
	private:
		HINSTANCE mHistance;
	};

}

template<class T>
void KUDE::Dllmanager::loadDll(T && filePath) {
	mHistance = LoadLibrary(filePath.c_str());
}
template<class T>
WinFuncAddr KUDE::Dllmanager::getProcAddress(T && functionName) {
	if (mHistance) return GetProcAddress(mHistance, functionName);
	return nullptr;

}

KUDE::Dllmanager::Dllmanager() : mHistance(nullptr) {}

void KUDE::Dllmanager::FreeDll() {
	if (mHistance == nullptr) {
		return;
	}
	FreeLibrary(mHistance);
	mHistance = nullptr;
}

KUDE::Dllmanager::~Dllmanager() {
	if (mHistance) // not null
		FreeLibrary(mHistance);

}
