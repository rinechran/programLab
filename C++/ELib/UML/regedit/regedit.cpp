#include <iostream>
#include <Windows.h>
#include <string>
namespace Eun {
	namespace Windows {
		struct KEY {
			constexpr static HKEY CLASSES_ROOT = HKEY_CLASSES_ROOT;
			constexpr static HKEY LOCAL_MACHINE = HKEY_LOCAL_MACHINE;
			constexpr static HKEY CURRENT_USER = HKEY_CURRENT_USER;
			constexpr static HKEY USERS = HKEY_USERS;
			constexpr static HKEY CURRENT_CONFIG = HKEY_CURRENT_CONFIG;


		};
		struct KEYACCESS {
			constexpr static REGSAM ALL_ACCESS = KEY_ALL_ACCESS;
			constexpr static REGSAM CREATE_LINK = KEY_CREATE_LINK;
			constexpr static REGSAM CREATE_SUB_KEY = KEY_CREATE_SUB_KEY;
			constexpr static REGSAM ENUMERATE_SUB_KEYS = KEY_ENUMERATE_SUB_KEYS;
			constexpr static REGSAM EXECUTE = KEY_EXECUTE;
			constexpr static REGSAM NOTIFY = KEY_NOTIFY;
			constexpr static REGSAM QUERY_VALUE = KEY_QUERY_VALUE;
			constexpr static REGSAM READ = KEY_READ;
			constexpr static REGSAM SET_VALUE = KEY_SET_VALUE;
			constexpr static REGSAM WOW64_32KEY = KEY_WOW64_32KEY;
			constexpr static REGSAM WOW64_64KEY = KEY_WOW64_64KEY;
			constexpr static REGSAM WRITE = KEY_WRITE;
		};
		struct REG {
			constexpr static int NONE = REG_NONE;
			constexpr static int SZ = REG_SZ;
			constexpr static int EXPAND_SZ = REG_EXPAND_SZ;
			constexpr static int BINARY = REG_BINARY;
			constexpr static int DWORD = REG_DWORD;
			constexpr static int DWORD_LITTLE_ENDIAN = REG_DWORD_LITTLE_ENDIAN;
			constexpr static int DWORD_BIG_ENDIAN = REG_DWORD_BIG_ENDIAN;
			constexpr static int LINK = REG_LINK;
			constexpr static int MULTI_SZ = REG_MULTI_SZ;
			constexpr static int RESOURCE_LIST = REG_RESOURCE_LIST;
			constexpr static int FULL_RESOURCE_DESCRIPTOR = REG_FULL_RESOURCE_DESCRIPTOR;
			constexpr static int QWORD = REG_QWORD;
			constexpr static int QWORD_LITTLE_ENDIAN = REG_QWORD_LITTLE_ENDIAN;
		};
		//HKEY KEY::CLASSES_ROOT = HKEY_CLASSES_ROOT;
		class Regedit {
		public:
			Regedit() {

			}
			bool isError(LONG &result) {
				if (lResult != ERROR_SUCCESS){
					if (lResult == ERROR_FILE_NOT_FOUND) 
						printf("Key not found.\n");
					else 
						printf("Error opening key.\n");
					return false;}
				return true;
			}
			bool openKey(HKEY key, std::wstring SubKey, REGSAM regsam) {
				lResult = RegOpenKeyEx(key, SubKey.c_str(), 0, regsam, &mKey);
				if (isError(lResult) != true)
					return false;
				return true;
			}

			~Regedit() {
				RegCloseKey(mKey);
			}
		private:
			LONG lResult;
			HKEY mKey;

		};
	}

	
}
