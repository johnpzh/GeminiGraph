#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

typedef int32_t idi;

void convert(char *input_filename, char *output_filename)
{
	std::ifstream fin(input_filename);
	if (!fin.is_open()) {
		fprintf(stderr, "Error: cannot open file %s\n", input_filename);
		exit(EXIT_FAILURE);
	}

	std::ofstream fout(output_filename);
	if (!fout.is_open()) {
		fprintf(stderr, "Error: cannot create file %s\n", output_filename);
		exit(EXIT_FAILURE);
	}

	std::string line;
	idi  head;
	idi tail;
	uint64_t num_edges = 0;
	uint64_t num_v = 0;

	while (std::getline(fin, line)) {
		if (line[0] == '#' || line[0] == '%') {
			continue;
		}
		std::istringstream iss(line);
		iss >> head >> tail;
		fout.write(reinterpret_cast<char *>(&head), sizeof(head));
		fout.write(reinterpret_cast<char *>(&tail), sizeof(tail));
		++num_edges;
		num_v = std::max(num_v, std::max(head, tail) + (uint64_t) 1);
		//num_v = std::max(num_v, std::max(head, tail) + reinterpret_cast<uint64_t>(1));
	}
	std::cout << "num_v: " << num_v << " num_edges: " << num_edges << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		fprintf(stderr, "Usage: ./edgelist2binary <input_file> <output_file>\n");
		exit(EXIT_FAILURE);
	}

	convert(argv[1], argv[2]);

	return EXIT_SUCCESS;
}
