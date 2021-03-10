#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>

using namespace std;
class CVSPerson {
public:
	char m_Name[1];
};

int main() {

	char str[] = "my name ....";

	CVSPerson* pCvsPerson = new CVSPerson[strlen(str) + 1];
	strcpy(pCvsPerson->m_Name, str);
	std::cout << pCvsPerson[0].m_Name;

	delete []pCvsPerson;

}