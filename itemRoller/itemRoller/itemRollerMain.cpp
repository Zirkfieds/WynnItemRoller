#include"itemRoller.h"

#include<conio.h>

int main() {
	srand(time(NULL));

	// TODO: Import full item db.
	// TODO: Make a map for all stats

#if 0
	// Manually parsed items listed below, will be discarded soon.
	string toxoStatString = "Poison 10000 1 Life_Steal 500 1 Mana_Steal 18 1 Walk_Speed 20 1 Loot_Bonus 20 1";
	string oblivStatString = "Raw_Spell 265 1 Mana_Regen -30 2 Mana_Steal 15 1 Exploding 40 1 SP_Regen 40 1 2nd_Cost_Raw -20 4";
	string stratiStatString = "Main_Damage 12 1 Spell_Damage 12 1 Health_Bonus -2000 2 Reflection 12 1 Walk_Speed 76 1";
	string idolStatString = "Raw_Spell 264 1 Mana_Regen 10 1 Reflection 30 1 Water_Def 15 1 SP_Regen 30 1 2nd_Cost_Raw -50 4";
	
	string hadalStatString = "Spell_Damage 75 1 Mana_Regen 30 1 3rd_Cost_Pct 112 3 4th_Cost_Pct 112 3";
	string hadalRollString = "39 115 30 130";
#endif;

	string warpStatString = "Regen_Raw -600 2 Regen_Pct -200 2 Mana_Regen -45 2 Air_Damage 15 1 Exploding 50 1 Reflection 90 1 Walk_Speed 180 1 2nd_Cost_Raw -299 4 1st_Cost_Raw 4 3";
	WynnItem* testItem = new WynnItem("Warp", warpStatString);

	int currAmpTier = 3;

	testItem->identifyItem(currAmpTier);
	while (1) {

		// TODO: using expression to determine the conditions of the gambling product.
		while (testItem->getStat("Mana_Regen") <= -33 || 
			testItem->getStat("Walk_Speed") <= 200 || 
			testItem->getStat("Regen_Raw") <= -480)  
		{
			testItem->rerollingItem(currAmpTier);
		}
		system("cls");
		testItem->displayItem();
		system("pause");
		testItem->rerollingItem(currAmpTier);
	}
}