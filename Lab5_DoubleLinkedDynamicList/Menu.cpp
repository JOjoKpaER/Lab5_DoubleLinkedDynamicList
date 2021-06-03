#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <Windows.h>

#include"List.h"
#include"Item.h"
#include"Main.h"
#include"FileLoader.h"

static List *list;

static FileLoader *fl;

static enum Function {
	ADDFRONT,
	ADDBACK,
	ADDAT,
	REMOVEFRONT,
	REMOVEBACK,
	REMOVEAT,
	SORTBYNAME,
	SORTBYPRICE,
	SAVE,
	CLEAR,
	PRINT,
	END,
	NONE
};

void AddFront(Item* item);
void AddBack(Item* item);
void AddAt(Item* item, unsigned int pos);
void RemoveFront();
void RemoveBack();
void RemoveAt(unsigned int pos);
void Sort(SortType);
void Save();
void Print();
void Clear();

void listMenuHandler(List* _list, FileLoader *_fl) {
	list = _list;
	fl = _fl;
	std::string Actions[] = { //12
		"Add front",
		"Add back",
		"Add at",
		"Remove front",
		"Remove back",
		"Remove at",
		"Sort by name",
		"Sort by price",
		"Save list",
		"Clear list",
		"Print",
		"Close"
	};
	std::string SelectionMessage = "Select next action:\n";
	for (int i = 0; i < 12; i++) {
		SelectionMessage += "\n" + Actions[i];
	}
	SelectionMessage += "\n";
	std::string SelectedAction;
	////////////////////////////////////////////////////////////////////////////////////////
	bool cls = true;
	while (cls) {
		std::cout << SelectionMessage;
		std::getline(std::cin, SelectedAction);
		Function func = NONE;
		for (int i = 0; i < 12; i++) {
			if (SelectedAction == Actions[i]) {
				func = Function(i);
				break;
			}
		}
		switch (func) {
		case(ADDFRONT): {
			std::string name;
			char origin[4];
			float price;
			int count;
			std::cout << "\nLabel of item: ";
			std::cin >> name;
			bool b = true;
			do {
				std::cout << "Origin of item: ";
				std::cin >> origin;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Unacceptable term\n");
					Sleep(delay);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			b = true;
			do {
				std::cout << "Quantity of item: ";
				std::cin >> count;
				if (std::cin.fail() || count <= 0) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Incorrect value\n");
					Sleep(delay);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			b = true;
			do {
				std::cout << "Price of item: ";
				std::cin >> price;
				if (std::cin.fail() || price <= 0.0f) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Incorrect value\n");
					Sleep(delay);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			AddFront(new Item(count, price, name, origin));
			break;
		}
		case(ADDBACK): {
			std::string name;
			char origin[4];
			float price;
			int count;
			std::cout << "\nLabel of item: ";
			std::cin >> name;
			bool b = true;
			do {
				std::cout << "Origin of item: ";
				std::cin >> origin;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Unacceptable term\n");
					Sleep(delay);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			b = true;
			do {
				std::cout << "Quantity of item: ";
				std::cin >> count;
				if (std::cin.fail() || count <= 0) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Incorrect value\n");
					Sleep(delay);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			b = true;
			do {
				std::cout << "Price of item: ";
				std::cin >> price;
				if (std::cin.fail() || price <= 0.0f) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Incorrect value\n");
					Sleep(delay);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			AddBack(new Item(count, price, name, origin));
			break;
		}
		case(ADDAT): {
			std::string name;
			char origin[4];
			float price;
			int count;
			unsigned int pos;
			std::cout << "\nLabel of item: ";
			std::cin >> name;
			bool b = true;
			do {
				std::cout << "Origin of item: ";
				std::cin >> origin;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Unacceptable term\n");
					Sleep(delay);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			b = true;
			do {
				std::cout << "Quantity of item: ";
				std::cin >> count;
				if (std::cin.fail() || count <= 0) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Incorrect value\n");
					Sleep(delay);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			b = true;
			do {
				std::cout << "Price of item: ";
				std::cin >> price;
				if (std::cin.fail() || price <= 0.0f) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Incorrect value\n");
					Sleep(delay);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
				if (price <= 0.0f)
				{
					std::cin.clear();
					std::printf("Incorrect value\n");
					Sleep(delay);
					b = true;
				}
			} while (b);
			b = true;
			do {
				std::cout << "Position: ";
				std::cin >> pos;
				if (std::cin.fail() || pos < 0 || pos > list->GetSize()) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Incorrect value\n");
					Sleep(delay);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			AddAt(new Item(count, price, name, origin), pos);
			break;
		}
		case(REMOVEFRONT): {
			RemoveFront();
			break;
		}
		case(REMOVEBACK): {
			RemoveBack();
			break;
		}
		case(REMOVEAT): {
			unsigned int pos;
			bool b = true;
			do {
				std::cout << "Position: ";
				std::cin >> pos;
				if (std::cin.fail() || pos < 0 || pos > list->GetSize()) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Incorrect value\n");
					Sleep(delay);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			RemoveAt(pos);
			break;
		}
		case(SORTBYNAME): {
			Sort(NAME);
			break;
		}
		case(SORTBYPRICE): {
			Sort(PRICE);
			break;
		}
		case(SAVE): {
			Save();
			break;
		}
		case(PRINT): {
			Print();
			break;
		}
		case(CLEAR): {
			Clear();
			break;
		}
		case(END): {
			cls = false;
			printf("List program is closing now\n");
			Sleep(delay);
			break;
		}
		default: {
			printf("Cannot procceed inputed function\n");
			Sleep(delay);
		}
		}
	}
	////////////////////////////////////////////////////////////////////////////////////////
}

std::string GetItemDescription(Item *item) {
	std::string ret = "";
	if (item)
		ret += " Label: " + item->Name + " Origin: " + item->Origin + " Count: x" + std::to_string(item->count) + " Price: " + std::to_string(item->price);
	return ret;
}


void AddFront(Item* item) {
	if (!item) return;
	list->AddFront(item);
	std::cout << GetItemDescription(item) << " was added to list\n";
	Sleep(delay);
}

void AddBack(Item* item) {
	if (!item) return;
	list->AddBack(item);
	std::cout << GetItemDescription(item) << " was added to list\n";
	Sleep(delay);
}

void AddAt(Item* item, unsigned int pos) {
	if (!item) return;
	list->AddAt(item, pos);
	std::cout << GetItemDescription(item) << " was added to list\n";
	Sleep(delay);
}

void RemoveFront() {
	if (!list->GetSize()) {
		printf("List is empty\n");
		Sleep(delay);
		return;
	}
	std::cout << GetItemDescription(list->RemoveFront()) << " was removed from list\n";
	Sleep(delay);
}

void RemoveBack() {
	if (!list->GetSize()) {
		printf("List is empty\n");
		Sleep(delay);
		return;
	}
	std::cout << GetItemDescription(list->RemoveBack()) << " was removed from list\n";
	Sleep(delay);

}

void RemoveAt(unsigned int pos) {

	if (!list->GetSize()) {
		printf("List is empty\n");
		Sleep(delay);
		return;
	}
	std::cout << GetItemDescription(list->RemoveAt(pos)) << " was removed from list\n";
	Sleep(delay);
}

void Sort(SortType type) {
	list->Sort(type);
	printf("List was sorted: \n");
	for (int i = 0; i < list->GetSize(); i++)
		std::cout << GetItemDescription(list->GetAt(i)) << "\n";
	Sleep(delay);
}

void Save() {
	fl->wtiteFile();
	printf("List was saved\n");
	Sleep(delay);
}

void Clear() {
	while (list->GetFront()) {
		std::cout << GetItemDescription(list->RemoveFront()) << " was removed from list\n";
		Sleep(delay / 10);
	}
}

void Print() {
	if (list->GetSize() == 0) {
		printf("List is empty\n");
		Sleep(delay);
	}
	for (int i = 0; i < list->GetSize(); i++) {
		std::cout << GetItemDescription(list->GetAt(i)) << "\n";
		Sleep(delay / 10);
	}
}