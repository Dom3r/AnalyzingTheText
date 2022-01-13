/**
 * @file words.h
 * @brief plik z funckjami zawieraj¹cymi operacje na strukturach
 */
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

 /** Funkcja zwracaj¹ca iloœæ pojawienia siê danego s³owa i usuwaj¹ca œrodkowego potomka
  @param Root korzeñ drzewa
  @return iloœæ pojawienia siê danego s³owa
  */
int cutNode(BinarySearchTree_t** Root);

/** Funkcja dodaj¹ca s³owo do drzewa
 @param Root korzeñ drzewa
 @param word s³owo które ma zostaæ zapisane
 @param mode znak okreœlaj¹cy typ drzewa, 'l' dla drzewa d³ugoœci, 'f' dla drzewa czêstotliwoœci
 */
void addToTree(BinarySearchTree_t** Root, List_t* word, char mode);

/** Funkcja dodaj¹ca s³owo listy
 @param Head g³owa listy
 @param word s³owo które ma zostaæ zapisane
 @param length d³ugoœæ s³owa
 */
void addToList(List_t** Head, char* word, int length);

/** Funkcja tworz¹ca drzewo
 @param Head g³owa listy
 @param Root korzeñ drzewa
 @param mode znak okreœlaj¹cy typ drzewa, 'l' dla drzewa d³ugoœci, 'f' dla drzewa czêstotliwoœci
 */
void createTree(List_t** Head, BinarySearchTree_t** Root, char mode);

/** Funkcja skracaj¹ca drzewo o œrodkowego potomka
 @param Root korzeñ drzewa
 */
void reduceTree(BinarySearchTree_t** Root);

/** Funkcja wyœwetlaj¹ca s³owa posortowane
 @param Root korzeñ drzewa
 @param amount iloœæ elementów które maj¹ zostaæ zapisane
 */
void printWordsSorted(BinarySearchTree_t* Root, int* amount);

/** Funkcja wyœwetlaj¹ca d³ugoœci posortowane
 @param Root korzeñ drzewa
 */
void printLenghtSorted(BinarySearchTree_t* Root);

/** Funkcja usuwaj¹ca liste
 @param Head g³owa listy
 */
void freeList(List_t** Head);

/** Funkcja usuwaj¹ca drzewo
 @param Root korzeñ drzewa
 */
void freeTree(BinarySearchTree_t** Root);