#pragma once
#include <Windows.h>
#include <vector>
#include <string>



typedef struct _ItemModel {
	unsigned int ItemName_length;
	std::string ItemName;
	unsigned int Description_length;
	std::string Description;
	byte type;
	byte TypeID;
	byte ItemModel;
	byte ItemIcon;
	unsigned short ReqLevel;
	byte Country;
	byte AttackFighter;
	byte DefenseFighter;
	byte PatrolRogue;
	byte ShootRogue;
	byte AttackMage;
	byte DefenseMage;
	byte Grow;
	byte Type2;
	byte Type3;
	short ReqStr;
	short ReqDex;
	short ReqRec;
	short ReqInt;
	short ReqWis;
	short ReqLuc;
	short ReqVg;
	byte ReqOg;
	byte ReqIg;
	byte Range;
	byte AttackTime;
	byte Attrib;
	byte Special;
	byte Slot;
	unsigned short Quality;
	unsigned short Effect1;
	unsigned short Effect2;
	unsigned short Effect3;
	unsigned short Effect4;
	unsigned short ConstHP;
	unsigned short ConstMP;
	unsigned short ConstSP;
	unsigned short ConstStr;
	unsigned short ConstDex;
	unsigned short ConstRec;
	unsigned short ConstInt;
	unsigned short ConstWis;
	unsigned short ConstLuc;
	byte Speed;
	byte Exp;
	unsigned int Buy;
	unsigned int Sell;
	unsigned short Grade;
	unsigned short Drop;
	byte Server;
	byte Count;

};


typedef struct _ItemGroup {
	unsigned int ItemCount;
	std::vector<_ItemModel*> Items;
};

typedef struct _ItemSDATA {
	unsigned int MaxType;
	unsigned int MaxTypeID;
	std::vector<_ItemGroup*> ItemGroups;
};