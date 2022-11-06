#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	int			i;
	int			j;
	std::string	upperCase;
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
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				megaphone.push_back(argv[i][j] - 32);
			else
				megaphone.push_back(argv[i][j]);
			j++;
		}
		std::cout << megaphone;
		i++;
	}
	std::cout << std::endl;
	return 0;
}