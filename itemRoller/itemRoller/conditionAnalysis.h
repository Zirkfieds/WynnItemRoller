#pragma once

#include<iostream>
#include<string>

#include<vector>
#include<map>

#include"WynnItem.h"

// TODO: finish the gambling condition analysis.

using namespace std;

class SingleCondition {
private:

	string statName;
	int statKey;
	int oprType;
	double statValue;

public:
	enum operatorType {
		EQL = 0, NOT_EQL, GREATER, GREATER_OR_EQL, LESSER, LESSER_OR_EQL
	};
	SingleCondition(string stat, int oprType, double rvalue); // Initialize a single condition with operator and rval.
	pair<int, double> getCondition(); // Getter of the rhalf of the expr.
	string getStat(); // Getter of the lhalf of the expr.
	bool isGivenStat(string stat); // Checks if the stat name matches.
	bool checkStat(string stat, double val); // Check whether a stat matches the requirements.

};

class CompoundCondition {
private:

	string rawExpression;
	vector<SingleCondition> conditions;
	bool flag;

public:
	CompoundCondition(string expr, vector<SingleCondition>& cond);
	CompoundCondition(string expr);
	bool matchAllConditions();
	void addCondition(SingleCondition& cond);
	void removeCondition(string stat);
	bool statComparison(WynnItem& item);

	
	

};