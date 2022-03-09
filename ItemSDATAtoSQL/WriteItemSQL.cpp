#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "ItemSDATA.h"
using namespace std;

void WriteItemSQL(_ItemSDATA* ItemSDATA)
{
	if (remove("item.sql") != 0)
		perror("item.sql doesn't exist, it will be created automatically.");
	else
		puts("File successfully deleted");

	ofstream myfile;
	myfile.open("item.sql", std::ios_base::app | std::ios_base::out);
	myfile <<"TRUNCATE TABLE [PS_GameDefs].[dbo].[ItemsTest];" << endl;
	myfile << "GO" << endl;

	for (int i = 0; i < ItemSDATA->ItemGroups.size(); i++) {
		_ItemGroup* ItemGroup = ItemSDATA->ItemGroups[i];
		for (int j = 0; j < ItemGroup->Items.size(); j++) {
			_ItemModel* Item = ItemGroup->Items[j];

			size_t index = 0;

			while (true) {
				/* Locate the substring to replace. */
				index = Item->ItemName.find('\'', index);
				if (index == std::string::npos) break;

				/* Make the replacement. */
				Item->ItemName.insert(index, 1, '\'');

				/* Advance index forward so the next iteration doesn't pick it up as well. */
				index += 2;
			}

			index = 0;
			while (true) {
				/* Locate the substring to replace. */
				index = Item->Description.find('\'', index);
				if (index == std::string::npos) break;

				/* Make the replacement. */
				Item->Description.insert(index, 1, '\'');

				/* Advance index forward so the next iteration doesn't pick it up as well. */
				index += 2;
			}

			myfile << "INSERT INTO [PS_GameDefs].[dbo].[ItemsTest] values ("<<to_string((Item->type*1000)+Item->TypeID)<<",'"<<Item->ItemName<<"','"<<Item->Description<<"',"<<
				to_string(Item->type) <<","<<
				to_string(Item->TypeID) <<"," << to_string(Item->ItemModel) <<","<< to_string(Item->ItemIcon) <<","<< to_string(Item->ReqLevel) <<"," << to_string(Item->Country) <<","<<
				to_string(Item->AttackFighter) <<","<< to_string(Item->DefenseFighter) <<","<< to_string(Item->PatrolRogue) <<","<<
				to_string(Item->ShootRogue) <<","<< to_string(Item->AttackMage) <<","<< to_string(Item->DefenseMage) <<","<< to_string(Item->Grow) <<","<<
				to_string(Item->ReqStr) <<","<< to_string(Item->ReqDex)<<","<< to_string(Item->ReqRec)<<","<< to_string(Item->ReqInt)<<","<<
				to_string(Item->ReqWis) <<","<< to_string(Item->ReqLuc)<<","<< to_string(Item->ReqVg)<<","<< to_string(Item->ReqOg)<<","<<
				to_string(Item->ReqIg)<<","<< to_string(Item->Range)<<","<< to_string(Item->AttackTime)<<","<< to_string(Item->Attrib)<<","<< to_string(Item->Special)<<
				","<< to_string(Item->Slot)<<","<< to_string(Item->Quality) <<","<< to_string(Item->Effect1) <<","<< to_string(Item->Effect2)<<","<<
				to_string(Item->Effect3) <<","<< to_string(Item->Effect4) <<","<< to_string(Item->ConstHP)<<","<< to_string(Item->ConstMP)<<","<<
				to_string(Item->ConstSP) <<","<< to_string(Item->ConstStr)<<","<< to_string(Item->ConstDex)<<","<< to_string(Item->ConstRec)<<","<< to_string(Item->ConstInt)<<","<<
				to_string(Item->ConstWis) <<","<< to_string(Item->ConstLuc) <<","<< to_string(Item->Speed)<<
				","<< to_string(Item->Exp) <<","<< to_string(Item->Buy) <<","<< to_string(Item->Sell) <<","<< to_string(Item->Grade) <<","<< to_string(Item->Drop) <<","<<
				to_string(Item->Server) <<","<< to_string(Item->Count)<<")";

			myfile <<endl;
		}

	}

	myfile << "GO" << endl;

	myfile.close();

	cout << "Item.sql successfully created!" << endl;
}