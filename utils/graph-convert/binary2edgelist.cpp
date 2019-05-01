#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <string>
#include <sstream>

typedef int32_t idi;

void convert(char *input_filename, char *output_filename, uint64_t num_edges)
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
	idi head;
	idi tail;

	for (uint64_t i = 0; i < num_edges; ++i) {
		fin.read(reinterpret_cast<char *>(&head), sizeof(head));
		fin.read(reinterpret_cast<char *>(&tail), sizeof(tail));
		fout << head << ' ' << tail << std::endl;
	}
}

int main(int argc, char *argv[])
{
	if (argc < 4) {
		fprintf(stderr, "Usage: ./binary2edgelist <input_file> <output_file> <#edges>\n");
		exit(EXIT_FAILURE);
	}

	convert(argv[1], argv[2], strtoul(argv[3], NULL, 0));

	return EXIT_SUCCESS;
}
