#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

void Foo(string val1, int val2, int val3, int val4, int val5, int val6, int val7, int val8, int val9) {
	cout << val1 << val2 << val3 << val4 << val5 << val6 << val7 << val8 << val9 << endl;
}

void Boo() {
	cout << "Boo" << endl;
}

void Hoo() {
	cout << "Hoo" << endl;
}
void UnHook();
void FNA() {
	Boo();
	UnHook();
	Foo("Test", 1, 2, 3, 4, 5, 6, 7, 8);
	Hoo();
}

DWORD relativityFunctoin(std::uint64_t orginFn, std::uint64_t newOrg) {
	return newOrg - orginFn - 5;
}


const int FUN_SIZE = 5;
std::vector<char> orginCord(FUN_SIZE, 0);
void UnHook() {
	DWORD oldProect;
	VirtualProtect((LPVOID)Foo, FUN_SIZE, PAGE_EXECUTE_READWRITE, &oldProect);
	memcpy(Foo, orginCord.data(), FUN_SIZE);
	VirtualProtect((LPVOID)Foo, FUN_SIZE, oldProect, &oldProect);

}
void Hook() {

	DWORD oldProect;
	VirtualProtect((LPVOID)Foo, FUN_SIZE, PAGE_EXECUTE_READWRITE, &oldProect);

	memcpy(orginCord.data(), (void*)Foo, FUN_SIZE);

	BYTE pBuf[5] = { 0xE9,0, };
	DWORD jmpaddress = relativityFunctoin((std::uint64_t)Foo, (std::uint64_t)FNA);
	memcpy(&pBuf[1], &jmpaddress, 4);


	memcpy(Foo, pBuf, FUN_SIZE);
	VirtualProtect((LPVOID)Foo, FUN_SIZE, oldProect, &oldProect);
}
void Koo() {
	Hook();
}
void wmain() {
	Koo();
	Foo("Test", 1, 2, 3, 4, 5, 6, 7, 8);

}