#include <iostream>
#include <boost/filesystem.hpp>
#include <string>


using namespace boost::filesystem;
int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cout << "Use Path argc" << std::endl;
		return 0;
	}

	std::cout << "File name : " << argv[1] << std::endl;
	std::cout << "File Size : " <<file_size(argv[1]) << std::endl;

}