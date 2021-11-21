#pragma once
#include <iostream>
#include <fstream>
#include <list>

#include "Node.h"

using namespace std;

constexpr char CODE_F[] = "code.bin";
constexpr char RESULT_TEXT[] = "decoded_text.txt";

void restoreTree(Node* root, ifstream& codeFile);
void decodeFile(Node* root, unsigned long long countOfBytes,
                ifstream& codeFile, ostream& result);