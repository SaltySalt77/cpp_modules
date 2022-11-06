#include <iostream>
#include <string>
#include <cctype>

/* 로직 고민
1. argc 개수 세기
2. 바꾸고 출력하자 */
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
		megaphone = argv[i];
		j = 0;
		while (megaphone[j]) {
			if (megaphone[j] == 2)
				megaphone.replace(j, 1, megaphone[j] - 32);
			j++;
		}
		std::cout << megaphone << std::endl;
		i++;
	}
	return 0;
}