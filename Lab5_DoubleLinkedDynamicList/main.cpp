#include <stdio.h>

#include "List.h"
#include"FileLoader.h"

void listMenuHandler(List* _list, FileLoader* _fl);

int main() {

	List list = List();
	FileLoader fl = FileLoader(&list, "Input.txt", "Input.txt");
	fl.openFileInput();
	fl.readFile();
	fl.closeFileInput();
	fl.openFileOutput();
	listMenuHandler(&list, &fl);
	return 0;
}

/*
List* generateList();

List *list = generateList();
	FileLoader fl = FileLoader(list, "", "Input.txt");
	fl.openFileOutput();
	fl.wtiteFile();
*/