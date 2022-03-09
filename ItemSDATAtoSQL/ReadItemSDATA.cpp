#include <iostream>
#include <fstream>
#include <string>
#include "ItemSDATA.h"
using namespace std;

char vals2[0x500005];
_ItemSDATA* ReadItemSDATA()
{
	_ItemSDATA* ItemSDATA = new _ItemSDATA();
	//_ItemSDATA* ItemSDATA;


	//_ItemSDATA* ItemSDATA = new _ItemSDATA();
	string filename = "Item.sdata";
	ifstream rf(filename, ios::binary);
	if (!rf) {
		cout << "file cannot be opened" << endl;
		getchar();
		//return 1;
		return ItemSDATA;
	}
	//ItemSDATA->MaxType*ItemSDATA->MaxTypeID
	int namelength;
	int descriptionlength;
	char temp[500];
	rf.read((char*)&ItemSDATA->MaxType, sizeof(ItemSDATA->MaxType));
	//rf.read((char*)&ItemSDATA->MaxTypeID, sizeof(ItemSDATA->MaxTypeID));
	//for (int i = 0; i < ItemSDATA->MaxType*ItemSDATA->MaxTypeID; i++) {
	//	if (rf.peek() != EOF) {
	//		rf.read((char*)&namelength, sizeof(namelength));
	//		if (namelength > 0) {
	//			_ItemModel* ItemModel = new _ItemModel();

	//			ItemModel->ItemName_length = namelength;

	//			rf.read((char*)&temp, namelength);
	//			//rf.read((char*)ItemModel->ItemName, namelength);
	//			ItemModel->ItemName = temp;
	//			cout << namelength << " " << ItemModel->ItemName << endl;

	//			rf.read((char*)&descriptionlength, sizeof(descriptionlength));
	//			ItemModel->Description_length = descriptionlength;
	//			rf.read((char*)&temp, descriptionlength);
	//			ItemModel->Description = temp;
	//			cout << descriptionlength << " " << ItemModel->Description << endl;

	//			rf.read((char*)&ItemModel->type, sizeof(ItemModel->type));
	//			rf.read((char*)&ItemModel->TypeID, sizeof(ItemModel->TypeID));
	//			rf.read((char*)&ItemModel->ItemModel, sizeof(ItemModel->ItemModel));
	//			rf.read((char*)&ItemModel->ItemIcon, sizeof(ItemModel->ItemIcon));
	//			rf.read((char*)&ItemModel->ReqLevel, sizeof(ItemModel->ReqLevel));
	//			rf.read((char*)&ItemModel->Country, sizeof(ItemModel->Country));
	//			rf.read((char*)&ItemModel->AttackFighter, sizeof(ItemModel->AttackFighter));
	//			rf.read((char*)&ItemModel->DefenseFighter, sizeof(ItemModel->DefenseFighter));
	//			rf.read((char*)&ItemModel->PatrolRogue, sizeof(ItemModel->PatrolRogue));
	//			rf.read((char*)&ItemModel->ShootRogue, sizeof(ItemModel->ShootRogue));
	//			rf.read((char*)&ItemModel->AttackMage, sizeof(ItemModel->AttackMage));
	//			rf.read((char*)&ItemModel->DefenseMage, sizeof(ItemModel->DefenseMage));
	//			rf.read((char*)&ItemModel->Grow, sizeof(ItemModel->Grow));
	//			rf.read((char*)&ItemModel->Type2, sizeof(ItemModel->Type2));
	//			rf.read((char*)&ItemModel->Type3, sizeof(ItemModel->Type3));
	//			rf.read((char*)&ItemModel->ReqStr, sizeof(ItemModel->ReqStr));
	//			rf.read((char*)&ItemModel->ReqDex, sizeof(ItemModel->ReqDex));
	//			rf.read((char*)&ItemModel->ReqRec, sizeof(ItemModel->ReqRec));
	//			rf.read((char*)&ItemModel->ReqInt, sizeof(ItemModel->ReqInt));
	//			rf.read((char*)&ItemModel->ReqWis, sizeof(ItemModel->ReqWis));
	//			rf.read((char*)&ItemModel->ReqLuc, sizeof(ItemModel->ReqLuc));
	//			rf.read((char*)&ItemModel->ReqVg, sizeof(ItemModel->ReqVg));
	//			rf.read((char*)&ItemModel->ReqOg, sizeof(ItemModel->ReqOg));
	//			rf.read((char*)&ItemModel->ReqIg, sizeof(ItemModel->ReqIg));
	//			rf.read((char*)&ItemModel->Range, sizeof(ItemModel->Range));
	//			rf.read((char*)&ItemModel->AttackTime, sizeof(ItemModel->AttackTime));
	//			rf.read((char*)&ItemModel->Attrib, sizeof(ItemModel->Attrib));
	//			rf.read((char*)&ItemModel->Special, sizeof(ItemModel->Special));
	//			rf.read((char*)&ItemModel->Slot, sizeof(ItemModel->Slot));
	//			rf.read((char*)&ItemModel->Quality, sizeof(ItemModel->Quality));
	//			rf.read((char*)&ItemModel->Effect1, sizeof(ItemModel->Effect1));
	//			rf.read((char*)&ItemModel->Effect2, sizeof(ItemModel->Effect2));
	//			rf.read((char*)&ItemModel->Effect3, sizeof(ItemModel->Effect3));
	//			rf.read((char*)&ItemModel->Effect4, sizeof(ItemModel->Effect4));
	//			rf.read((char*)&ItemModel->ConstHP, sizeof(ItemModel->ConstHP));
	//			rf.read((char*)&ItemModel->CostMP, sizeof(ItemModel->CostMP));
	//			rf.read((char*)&ItemModel->CostSP, sizeof(ItemModel->CostSP));
	//			rf.read((char*)&ItemModel->ConstStr, sizeof(ItemModel->ConstStr));
	//			rf.read((char*)&ItemModel->ConstDex, sizeof(ItemModel->ConstDex));
	//			rf.read((char*)&ItemModel->ConstRec, sizeof(ItemModel->ConstRec));
	//			rf.read((char*)&ItemModel->ConstInt, sizeof(ItemModel->ConstInt));
	//			rf.read((char*)&ItemModel->ConstWis, sizeof(ItemModel->ConstWis));
	//			rf.read((char*)&ItemModel->ConstLuc, sizeof(ItemModel->ConstLuc));
	//			rf.read((char*)&ItemModel->Speed, sizeof(ItemModel->Speed));
	//			rf.read((char*)&ItemModel->Exp, sizeof(ItemModel->Exp));
	//			rf.read((char*)&ItemModel->Buy, sizeof(ItemModel->Buy));
	//			rf.read((char*)&ItemModel->Sell, sizeof(ItemModel->Sell));
	//			rf.read((char*)&ItemModel->Grade, sizeof(ItemModel->Grade));
	//			rf.read((char*)&ItemModel->Server, sizeof(ItemModel->Server));
	//			rf.read((char*)&ItemModel->Count, sizeof(ItemModel->Count));

	//			ItemSDATA->Items.push_back(ItemModel);
	//		}
	//	}
	//	
	//	
	//}

	while (rf && rf.peek() != EOF) {
		_ItemGroup* ItemGroup = new _ItemGroup();
		ItemSDATA->ItemGroups.push_back(ItemGroup);

		rf.read((char*)&ItemGroup->ItemCount, sizeof(ItemGroup->ItemCount));
		
		//if (ItemGroup->ItemCount > 0) {	
		for(int i=0; i<ItemGroup->ItemCount; i++){
			_ItemModel* ItemModel = new _ItemModel();
			rf.read((char*)&namelength, sizeof(namelength));
			ItemModel->ItemName_length = namelength;

			rf.read((char*)&temp, namelength);
			//rf.read((char*)ItemModel->ItemName, namelength);
			ItemModel->ItemName = temp;
			//cout << namelength << " " << ItemModel->type <<" " << ItemModel->TypeID<< ItemModel->ItemName << endl;

			rf.read((char*)&descriptionlength, sizeof(descriptionlength));
			ItemModel->Description_length = descriptionlength;
			rf.read((char*)&temp, descriptionlength);
			ItemModel->Description = temp;
			//cout << descriptionlength << " " << ItemModel->Description << endl;

			rf.read((char*)&ItemModel->type, sizeof(ItemModel->type));
			rf.read((char*)&ItemModel->TypeID, sizeof(ItemModel->TypeID));
			rf.read((char*)&ItemModel->ItemModel, sizeof(ItemModel->ItemModel));
			rf.read((char*)&ItemModel->ItemIcon, sizeof(ItemModel->ItemIcon));
			rf.read((char*)&ItemModel->ReqLevel, sizeof(ItemModel->ReqLevel));
			rf.read((char*)&ItemModel->Country, sizeof(ItemModel->Country));
			rf.read((char*)&ItemModel->AttackFighter, sizeof(ItemModel->AttackFighter));
			rf.read((char*)&ItemModel->DefenseFighter, sizeof(ItemModel->DefenseFighter));
			rf.read((char*)&ItemModel->PatrolRogue, sizeof(ItemModel->PatrolRogue));
			rf.read((char*)&ItemModel->ShootRogue, sizeof(ItemModel->ShootRogue));
			rf.read((char*)&ItemModel->AttackMage, sizeof(ItemModel->AttackMage));
			rf.read((char*)&ItemModel->DefenseMage, sizeof(ItemModel->DefenseMage));
			rf.read((char*)&ItemModel->Grow, sizeof(ItemModel->Grow));
			rf.read((char*)&ItemModel->Type2, sizeof(ItemModel->Type2));
			rf.read((char*)&ItemModel->Type3, sizeof(ItemModel->Type3));
			rf.read((char*)&ItemModel->ReqStr, sizeof(ItemModel->ReqStr));
			rf.read((char*)&ItemModel->ReqDex, sizeof(ItemModel->ReqDex));
			rf.read((char*)&ItemModel->ReqRec, sizeof(ItemModel->ReqRec));
			rf.read((char*)&ItemModel->ReqInt, sizeof(ItemModel->ReqInt));
			rf.read((char*)&ItemModel->ReqWis, sizeof(ItemModel->ReqWis));
			rf.read((char*)&ItemModel->ReqLuc, sizeof(ItemModel->ReqLuc));
			rf.read((char*)&ItemModel->ReqVg, sizeof(ItemModel->ReqVg));
			rf.read((char*)&ItemModel->ReqOg, sizeof(ItemModel->ReqOg));
			rf.read((char*)&ItemModel->ReqIg, sizeof(ItemModel->ReqIg));
			rf.read((char*)&ItemModel->Range, sizeof(ItemModel->Range));
			rf.read((char*)&ItemModel->AttackTime, sizeof(ItemModel->AttackTime));
			rf.read((char*)&ItemModel->Attrib, sizeof(ItemModel->Attrib));
			rf.read((char*)&ItemModel->Special, sizeof(ItemModel->Special));
			rf.read((char*)&ItemModel->Slot, sizeof(ItemModel->Slot));
			rf.read((char*)&ItemModel->Quality, sizeof(ItemModel->Quality));
			rf.read((char*)&ItemModel->Effect1, sizeof(ItemModel->Effect1));
			rf.read((char*)&ItemModel->Effect2, sizeof(ItemModel->Effect2));
			rf.read((char*)&ItemModel->Effect3, sizeof(ItemModel->Effect3));
			rf.read((char*)&ItemModel->Effect4, sizeof(ItemModel->Effect4));
			rf.read((char*)&ItemModel->ConstHP, sizeof(ItemModel->ConstHP));
			rf.read((char*)&ItemModel->ConstMP, sizeof(ItemModel->ConstMP));
			rf.read((char*)&ItemModel->ConstSP, sizeof(ItemModel->ConstSP));
			rf.read((char*)&ItemModel->ConstStr, sizeof(ItemModel->ConstStr));
			rf.read((char*)&ItemModel->ConstDex, sizeof(ItemModel->ConstDex));
			rf.read((char*)&ItemModel->ConstRec, sizeof(ItemModel->ConstRec));
			rf.read((char*)&ItemModel->ConstInt, sizeof(ItemModel->ConstInt));
			rf.read((char*)&ItemModel->ConstWis, sizeof(ItemModel->ConstWis));
			rf.read((char*)&ItemModel->ConstLuc, sizeof(ItemModel->ConstLuc));
			rf.read((char*)&ItemModel->Speed, sizeof(ItemModel->Speed));
			rf.read((char*)&ItemModel->Exp, sizeof(ItemModel->Exp));
			rf.read((char*)&ItemModel->Buy, sizeof(ItemModel->Buy));
			rf.read((char*)&ItemModel->Sell, sizeof(ItemModel->Sell));
			rf.read((char*)&ItemModel->Grade, sizeof(ItemModel->Grade));
			rf.read((char*)&ItemModel->Drop, sizeof(ItemModel->Drop));
			rf.read((char*)&ItemModel->Server, sizeof(ItemModel->Server));
			rf.read((char*)&ItemModel->Count, sizeof(ItemModel->Count));

			//cout << to_string(ItemModel->type) << " " << to_string(ItemModel->TypeID) << ItemModel->ItemName << " " << to_string(ItemModel->Grade) << endl;
			/*if(ItemModel->type==12 && ItemModel->TypeID == 161)
				cout << to_string(ItemModel->type * 1000 + ItemModel->TypeID) << " - " << ItemModel->ReqLuc << endl;*/

			ItemSDATA->ItemGroups.back()->Items.push_back(ItemModel);

		}
		
	}


	rf.close();
	return ItemSDATA;
	
}