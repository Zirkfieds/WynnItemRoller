#pragma once

#include<iostream>

#include<vector>
#include<map>

// TODO: finish the gambling condition analysis.

using namespace std;

class SingleCondition {
private:
	enum operatorType {
		EQL = 0, NOT_EQL, GREATER, GREATER_OR_EQL, LESSER, LESSER_OR_EQL
	};
	string statName;
	int statKey;
	int oprType;
	double statValue;

public:

};

class ComplexCondition {
private:

	string rawExpression;
	vector<SingleCondition> conditions;

public:

};