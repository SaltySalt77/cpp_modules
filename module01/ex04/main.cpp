#include "Sed.hpp"

int	main(int argc, char	**argv) {

	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		*argus = new std::string[4];
	char			*read_buffer;
	std::string		write_buffer;

	if (argc != 4) {
		std::cerr << "usage : <filename> <string to be replaced> <string to replace>" << std::endl;
		return 1;
	}

	int	i = -1;
	while (++i < argc - 1)
		argus[i].append(argv[i + 1]);

	argus[OUTFILE].append(argus[INFILE]);
	argus[OUTFILE].append(".replace");

	infile.open(argus[INFILE]);
	if (infile.fail()) {
		std::cerr << "No such file or directory" << std::endl;
		return 1;
	}

	outfile.open(argus[OUTFILE]);
	if (outfile.fail()) {
		std::cerr << "No such file or directory" << std::endl;
		return 1;
	}

	read_buffer = new char[100];
	write_buffer = "";

	while (!infile.eof()) {
		infile.getline(read_buffer, 100);
		write_buffer.append(read_buffer);
		write_buffer.append("\n");
	}

	unsigned long	idx;
	std::string		tmp;
	while (!write_buffer.empty()) {
		idx = write_buffer.find(argus[FROM_STR], 0);
		if (idx >= write_buffer.size()) {
			outfile << write_buffer;
			break ;
		}
		outfile << write_buffer.substr(0, idx) << argus[TO_STR];
		write_buffer = write_buffer.substr(idx + argus[FROM_STR].size(), write_buffer.size() - argus[FROM_STR].size());
	}

	infile.close();
	outfile.close();
}