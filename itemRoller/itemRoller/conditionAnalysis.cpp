#include "conditionAnalysis.h"

SingleCondition::SingleCondition(string stat, int oprType, double rvalue) {
	// this->statKey = statsMap.find(stat);
	this->statName = stat;
	this->oprType = oprType;
	this->statValue = rvalue;
}

pair<int, double> SingleCondition::getCondition() {
	return make_pair(this->oprType, this->statValue);

}

bool SingleCondition::isGivenStat(string stat) {
	return !this->statName.compare(stat);
}

string SingleCondition::getStat() {
	return this->statName;
}

bool SingleCondition::checkStat(string stat, double val) {
	if (isGivenStat(stat)) {
		switch (oprType) {
		case EQL:
			return val == this->statValue ? true : false;
		case NOT_EQL:
			return val != this->statValue ? true: false;
		case GREATER:
			return val > this->statValue ? true : false;
		case LESSER:
			return val < this->statValue ? true : false;

		// TODO: ADD OTHER CONDITIONS

		}
	}
}
