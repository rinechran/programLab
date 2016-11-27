
#include <string>


namespace Eun {
	template <typename T>
	std::basic_string<T> ReplaceAll(std::basic_string<T>&str, const std::basic_string<T>&& from, const std::basic_string<T>&& to) {
		int startPos = 0;
		while ((startPos = str.find(from, startPos)) != std::string::npos) {
			str.replace(startPos, from.length(), to);
			startPos += to.length();
		}
		return str;
	}
}

