#include"itemStat.h"

#include<iomanip>

using namespace std;

SingleStat::SingleStat(string name, double base, int favorType) {
	statName = name;
	statBase = base;
	statFlag = isPositiveStat(base);
	statRoll = -1;
	statFavorType = favorType;
}

SingleStat::SingleStat(string name, double base, double roll, int favorType) {
	statName = name;
	statBase = base;
	statFlag = isPositiveStat(base);
	statFavorType = favorType;

	statRoll = roll;
	roundedStat = roundStat(base, roll);
	// initStatValueMap();
}


void SingleStat::rollSingleStat(int tier) { // Rolling a single stat, taking amps into account.
	int roll;
	if (statFlag) {
		roll = (30 + rand() % 101);
		this->statRoll = roll;
		applyAmplifier(tier);
	}
	else {
		roll = 70 + rand() % 61;
		this->statRoll = roll;
	}

	this->roundedStat = roundStat(statBase, statRoll);

}


void SingleStat::rollSingleStat(double roll) { // Rolling a single stat with a given true roll.
	double trueRoll = roll;
	statRoll = trueRoll;
	roundedStat = roundStat(statBase, statRoll);
}


void SingleStat::rerollingSingleStat(int tier) { // Rerolling a single stat.
	rollSingleStat(tier);
}


int SingleStat::roundStat(double base, double roll) { // Rounding a single stat.
	double tmpStat = base * roll / 100;
	if (statFlag) {
		return round(tmpStat);
	}
	else {
		int ret;
		double tmp1 = fmod(tmpStat, 0.5);
		double tmp2 = fmod(tmpStat, 1.0);
		if (fabs(tmp1) < 1e-4 && fabs(tmp2) >= 1e-4) { // Rounding down if -.5
			ret = round(tmpStat) + 1;
		}
		else {
			ret = round(tmpStat);
		}
		return ret;
	}
}


void SingleStat::applyAmplifier(int tier) { // Applies amplifier based on tiers.

	if (statFlag) {
		statRoll += int((POSITIVE_MAX - statRoll) * (double(tier) * AMPLIFIER_CONST));
	}
	else { // unused equivalent amp method for negative stats.
		// statRoll -= int((statRoll - NEGATIVE_MIN) * (double(tier) * AMPLIFIER_CONST));
	}
}


bool SingleStat::isPositiveStat(double base) {
	return base > 0 ? true : false;
}



#if 0
void initStatValueMap() { // Initialize Wynntils-style percentage analysis.
	double highest, lowest;
	if (statFlag) {
		highest = roundStat(statBase, POSITIVE_MAX);
		lowest = roundStat(statBase, POSITIVE_MIN);
		if (statFavorType == PosHi) { // Higher roll results in more preferrable result.

		}
		else {

		}
	}
	else {
		highest = roundStat(statBase, NEGATIVE_MIN);
		lowest = roundStat(statBase, NEGATIVE_MAX);
		if (statFavorType == NegLo) { // Lower roll results in more preferable result.

		}
		else {

		}
	}
}
#endif;

void SingleStat::listStatProperties() { // Displaying detailed stat info.

	// TODO: reformat this part later.

#if RICH_PRESENCE
	cout << "---------------------" << endl;
	cout << "Property: " << statName << endl;
	cout << "True roll: " << statRoll << endl;
	cout << "Stat Value: " << '(' << statBase << ')' << roundedStat << endl;
	cout << "---------------------" << endl;
#endif;
#if !RICH_PRESENCE
	cout << setiosflags(ios::fixed) << setprecision(1);
	if (statFlag) {
		if (statFavorType == PosLo) {
			cout << setiosflags(ios::left) << setw(12) << statName << ": " << setw(6) << roundedStat <<
				" [" << setw(5) << 130 - statRoll << "%]" <<
				" (" << setw(5) << roundStat(statBase, POSITIVE_MIN) << " - " <<
				setw(5) << roundStat(statBase, POSITIVE_MAX) << ')' << endl;
		}
		else {
			cout << setiosflags(ios::left) << setw(12) << statName << ": " << setw(6) << roundedStat <<
				" [" << setw(5) << statRoll - 30 << "%]" <<
				" (" << setw(5) << roundStat(statBase, POSITIVE_MIN) << " - " <<
				setw(5) << roundStat(statBase, POSITIVE_MAX) << ')' << endl;
		}
	}
	else {
		if (statFavorType == NegHi) {
			cout << setiosflags(ios::left) << setw(12) << statName << ": " << setw(6) << roundedStat <<
				" [" << setw(5) << ((statRoll - 70) / 60) * 100 << "%]" <<
				" (" << setw(5) << roundStat(statBase, NEGATIVE_MIN) << " - " <<
				setw(5) << roundStat(statBase, NEGATIVE_MAX) << ')' << endl;
		}
		else {
			cout << setiosflags(ios::left) << setw(12) << statName << ": " << setw(6) << roundedStat <<
				" [" << setw(5) << (1 - ((statRoll - 70) / 60)) * 100 << "%]" <<
				" (" << setw(5) << roundStat(statBase, NEGATIVE_MIN) << " - " <<
				setw(5) << roundStat(statBase, NEGATIVE_MAX) << ')' << endl;
		}
	}
#endif;

}