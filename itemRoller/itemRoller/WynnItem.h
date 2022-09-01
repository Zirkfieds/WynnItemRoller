#pragma once
#include"itemStat.h"

using namespace std;

class WynnItem {
private:

	string itemName;
	int identificationCnt;
	vector<SingleStat> itemStats;

public:

	WynnItem(string itemName, string itemStats);
	WynnItem(string itemName, string itemStats, string itemRolls);

	void parseStats(string jsonString); // Parse stats string.
	void parseRolls(string rollString); // Parse rolls string.

	bool identifyItem(int ampTier); // Identify an item.
	bool rerollingItem(int ampTier); // Rerolling an item.
	bool displayItem(); // Display an item.

	double getStat(string statName);
	vector<SingleStat> getAllStats();

};