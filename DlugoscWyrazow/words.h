/**
 * @file words.h
 * @brief plik z funckjami zawieraj�cymi operacje na strukturach
 */
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

 /** Funkcja zwracaj�ca ilo�� pojawienia si� danego s�owa i usuwaj�ca �rodkowego potomka
  @param Root korze� drzewa
  @return ilo�� pojawienia si� danego s�owa
  */
int cutNode(BinarySearchTree_t** Root);

/** Funkcja dodaj�ca s�owo do drzewa
 @param Root korze� drzewa
 @param word s�owo kt�re ma zosta� zapisane
 @param mode znak okre�laj�cy typ drzewa, 'l' dla drzewa d�ugo�ci, 'f' dla drzewa cz�stotliwo�ci
 */
void addToTree(BinarySearchTree_t** Root, List_t* word, char mode);

/** Funkcja dodaj�ca s�owo listy
 @param Head g�owa listy
 @param word s�owo kt�re ma zosta� zapisane
 @param length d�ugo�� s�owa
 */
void addToList(List_t** Head, char* word, int length);

/** Funkcja tworz�ca drzewo
 @param Head g�owa listy
 @param Root korze� drzewa
 @param mode znak okre�laj�cy typ drzewa, 'l' dla drzewa d�ugo�ci, 'f' dla drzewa cz�stotliwo�ci
 */
void createTree(List_t** Head, BinarySearchTree_t** Root, char mode);

/** Funkcja skracaj�ca drzewo o �rodkowego potomka
 @param Root korze� drzewa
 */
void reduceTree(BinarySearchTree_t** Root);

/** Funkcja wy�wetlaj�ca s�owa posortowane
 @param Root korze� drzewa
 @param amount ilo�� element�w kt�re maj� zosta� zapisane
 */
void printWordsSorted(BinarySearchTree_t* Root, int* amount);

/** Funkcja wy�wetlaj�ca d�ugo�ci posortowane
 @param Root korze� drzewa
 */
void printLenghtSorted(BinarySearchTree_t* Root);

/** Funkcja usuwaj�ca liste
 @param Head g�owa listy
 */
void freeList(List_t** Head);

/** Funkcja usuwaj�ca drzewo
 @param Root korze� drzewa
 */
void freeTree(BinarySearchTree_t** Root);