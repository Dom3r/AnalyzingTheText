/**
 * @file structs.h
 * @brief plik zawieraj¹cy strutury
 */
#pragma once
#include <stdio.h>

 /** Struktura Listy */
typedef struct List {
	char* word; ///< s³owo
	int length; ///< d³ugoœæ s³owa
	int frequency; ///< iloœæ wyst¹pnieñ s³owa
	struct List* next; ///< wskaŸnik na nastêpny element
} List_t;

/** Strutura Drzewa poszukiwañ binarnych */
typedef struct BinarySearchTree {
	int frequency; ///< iloœæ wyst¹pnieñ s³owa
	int length; ///< d³ugoœæ s³owa
	char* word; ///< s³owo
	struct BinarySearchTree* left; ///< wskaŸniki na lewego potomka
	struct BinarySearchTree* right; ///< wskaŸniki na prawego potomka
	struct BinarySearchTree* middle; ///< wskaŸniki na œrodkowego potomka
} BinarySearchTree_t;