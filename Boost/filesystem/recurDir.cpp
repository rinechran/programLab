#include <iostream>
#include <boost/filesystem.hpp>
#include <string>
#include <vector>

using namespace boost::filesystem;
using namespace std;


void recurDir(path p) {
	vector<path> dir{ p };

	if (!exists(p)) return;
	for (auto i = 0; i != dir.size();i++) {
		for (directory_entry& j : directory_iterator(dir[i])) {
			if (is_directory(j)) dir.push_back(j);
			else cout << j.path() << endl;
		}
	}

}
int main(int argc, char* argv[])
{
	
	if (argc < 2) {
		std::cout << "Use Path argc" << std::endl;
		return 0;
	}

	recurDir(argv[1]);
	

}