#include <Windows.h>
#include <TlHelp32.h>
#include <string>
#include <iostream>
#include <vector>


namespace KUDE {
	class Processor {
	public:

		struct Process {
			std::wstring name;
			DWORD handle;
		};
		std::vector<Process> getProcess() {
			std::vector<Process> process;
			PROCESSENTRY32 pe = {};
			pe.dwSize = sizeof(PROCESSENTRY32);
			HANDLE handle = INVALID_HANDLE_VALUE;
			handle = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
			Process32First(handle, &pe);
			do {
				process.push_back({pe.szExeFile,pe.th32ProcessID});

			} while (Process32Next(handle,&pe));
			CloseHandle(handle);

			return process;
		}

	};
}
