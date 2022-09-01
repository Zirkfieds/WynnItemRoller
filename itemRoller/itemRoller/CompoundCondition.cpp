#include "conditionAnalysis.h"

#include<regex>

CompoundCondition::CompoundCondition(string expr, vector<SingleCondition>& cond) {
	this->rawExpression = expr;
	for (auto& c : cond) {
		this->conditions.push_back(c);
	}
	this->flag = false;
}

CompoundCondition::CompoundCondition(string expr) {
	this->rawExpression = expr;
	this->flag = true;
}

bool CompoundCondition::matchAllConditions() {

	return true;
}

void CompoundCondition::addCondition(SingleCondition& cond) {

}

void removeCondition(string stat) {

}

bool statComparison(WynnItem& const item) {
	vector<SingleStat> stats = item.getAllStats();

	return true;
}