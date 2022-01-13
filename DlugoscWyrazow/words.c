#include "words.h"

int cutNode(BinarySearchTree_t** Root) {
	BinarySearchTree_t* root = *Root;
	if (root == NULL) {
		return 0;
	}
	int frequency = root->frequency + cutNode(&root->middle);
	root->middle = NULL;
	free(root);

	return frequency;
}

void addToTree(BinarySearchTree_t** Root, List_t* word, char mode)
{
	BinarySearchTree_t* root = *Root;
	if (root == NULL) {
		root = (BinarySearchTree_t*)malloc(sizeof(BinarySearchTree_t));
		root->word = calloc(strlen(word->word) + 1, sizeof(char));
		memcpy(root->word, word->word, strlen(word->word) + 1);
		root->length = word->length;
		root->frequency = word->frequency;
		root->left = root->right = root->middle = NULL;
		*Root = root;
	}
	else
	{
		if (mode == 'f') {
			if (root->frequency > word->frequency)
				addToTree(&root->left, word, 'f');
			else if (root->frequency == word->frequency)
				addToTree(&root->middle, word, 'f');
			else
				addToTree(&root->right, word, 'f');
		}
		else if (mode == 'l') {
			if (root->length > word->length)
				addToTree(&root->left, word, 'l');
			else if (root->length == word->length)
				addToTree(&root->middle, word, 'l');
			else
				addToTree(&root->right, word, 'l');
		}

	}
}

void addToList(List_t** Head, char* word, int length)
{
	List_t* head = *Head;

	if (head == NULL) {
		head = (List_t*)malloc(sizeof(List_t));
		if (word[0] > 64 && word[0] < 91)
			word[0] += 32;
		head->word = calloc(strlen(word) + 1, sizeof(char));
		memcpy(head->word, word, strlen(word) + 1);
		head->length = length;
		head->frequency = 1;
		head->next = NULL;
	}
	else
	{
		List_t* first = head;
		while (head->next != NULL && strcmp(word, head->word))
			head = head->next;

		if (!strcmp(word, head->word)) {
			head->frequency++;
		}
		else if (head->next == NULL) {
			head->next = (List_t*)malloc(sizeof(List_t));
			if (word[0] > 64 && word[0] < 91)
				word[0] -= 32;
			head->next->word = calloc(strlen(word) + 1, sizeof(char));
			memcpy(head->next->word, word, strlen(word) + 1);
			head->next->length = length;
			head->next->frequency = 1;
			head->next->next = NULL;
		}
		head = first;
	}
	*Head = head;
}

void createTree(List_t** Head, BinarySearchTree_t** Root, char mode)
{
	List_t* head = *Head;
	List_t* first = *Head;

	addToTree(&*Root, head, mode);
	BinarySearchTree_t* node = *Root;
	head = head->next;
	while (head != NULL)
	{
		addToTree(&node, head, mode);
		head = head->next;
	}
	*Head = first;
}

void reduceTree(BinarySearchTree_t** Root)
{
	BinarySearchTree_t* root = *Root;
	if (root != NULL) {
		root->frequency = root->frequency + cutNode(&root->middle);
		root->middle = NULL;
		reduceTree(&root->left);
		reduceTree(&root->right);
	}
}

void printWordsSorted(BinarySearchTree_t* Root, int* amount)
{
	if (Root != NULL) {
		if (*amount > 0)
			printWordsSorted(Root->right, &*amount);
		if (*amount > 0)
			printWordsSorted(Root->middle, &*amount);
		if (*amount > 0) {
			printf(" %s \t | %d \t | %d\n", Root->word, Root->frequency, Root->length);
			--* amount;
		}
		if (*amount > 0)
			printWordsSorted(Root->left, &*amount);
	}
}

void printLenghtSorted(BinarySearchTree_t* Root)
{
	if (Root != NULL) {
		printLenghtSorted(Root->left);
		printf(" %d \t | %d\n", Root->length, Root->frequency);
		printLenghtSorted(Root->right);
	}
}




void printWords(List_t* Head) {
	//List_t* head = *Head;
	while (Head != NULL)
	{
		printf("%s | %d | %d\n", Head->word, Head->frequency, Head->length);
		Head = Head->next;
	}
}


void freeList(List_t** Head)
{
	List_t* head = *Head;
	if (head != NULL) {
		freeList(&head->next);
		free(head);
	}
}

void freeTree(BinarySearchTree_t** Root)
{
	BinarySearchTree_t* root = *Root;
	if (root != NULL) {
		freeTree(&root->left);
		freeTree(&root->middle);
		freeTree(&root->right);
		free(root);
	}
} 