#include "file.h" 

void getWords(FILE* file, List_t** WordsHead)
{
	List_t* wordsHead = *WordsHead;
	char character;
	char word[50];
	int i = 0;
	while (fread(&character, sizeof(char), 1, file))
	{
		if ((character > 31 && character < 48) || (character > 58 && character < 65) || (character > 90 && character < 97) || (character > 122 && character < 127)) {
			if (i == 0) {
				word[i] = character;
				word[i + 1] = '\0';
				addToList(&wordsHead, word, 0);
			}
			else {
				word[i] = '\0';
				addToList(&wordsHead, word, strlen(word));
				memset(word, 0, sizeof word);
				i = 0;
				word[i] = character;
				word[i + 1] = '\0';
				addToList(&wordsHead, word, 0);
				memset(word, 0, sizeof word);
				i = 0;
			}
		}
		else
		{
			word[i] = character;
			i++;
		}
	}
	*WordsHead = wordsHead;
}


void saveLengthToFile(FILE* file, BinarySearchTree_t* Root)
{
	if (Root != NULL) {
		saveLengthToFile(file, Root->left);
		fprintf(file, "%d \t| %d \n", Root->length, Root->frequency);
		saveLengthToFile(file, Root->right);
	}
}

void saveFreqToFile(FILE* file, BinarySearchTree_t* Root, int* amount)
{
	if (Root != NULL) {
		if (*amount > 0)
			saveFreqToFile(file, Root->right, &*amount);
		if (*amount > 0) {
			fprintf(file, "%s  | %d | %d \n", Root->word, Root->length, Root->frequency);
			--* amount;
		}
		if (*amount > 0)
			saveFreqToFile(file, Root->middle, &*amount);
		if (*amount > 0)
			saveFreqToFile(file, Root->left, &*amount);
	}
}
