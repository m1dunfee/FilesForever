#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
//includes can have odder of operations issues >.>
#include "Item.h"

//safer to just use reference here
void WriteFile(string t_fileName, vector<Item>& t_vec) {
	ofstream outFS;
	
	outFS.open(t_fileName);
	
	if (!outFS.is_open()) {
		cout << "Cound not open file: " << t_fileName << endl;
		return;
	}

	for (int i = 0; i < t_vec.size(); i++) {
		outFS << t_vec.at(i).GetName() << " " << t_vec.at(i).GetCount() << endl;
	}

	outFS.close();
}

void ReadFile(string t_fileName, vector<Item>& t_vec) {
	ifstream inFS;
	string currName;
	int currNum;
	int location;
	bool found;

	inFS.open(t_fileName);

	if (!inFS.is_open()) {
		cout << "Cound not open file: " << t_fileName << endl;
		return;
	}
	
	//eof caused infinate loop here
	while (inFS >> currName) { 
		if (inFS.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Could not read input form: " << t_fileName << endl;
		}else {
			// I think I just learned another lesson here.
			// If I would have used maps, I wouldn't have had to worry about Big'O. 
			// I'm still not going to since I haven't taken that class yet, but this is there I would optimize first.
			found = false;
			for (int i = 0; i < t_vec.size(); i++) {
				if (t_vec.at(i).GetName() == currName) {
					found = true;
					location = i;
				}else {
					continue;
				}
			}
			if (found) {
				t_vec.at(location).IcrementCount();
				//cout << "++" << endl;
			}else {
				t_vec.push_back(Item(currName, 1));
				//cout << currName << endl;
			}
		}
}

	inFS.close();
}

std::string ValidInput() {
	bool flag = true;
	string userInput;

	while (flag) {
		try {
			cin >> userInput;
			if (cin.fail()) {
				// Clear the error state and ignore invalid input
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				throw runtime_error("Input error: invalid input");
			}else {
				flag = false;
			}
		}catch (exception& e) {
			cout << "Invalid input, please try again: " << e.what() << endl;
		}
	
	}

	return userInput;
}

void ItemLookup(vector<Item>& t_vec){
	bool flag = false;
	Item tempItem = Item(); 

	cout << "Please enter the name of the item." << endl;
	tempItem.SetName(ValidInput());

	for (int i = 0; i < t_vec.size(); i++) {
		if (t_vec.at(i).GetName() == tempItem.GetName()) {
			tempItem = t_vec.at(i); // one of the big three
			break;
		}
		else {
			continue;
		}
	}

	cout << tempItem.GetName() << " " << tempItem.GetCount() << endl;
}

void PrintItems(vector<Item>& t_vec) {
	for (int i = 0; i < t_vec.size(); i++) {
		cout << t_vec.at(i).GetName() << " " << t_vec.at(i).GetCount() << endl;
	}
}

void PrintItemsHist(vector<Item>& t_vec) {
	for (int i = 0; i < t_vec.size(); i++) {
		cout << t_vec.at(i).GetName() << " ";
		for (int j = 0; j < t_vec.at(i).GetCount(); j++) {
			cout << "*";
		}
		cout << endl;
	}
}

int main() {
	string inFile = "inputFile.txt";
	string outFile = "outputFile.txt";
	string option = "";
	bool flag = true;
	vector<Item> itemVec;

	ReadFile(inFile, itemVec);
	WriteFile(outFile, itemVec);

	cout << "**************** MENU ****************" << endl;
	cout << "* ITEM LOOKUP - 1" << endl;
	cout << "* ITEM QUANTITIES - 2" << endl;
	cout << "* ITEM QUANTITIES HIST - 3" << endl;
	cout << "* EXIT - 4" << endl;
	cout << "**************************************" << endl;


	// had to an if else data structure since in c++ switchs requires int or enum cases
	while (flag) {
		option = ValidInput();

		if (option == "1") {
			ItemLookup(itemVec);
		}
		else if (option == "2") {
			PrintItems(itemVec);
		}
		else if (option == "3") {
			PrintItemsHist(itemVec);
		}
		else if (option == "4") {
			// no memory cleanup since I am only using reference.
			cout << "easy peasy lemon squeezy." << endl;
			return 0;
		}
		else {
			cout << "invalid choice. Please enter 1, 2, 3, or 4..." << endl;
		}
		cout << "Please choose another Menu option..." << endl;
	}
}