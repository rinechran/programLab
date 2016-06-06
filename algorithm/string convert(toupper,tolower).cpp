#include <string>
#include <algorithm>
using namespace std;

void ToLower(std::string& str) {
	bool bStartExtesion = false;
	std::string::iterator it = str.begin();
	while (it != str.end()) {
		unsigned char ch = *it;
		if (bStartExtesion) {
			bStartExtesion = false;
		}
		else {
			if (ch < 128 & !bStartExtesion)
				*it = tolower(ch);
			else
				bStartExtesion = true;
		}
		it++;
	}
}

void ToUpwer(std::string& str) {
	bool bStartExtesion = false;
	std::string::iterator it = str.begin();
	while (it != str.end()) {
		unsigned char ch = *it;
		if (bStartExtesion) {
			bStartExtesion = false;
		}
		else {
			if (ch < 128 & !bStartExtesion)
				*it = toupper(ch);
			else
				bStartExtesion = true;
		}
		it++;
	}
}