#include <string>
using namespace std;
#include "Item.h"

//medthods
std::string Item::GetName() {
	return this->name;
};
int Item::GetCount() {
	return this->count;
};
void Item::SetName(std::string t_name) {
	this->name = t_name;
};
void Item::IcrementCount() {
	this->count++;
};

//big three
Item::~Item() {
    // No dynamic memory allocation here, so no need for explicit deallocation
}

Item::Item(const Item& t_origItem) {
    name = t_origItem.name;
    count = t_origItem.count;
}

Item& Item::operator=(const Item& t_ItemToCopy) {
    if (this != &t_ItemToCopy) { // Self-assignment check
        name = t_ItemToCopy.name;
        count = t_ItemToCopy.count;
    }
    return *this;
}

//constructors
Item::Item(std::string t_string, int t_count) {
    this->name = t_string;
    this->count = t_count;
}
Item::Item() {
    this->name = "";
    this->count = 0;
}