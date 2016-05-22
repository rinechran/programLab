#include <iostream>
#include <boost/filesystem.hpp>
#include <string>


using namespace boost::filesystem;
using namespace std;
int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cout << "Use Path argc" << std::endl;
		return 0;
	}

	boost::filesystem::path p(argv[1]);

	if (exists(p)) {
		if (is_regular_file(p))
			cout << "File size : " << file_size(p) << endl;
		else if (is_directory(p))
			cout << argv[1] << " is Directory" << endl;
		else
			cout << "Error" << endl;
	}

}