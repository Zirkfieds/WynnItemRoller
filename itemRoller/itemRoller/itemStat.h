#pragma once
#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
#include<vector>
#include<map>

using namespace std;

#define POSITIVE_MAX 130.0
#define POSITIVE_MIN 30.0
#define NEGATIVE_MAX 130.0
#define NEGATIVE_MIN 70.0

#define AMPLIFIER_CONST 0.05

#define RICH_PRESENCE 0

class SingleStat {
private:
	enum favorType {
		NONE = 0, PosHi, NegLo, PosLo, NegHi
	};
	string statName;

	double statBase;
	bool statFlag;
	double statRoll;
	int roundedStat;

	int statFavorType;

	map<int, double> statValueMap;

public:
	SingleStat(string name, double base, double roll, int favorType);
	SingleStat(string name, double base, int favorType);

	void rollSingleStat(int tier);					// Rolling a single stat, taking amps into account.
	void rollSingleStat(double roll);				// Rolling a single stat with a given true roll.

	void rerollingSingleStat(int tier);				// Rerolling a single stat.
	int roundStat(double base, double roll);		// Rounding a single stat.

	void applyAmplifier(int tier);					// Applies amplifier based on tiers.
	bool isPositiveStat(double base);

	string getStatName() { return this->statName; }
	double getRoundedStat() { return this->roundedStat; }

	void listStatProperties();						// Displaying detailed stat info.
};