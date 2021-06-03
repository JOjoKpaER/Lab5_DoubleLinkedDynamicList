#pragma once
#include "Item.h"
#include "Main.h"

class List
{
private:

	struct element {

		Item *item;
		element *prev;
		element *next;

		element(Item *_item, element *_prev, element *_next) {
			item = _item;
			prev = _prev;
			next = _next;
			if (_next) _next->prev = this;
			if (_prev) _prev->next = this;
		}

		element(element *_element) {
			item = _element->item;
			prev = _element->prev;
			next = _element->next;
		}

		element* operator=(element *_element) {
			return new element(_element);
		}
	};

	element *front, *back;
	unsigned int size;

public:

	List() {
		front = nullptr;
		back = nullptr;
		size = 0;
	}

	~List() {
		if (back && front) {
			element* t = front->prev;
			while (front->prev)
			{
				delete front;
				front = t;
				t = front->prev;
			}
			delete t;
			t = nullptr;
			front = nullptr;
			back = nullptr;
		}
	}

	void AddFront(Item *_item) {
		if (front) {
			element *t = new element(_item, front, nullptr);
			front = t;
		}
		if (!front && !back) {
			element *t = new element(_item, nullptr, nullptr);
			front = t;
			back = t;
		}
		size++;
	}

	void AddBack(Item *_item) {
		if (back) {
			element *t = new element(_item, nullptr, back);
			back = t;
		}
		if (!front && !back) {
			element *t = new element(_item, nullptr, nullptr);
			front = t;
			back = t;
		}
		size++;
	}

	void AddAt(Item *_item, unsigned int i) {
		if (i > size) return;
		if (i == size) {
			this->AddBack(_item);
			return;
		}
		if (i == 0) {
			this->AddFront(_item);
			return;
		}
		element *cursor = front;
		for (int j = 0; j < i; j++) {
			cursor = cursor->prev;
		}
		element *t = new element(_item, cursor, cursor->next);
		size++;
	}

	Item *RemoveFront() {
		if (!front) return nullptr;
		element *t = front->prev;
		Item* ret = front->item;
		delete front;
		front = t;
		size--;
		return ret;
	}

	Item *RemoveBack() {
		if (!back) return nullptr;
		element *t = back->next;
		Item* ret = back->item;
		delete back;
		back = t;
		size--;
		return ret;
	}

	Item *RemoveAt(unsigned int i) {
		if (i > size) return nullptr;
		if (i == size) {
			return this->RemoveBack();
		}
		if (i == 0) {
			return this->RemoveFront();
		}
		element *cursor = front;
		for (int j = 0; j < i; j++) {
			cursor = cursor->prev;
		}
		Item* ret = cursor->item;
		element t = *cursor;
		cursor->prev->next = t.next;
		cursor->next->prev = t.prev;
		size--;
		return ret;
	}

	Item *GetFront() {
		if (!front) return nullptr;
		return front->item;
	}

	Item *GetBack() {
		if (!back) return nullptr;
		return back->item;
	}

	Item *GetAt(unsigned int i) {
		if (i > size) return nullptr;
		if (i == size) {
			Item *ret = this->GetBack();
			return ret;
		}
		if (i == 0) {
			Item *ret = this->GetFront();
			return ret;
		}
		element *cursor = front;
		for (int j = 0; j < i; j++) {
			cursor = cursor->prev;
		}
		return cursor->item;
	}

	unsigned int GetSize() {
		return size;
	}

	void Sort(SortType type) {
		for (int i = 0; i < size - 1; i++) {
			element*  cursor = back;
			for (int j = 0; j < size - 1; j++) {
				if (type == PRICE) {
			//		printf("%f %i %f\n", cursor->item->price, cursor->item->price < cursor->next->item->price, cursor->next->item->price);
					if (cursor->item->price < cursor->next->item->price) {
						Item *t = cursor->item;
						cursor->item = cursor->next->item;
						cursor->next->item = t;
					}
				}
				if (type == NAME) {
					if (cursor->item->Name < cursor->next->item->Name) {
						Item *t = cursor->item;
						cursor->item = cursor->next->item;
						cursor->next->item = t;
					}
				}
				cursor = cursor->next;
			}
		}
	}
};

