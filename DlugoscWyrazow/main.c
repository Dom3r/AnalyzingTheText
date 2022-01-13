#include <stdio.h>
#include <stdlib.h>
#include "run.h"

int main(int argc, char* argv[])
{

	FILE* Infile = NULL;
	FILE* Outfile = NULL;
	int amount = 0;
	bool print = false;
	// przelaczniki 
	for (int i = 1; i < argc; i++) {
		if (!strcmp(argv[i], "-i")) {
			Infile = fopen(argv[i + 1], "r");
			i++;
		}
		else if (!strcmp(argv[i], "-n")) {
			sscanf(argv[i + 1], "%d", &amount);
			i++;
		}
		else if (!strcmp(argv[i], "-o")) {
			Outfile = fopen(argv[i + 1], "w");
			i++;
		}
		else if (!strcmp(argv[i], "-p")) {
			print = true;
		}
	}
	run(Infile, Outfile, amount, print);


}