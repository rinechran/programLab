#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <codecvt>

using namespace std::string_literals;

namespace KUDE {
	class DllManager {
		//using WinFuncAddr = ;
	public:
		DllManager();

		void loadDll(std::string &  filePath);
		void FreeDll();

		void* getProcAddress(std::string &  functionName);


		~DllManager();
	private:
		HINSTANCE mHistance;

	};

};

void* KUDE::DllManager::getProcAddress(std::string &  functionName) {
	if (mHistance)  return GetProcAddress(mHistance, functionName.c_str());
	return nullptr;
}
KUDE::DllManager::DllManager() : mHistance(nullptr) {}

void KUDE::DllManager::loadDll(std::string & filePath) {

	mHistance = LoadLibraryA(filePath.c_str());
}

void KUDE::DllManager::FreeDll() {
	if (mHistance == nullptr) {
		return;
	}
	FreeLibrary(mHistance);
	mHistance = nullptr;
}

KUDE::DllManager::~DllManager() {
	if (mHistance) // not null
		FreeLibrary(mHistance);

}
