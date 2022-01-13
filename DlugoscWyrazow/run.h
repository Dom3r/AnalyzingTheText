/**
 * @file run.h
 * @brief plik z funkcj¹ dzia³ania programu
 */
#pragma once
#include "words.h"
#include "file.h"

#include <stdbool.h>

 /** Funkcja zapisuj¹ca s³owa z pliku do listy 
  @param inFile plik wejœciowy
  @param outFile plik wyjœciowy
  @param amount iloœæ elementów które maj¹ zostaæ zapisane/wyœwietlone
  @param print wartoœæ binarna okreœlaj¹ca czy wyjœcie ma zostaæ wyœwietlona na ekranie
  */
void run(FILE* inFile, FILE* outFile, int amount, bool print);