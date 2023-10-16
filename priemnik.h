//priemnik.h
#pragma once

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include "struct.h"
#include "HashTable.h"

using namespace std;

void insertDataToHT(string binaryFilename);

int findPositionByKey(string key);

string findLineByPosition(string binaryFilename, int pos);

void addNewLineToBinaryAndHT(string newLine, string binaryFilename);

void removeFromHtAndBinaryFileByKey(string key, string binaryFilename);

#endif 
