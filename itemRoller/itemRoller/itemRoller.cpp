#include"itemRoller.h"

#include<sstream>

WynnItem::WynnItem(string itemName, string itemStats) {
	identificationCnt = 0;
	parseStats(itemStats);
	this->itemName = itemName;
}


WynnItem::WynnItem(string itemName, string itemStats, string itemRolls) {
	identificationCnt = 0;
	parseStats(itemStats);
	parseRolls(itemRolls);
	this->itemName = itemName;
}


void WynnItem::parseStats(string jsonString) { // Parse stats string.
	
	// TODO: parse .json from item db directly.

	istringstream ss(jsonString);
	while (ss.peek() != EOF) {

		string statName;
		double statBase;
		int favorType;

		// Parse here
		ss >> statName >> statBase >> favorType;

		SingleStat newStat(statName, statBase, favorType);
		this->itemStats.push_back(newStat);
	}

} 

void WynnItem::parseRolls(string rollString) { // Parse rolls string.
	double* rolls = new double[16];
	fill(rolls, rolls + 16, -1.0);

	int index = 0;
	istringstream ss(rollString);

	while (ss.peek() != EOF) {
		double roll;
		ss >> roll;
		rolls[index++] = roll;
	}

	index = 0;
	for (auto& stat : itemStats) {
		stat.rollSingleStat(rolls[index++]);
	}

	identificationCnt++;
	delete rolls;
}

bool WynnItem::identifyItem(int ampTier) { // Identify an item.
	for (auto& stat : itemStats) {
		stat.rollSingleStat(ampTier);
	}
	identificationCnt++;
	return true;
}


bool WynnItem::rerollingItem(int ampTier) { // Rerolling an item.
	for (auto& stat : itemStats) {
		stat.rerollingSingleStat(ampTier);
	}
	identificationCnt++;
	return true;
}


bool WynnItem::displayItem() { // Display an item.
	cout << "You identified " << itemName << " [" << identificationCnt << "]!" <<endl;
	for (auto& stat : itemStats) {
		stat.listStatProperties();
	}
	return true;
}

double WynnItem::getStat(string statName) {
	for (auto& stat : itemStats) {
		if (statName.compare(stat.getStatName()) == 0) {
			return stat.getRoundedStat();
		}
	}
}
