
#include "common.h"

#include "cocos2d.h"
#include <iostream>
USING_NS_CC;

struct ENEMY globalEnemyData[]=
{
	{TYPE_ENEMY,ENEMY_KULOUREN,"������","������",110,25,5,110},
	{TYPE_ENEMY,ENEMY_KULOUSHIBING,"����ʿ��","����ʿ��",150,40,20,150},
	{TYPE_ENEMY,ENEMY_XIAOBIANFU,"С����","С����",100,20,5,100},
	{TYPE_ENEMY,ENEMY_LVTOUGUAI,"��ͷ��","��ͷ��",50,20,1,50},
	{TYPE_ENEMY,ENEMY_HONGTOUGUAI,"��ͷ��","��ͷ��",70,15,2,70},
	{TYPE_ENEMY,ENEMY_CHUJIFASHI,"������ʦ","������ʦ",125,50,25,125},
};

struct ITEM globalItemData[]=
{
	{TYPE_ITEM,ITEM_REDDIAMOND,"�챦ʯ","���ӹ�����"},
	{TYPE_ITEM,ITEM_BLUEDIAMOND,"����ʯ","���ӷ�����"},
	{TYPE_ITEM,ITEM_REDBLOOD,"��Ѫƿ","���Ӵ�������"},
	{TYPE_ITEM,ITEM_BLUEBLOOD,"��Ѫƿ","������������"},
	{TYPE_ITEM,ITEM_YELLOWKEY,"��Կ��","������ɫ��"},
	{TYPE_ITEM,ITEM_BLUEKEY,"��Կ��","������ɫ��"},
	{TYPE_ITEM,ITEM_REDKEY,"��Կ��","������ɫ��"},
};

ObjManager& ObjManager::getInstance()
{
	static ObjManager manager;
	return manager;
}

ValueMap* ObjManager::InitEnemyByType(int type)
{
	ValueMap* curmap=new ValueMap(enemytemp[type]);
	enemies.push_back(curmap);
	return curmap;
}

ValueMap* ObjManager::InitItemByType(int type)
{
	return &itemtemp[type];
}

ObjManager::ObjManager()
{
	ValueMap curmap;
	for(ENEMY eny:globalEnemyData)
	{
		curmap["category"]=eny.category;
		curmap["type"]=eny.type;
		curmap["name"]=eny.name;
		curmap["desc"]=eny.desc;
		curmap["life"]=eny.life;
		curmap["offense"]=eny.offense;
		curmap["defense"]=eny.defense;
		curmap["money"]=eny.money;
		curmap["selected"]=false;
		enemytemp[eny.type]=curmap;
		curmap.clear();
	}

	for(ITEM item:globalItemData)
	{
		curmap["category"]=item.category;
		curmap["type"]=item.type;
		curmap["name"]=item.name;
		curmap["desc"]=item.desc;
		curmap["selected"]=false;
		itemtemp[item.type]=curmap;
		curmap.clear();
	}
}

ObjManager::~ObjManager()
{
	for(ValueMap* pt:enemies)
	{
		delete pt;
	}
	for(ValueMap* pt:items)
	{
		delete pt;
	}
}


int HeroInitPos[]=
{//in*2 out*2�ֱ�����¥�µ��˲�ĳ�ʼλ�úʹ�¥�ϵ��˲�ĳ�ʼλ��
	//					��һ��			�ڶ���			������			���Ĳ�
	-1,-1,  -1,-1,    6,10,  2,1,    2,1,  1,10,    2,11,  10,11,    11,10,  1,10
};
