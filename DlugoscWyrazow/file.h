/**
 * @file file.h
 * @brief plik z funkcjami obs³uguj¹cymi pliki
 */
#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "structs.h"
#include "words.h"

 /** Funkcja zapisuj¹ca s³owa z pliku do listy
  @param file plik wejœciowy
  @param WordsHead g³owa listy
  */
void getWords(FILE* file, List_t** WordsHead);

/** Funkcja zapisuj¹ca drzewo d³ugoœci do listy
 @param file plik wyjœciowy
 @param Root korzeñ drzewa
 */
void saveLengthToFile(FILE* file, BinarySearchTree_t* Root);

/** Funkcja zapisuj¹ca drzewo czêstotliwoœci do listy
 @param file plik wyjœciowy
 @param Root korzeñ drzewa
 @param amount iloœæ elementów które maj¹ zostaæ zapisane
 */
void saveFreqToFile(FILE* file, BinarySearchTree_t* Root, int* amount);