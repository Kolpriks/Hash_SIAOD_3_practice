//priemnik.cpp
#include <iostream>

#include <list>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>


#include "struct.h"
#include "HashTable.h"

using namespace std;

HashTable ht;
int position = 1;

void insertDataToHT(string binaryFilename) {
    ifstream binaryFile(binaryFilename, ios::binary);

    if (!binaryFile.is_open()) {
        cout << "Ошибка при открытии файла: " << binaryFilename << endl;
        return;
    }

    
    Record record;

    while (binaryFile.read(reinterpret_cast<char*>(&record), sizeof(Record))) {
       
        string result = (record.licence);
        ht.insert(result, position);

        position++;
    }


    cout << endl;
    binaryFile.close();
}


int findPositionByKey(string key) {
    int result = ht.find(key);
    return result;
}


string findLineByPosition(string binaryFilename, int pos)
{
    ifstream file(binaryFilename, ios::binary);

    file.seekg(pos * sizeof(Record), ios::beg);
    Record record;
    file.read(reinterpret_cast<char*>(&record), sizeof(Record));
    file.close();
    string resultLine = string() + record.licence + " " + record.nameOfCompany + " " + record.name + " " + (record.activeOrNot ? "1" : "0");
    return resultLine;
}


void addNewLineToBinaryAndHT(string newLine, string binaryFilename) {
    
    ofstream binaryFile(binaryFilename, ios::binary | ios::app);

    if (!binaryFile.is_open()) {
        cout << "Не удалось открыть бинарный файл." << endl;
        return;
    }

    Record record;
    istringstream iss(newLine);
    iss >> record.licence >> record.nameOfCompany >> record.name >> record.activeOrNot;
    binaryFile.write(reinterpret_cast<char*>(&record), sizeof(Record));
    string result = record.licence;
    ht.insert(result, position);
    position++;

    binaryFile.close();
}


void removeFromHtAndBinaryFileByKey(string key, string binaryFilename)
{
    int pos = findPositionByKey(key);
    removeRecordByLicence(binaryFilename, key);
    ht.remove(key);
    
}

void printHashTable() {
    for (Hash hash : table)
        cout << "| " << setw(5) << hash.key << setw(10) << hash.pos << " |" << endl;
}