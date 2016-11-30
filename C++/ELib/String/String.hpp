
#include <string>


namespace Eun {
	template <typename T>
	T ReplaceAll(T str,const T && from,const T && to) {
		int startPos = 0;
		while ((startPos = str.find(from, startPos)) != std::string::npos) {
			str.replace(startPos, from.length(), to);
			startPos += to.length();
		}
		return str;
	}
	template <typename T>
	T ltrim(T && str) {
		return str.erase(0, str.find_first_not_of(" "));
	}
	template <typename T>
	T rtrim(T && str) {
		return str.erase(str.find_last_not_of(" ") + 1, str.length());
	}
	template <typename T>
	T trim(T&&str) {
		return ltrim(rtrim(str));
	}

}
