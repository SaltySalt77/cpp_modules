#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	int			i;
	int			j;
	std::string	megaphone;

	i = 1;	
	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEDDBACK NOISE *" << std::endl;
		return 0;
	}
	while (i < argc) {
		j = 0;
		megaphone.clear();
		while (argv[i][j]) {
			megaphone.push_back((char) std::toupper((int) argv[i][j]));
			j++;
		}
		std::cout << megaphone;
		i++;
	}
	std::cout << std::endl;
	return 0;
}