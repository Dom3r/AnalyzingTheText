#include "run.h" 


void run(FILE* inFile, FILE* outFile, int amount, bool print)
{
	BinarySearchTree_t* LengthRoot = NULL;
	BinarySearchTree_t* FreqRoot = NULL;
	List_t* head = NULL;
	if (inFile == NULL) {
		printf("error, file not exists or is not given \n");
		return;
	}
	if (outFile == NULL && print == false) {
		printf("error, program will not run without the appropriate parameters \n");
		return;
	}
	getWords(inFile, &head);
	fclose(inFile);
	createTree(&head, &FreqRoot, 'f');
	createTree(&head, &LengthRoot, 'l');
	freeList(&head);
	reduceTree(&LengthRoot);
	int outAmount = amount;
	int printAmount = amount;
	if (outFile != NULL) {
		if (amount > 0) {
			fprintf(outFile, "%s \t | %s | %s\n", "Word", "Freqency", "Length");
			saveFreqToFile(outFile, FreqRoot, &outAmount);
		}
		fprintf(outFile, "%s \t| %s\n", "Length", "Freqency");
		saveLengthToFile(outFile, LengthRoot);
		fclose(outFile);
	}


	if (print == true) {
		fprintf(stdout, "%s \t | %s | %s\n", "Word", "Length", "Freqency");
		printWordsSorted(FreqRoot, &printAmount);
		fprintf(stdout, "%s \t | %s\n", "Length", "Freqency");
		printLenghtSorted(LengthRoot);
	}
	freeTree(&FreqRoot);
	freeTree(&LengthRoot);
}