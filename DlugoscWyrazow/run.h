/**
 * @file run.h
 * @brief plik z funkcj� dzia�ania programu
 */
#pragma once
#include "words.h"
#include "file.h"

#include <stdbool.h>

 /** Funkcja zapisuj�ca s�owa z pliku do listy 
  @param inFile plik wej�ciowy
  @param outFile plik wyj�ciowy
  @param amount ilo�� element�w kt�re maj� zosta� zapisane/wy�wietlone
  @param print warto�� binarna okre�laj�ca czy wyj�cie ma zosta� wy�wietlona na ekranie
  */
void run(FILE* inFile, FILE* outFile, int amount, bool print);