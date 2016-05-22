#include <iostream>
#include <boost/filesystem.hpp>
#include <string>
#include <exception>

using namespace boost::filesystem;
using namespace std;
int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cout << "Use Path argc" << std::endl;
		return 0;
	}

	boost::filesystem::path p(argv[1]);

	try {
		if (exists(p)) {
			
			if (is_regular_file(p)) {
				cout << p << file_size(p) << endl;
			}
			else if (is_directory(p)) {

				for (auto &i = directory_iterator(p);i != directory_iterator();i++){	
					cout << *i << endl;;
				}
				for (directory_entry& x : directory_iterator(p))
					cout << "    " << x.path() << '\n';
			}
		}
	}
	catch (exception &e) {
		cout << e.what();
	}

}