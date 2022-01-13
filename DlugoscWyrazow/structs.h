/**
 * @file structs.h
 * @brief plik zawieraj�cy strutury
 */
#pragma once
#include <stdio.h>

 /** Struktura Listy */
typedef struct List {
	char* word; ///< s�owo
	int length; ///< d�ugo�� s�owa
	int frequency; ///< ilo�� wyst�pnie� s�owa
	struct List* next; ///< wska�nik na nast�pny element
} List_t;

/** Strutura Drzewa poszukiwa� binarnych */
typedef struct BinarySearchTree {
	int frequency; ///< ilo�� wyst�pnie� s�owa
	int length; ///< d�ugo�� s�owa
	char* word; ///< s�owo
	struct BinarySearchTree* left; ///< wska�niki na lewego potomka
	struct BinarySearchTree* right; ///< wska�niki na prawego potomka
	struct BinarySearchTree* middle; ///< wska�niki na �rodkowego potomka
} BinarySearchTree_t;