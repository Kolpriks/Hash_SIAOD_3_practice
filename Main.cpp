//main.cpp
#include "HashTable.h"
#include "struct.h"
#include "priemnik.h"

#include <iostream>

#include <list>
#include <string>
#include <chrono>
#include <iomanip>
#include <string.h>
using namespace std;


int main() {

    setlocale(LC_ALL, "Russian");

	string filename;
	string id;
	string company;
	string NaMe;
	string active;
	string newLine;
	
	string key;
	int choice;


	cout << "Введите название файла: ";
	cin >> filename;
	itFile(filename);

	while (true) {


		cout << "Создание бинарного файла из текстового - 1" << endl;
		cout << "Создание текстового файла из бинарного - 2" << endl;
		cout << "Вывод содержимого бинарного файла на экран - 3" << endl;
		cout << "Поместить данные в хэш таблицу - 4" << endl;
		cout << "Найти строку данных используя хэш таблицу - 5" << endl;
		cout << "Добавить строку в таблицу и хэш таблицу-  6" << endl;
		cout << "Удалить, запись по ключу из таблицы и бинарного файла - 7" << endl;
		cout << "Выход - 0" << endl;

		cout << "Выберите действие: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 1:
		{
			string binFilename = filename.substr(0, filename.find_last_of('.')) + ".dat";
			textFileToBinaryFile(filename, binFilename);
			cout << "Бинарный файл " << binFilename << " создан." << endl << endl;

			break;
		}
		case 2:
		{
			string binFilename = filename.substr(0, filename.find_last_of('.')) + ".dat";
			binaryFileToTextFile(binFilename, filename);
			cout << "Текстовый файл " << filename << " создан." << endl << endl;

			break;
		}
		case 3:
		{
			string binFilename = filename.substr(0, filename.find_last_of('.')) + ".dat";
			printBinaryFile(binFilename);

			break;
		}
		case 4:
		{
			insertDataToHT("file.dat");
			cout << "Данныые успешно помещенны в хэш таблицу!" << endl << endl;
			break;
		}
		case 5:
		{
			
			string binFilename = filename.substr(0, filename.find_last_of('.')) + ".dat";
			cout << "Введите ключ: " << endl;
			cin >> key;

			// Засекаем время перед началом поиска
			auto start = chrono::high_resolution_clock::now();

			int pos = findPositionByKey(key) - 1;

			// Засекаем время после завершения поиска
			auto end = chrono::high_resolution_clock::now();
			chrono::duration<double> duration = end - start;

			if (pos >= 0)
			{
				cout << findLineByPosition(binFilename, pos)<<endl;
				cout << "Время поиска ключа: " << fixed << setprecision(8) << duration.count() << " секунд" << endl;
			}
			else 
			{
				cout << "Ключ не найден!" << endl;	
			}
			cout <<  endl;
			break;
		}

		case 6:
		{
			string binFilename = filename.substr(0, filename.find_last_of('.')) + ".dat";
			cout << "Введите строку, для добавления в файл и таблицу: " << endl;
			cin >> id >> company >> NaMe >> active;
			newLine = string() + id + " " + company + " "+ NaMe+ " " + active;
			
			cout << "Вы ввели: " << newLine << endl << endl;

			addNewLineToBinaryAndHT(newLine, binFilename);

			break;
		}
		case 7:
		{
			string binFilename = filename.substr(0, filename.find_last_of('.')) + ".dat";
			cout << "Введите ключа строки, которую необходимо удалить: " << endl;
			cin >> key;
			removeFromHtAndBinaryFileByKey(key, binFilename);
			cout << "Запись с ключом " << key << " удалена!" << endl << endl;

			break;

		}
		case 0:
			return 0;
		}
	}
};
