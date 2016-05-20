#include <iostream>
#include <cassert>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;
enum class Week {
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};
const std::unordered_map<Week, string>  WeektoName = {
	{Week::Sunday,"Sun"},
	{Week::Monday,"Mon" },
	{Week::Tuesday,"Tue" },
	{Week::Wednesday,"Wed" },
	{Week::Thursday,"Thu" },
	{Week::Friday,"Fri" },
	{Week::Saturday,"Sat" }
};
std::string to_string(Week week) {
	assert(WeektoName.find(week) != WeektoName.end());
	return WeektoName.at(week);
}
int main() {

	cout << to_string(Week::Friday) << endl;
	cout << to_string(Week::Thursday) << endl;
	cout << to_string(Week::Saturday) << endl;



}
