// ItemSDATAtoSQL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "ItemSDATA.h"
using namespace std;

extern _ItemSDATA* ReadItemSDATA();
extern void WriteItemSQL(_ItemSDATA* ItemSDATA);


int main()
{
	_ItemSDATA* asd = ReadItemSDATA();
	if (asd) {

		WriteItemSQL(asd);
	}
	cout << "You can close the program." << endl;
	getchar();
}
