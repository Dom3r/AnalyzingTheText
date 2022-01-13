/**
 * @file file.h
 * @brief plik z funkcjami obs�uguj�cymi pliki
 */
#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "structs.h"
#include "words.h"

 /** Funkcja zapisuj�ca s�owa z pliku do listy
  @param file plik wej�ciowy
  @param WordsHead g�owa listy
  */
void getWords(FILE* file, List_t** WordsHead);

/** Funkcja zapisuj�ca drzewo d�ugo�ci do listy
 @param file plik wyj�ciowy
 @param Root korze� drzewa
 */
void saveLengthToFile(FILE* file, BinarySearchTree_t* Root);

/** Funkcja zapisuj�ca drzewo cz�stotliwo�ci do listy
 @param file plik wyj�ciowy
 @param Root korze� drzewa
 @param amount ilo�� element�w kt�re maj� zosta� zapisane
 */
void saveFreqToFile(FILE* file, BinarySearchTree_t* Root, int* amount);