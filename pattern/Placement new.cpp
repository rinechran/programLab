#include <iostream>
#include <Windows.h>

using namespace std;
class CVSPerson {
public:
	char m_Name[1];
};

int main() {
	
	char * str = "my name ....";
	CVSPerson * pCvsPerson = new CVSPerson[strlen(str) + sizeof(pCvsPerson)];
	strcat(pCvsPerson->m_Name, str);
	std::cout << pCvsPerson->m_Name;
		
}

