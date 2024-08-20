#pragma once

#include <string>
using namespace std;

class Item
{
	public:
		//medthods
		std::string GetName();
		int GetCount();
		void SetName(std::string);
		void IcrementCount();
		
		//big three
		// I don't actually need any of these. I thought maybe if I was using pointers, but I just used pass by refer.
		// would I delete this in the real world? just comment it out? seems like a security rist to just leave code laying around.
		~Item(); // deconstructer
		Item(const Item& t_origItem); // copy constructer
		Item& operator=(const Item& t_ItemToCopy); // Assignment


		//constructers
		Item(std::string, int);
		Item();


	private:
		std::string name;
		int count;

};

