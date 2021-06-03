#include<string>

#include"List.h"
#include"Item.h"

#define COUNTMIN 1
#define COUNTMAX 10
#define PRICEMIN 0.01f
#define PRICEMAX 10000.0f
#define STACKLIMIT 1000

static std::string name_array[] = { //15
	"Rabbit",
	"Magazine",
	"Watch",
	"Flash card",
	"Book",
	"Train",
	"Apple",
	"Ball",
	"Car",
	"Cup",
	"Laptop",
	"Flower",
	"Bun",
	"Candy",
	"Cell phone"
};

static std::string origin_array[] = { //7
	"RUS",
	"CHN",
	"DEU",
	"USA",
	"POL",
	"KAZ",
	"GBR"
};


List* generateList() {
	List* ret = new List();
	int stackLimit = std::rand() % STACKLIMIT;
	for (int i = 0; i < stackLimit; i++) {
		std::string name = name_array[std::rand()%15];
		std::string origin_str = origin_array[std::rand()%7];
		char *origin = new char[4];
		*(origin + 0) = origin_str[0];
		*(origin + 1) = origin_str[1];
		*(origin + 2) = origin_str[2];
		*(origin + 3) = 0;
		int count = rand() % COUNTMAX - COUNTMIN + 2;
		float price = ((float)(rand()) / (float)RAND_MAX) * PRICEMAX + PRICEMIN;
		Item *item = new Item(count, price, name, origin);
		ret->AddFront(item);
	}
	return ret;
}