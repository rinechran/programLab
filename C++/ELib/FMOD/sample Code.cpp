#include <iostream>
#include "EunPlayer.hpp"

int main() {
	EunPlayer musicPlyer;
	musicPlyer.FilePush("temp.mp3");
	musicPlyer.playSound("temp.mp3");
	char x;
	while (true) {
		std::cout << "Music play start : s" << std::endl;
		std::cout << "Music play pause : p" << std::endl;
		std::cout << "Music play exit : q" << std::endl;
		std::cout << "Press : ";
		std::cin >> x;
		switch (x)
		{
		case 'p':
			musicPlyer.setPaused(true);
			break;
		case 's':
			musicPlyer.setPaused(false);
			break;
		case 'q':
			return 0;
		default:
			break;
		}

	}

	
}