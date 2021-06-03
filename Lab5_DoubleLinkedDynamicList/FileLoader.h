#pragma once

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <string>

#include"Main.h"
#include"List.h"
#include"Item.h"

class FileLoader
{
private:

	std::string FilePathInput;
	std::string FilePathOutput;

	std::ifstream *FileInput;
	std::ofstream *FileOutput;

	List *list;

public:

	FileLoader(List *_list, std::string PathInput, std::string PathOutput) {
		list = _list;
		FilePathInput = PathInput;
		FilePathOutput = PathOutput;
	}

	~FileLoader() {
		if (FileInput)
			FileInput->close();
		if (FileOutput)
			FileOutput->close();
	}

	void openFileInput() {;
		FileInput = new std::ifstream(FilePathInput);
		if (!FileInput->is_open())
		{
			printf("Cannot open file\n");
			FileInput = nullptr;
			return;
		}
	}

	void closeFileInput() {
		if (!FileInput) return;
		if (FileInput->is_open()) {
			FileInput->close();
		}
	}

	void openFileOutput() {
		FileOutput = new std::ofstream(FilePathOutput);
		if (!FileOutput->is_open())
		{
			printf("Cannot open file\n");
			FileOutput = nullptr;
			return;
		}
	}

	void closeFileOutput() {
		if (!FileOutput) return;
		if (FileOutput->is_open()) {
			FileOutput->close();
		}
	}

	bool readFile() {
		if (!FileInput) {
			printf("Cannot open cart file");
			return false;
		}
		std::string line;
		while (std::getline(*(FileInput), line)) {
			if (line.empty()) {
				continue;
			}
			float price = std::stof(line.substr(line.rfind(" "), line.size()));
			line.erase(line.rfind(" "), line.size());
			int count = std::stoi(line.substr(line.rfind(" "), line.size()));
			line.erase(line.rfind(" "), line.size());
			std::string origin_str = line.substr(line.rfind(" "), line.size());
			line.erase(line.rfind(" "), line.size());
			std::string name = line;
			if (!price || !count || origin_str.empty() || name.empty()) {
				printf("Incomplete line in file has occured\n");
				continue;
			}
			char *origin = new char[4];
			*(origin + 0) = origin_str[1];
			*(origin + 1) = origin_str[2];
			*(origin + 2) = origin_str[3];
			*(origin + 3) = 0;
			Item *i = new Item(count,price,name,origin);
			list->AddBack(i);
		}
		return true;
	}

	bool wtiteFile() {
		if (!FileOutput) {
			printf("Cannot write cart file\n");
			return false;
		}
		FileOutput->clear();
		do
		{
			// Name(string) + " " + Origin(string) + " " Count(unsigned int) + " " + Price(float) + "\n"
			std::string line = "";
			Item *i = list->RemoveFront();
			line += i->Name + " "
				+ i->Origin + " "
				+ std::to_string(i->count) + " "
				+ std::to_string(i->price) + "\n";
			(*FileOutput) << line;
			if (FileOutput->fail()) {
				printf("Error has occured while writing cart file\n");
				return false;
			}
		} while (list->GetFront());
		return true;
	}
};

