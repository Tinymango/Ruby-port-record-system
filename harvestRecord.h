#include <fstream>
#include <string>

using namespace std; 


class harvestRecord {
public: 
	harvestRecord();
	~harvestRecord();
	bool harvestAddRec(int id, string &supplier_name, string &grape_variety, string &quantity, string &harvestSugar, string &ripeness, string &harvestDate, string &harvestName, string &harvestNote); // , int &harvest_sugar, int &harvest_TA, int &solids, string &date, string &harvest_name, string &harvest_note
	bool harvestGetRec(int id, string &supplier_name, string &grape_variety, string &quantity, string &harvestSugar, string &ripeness, string &harvestDate, string &harvestName, string &harvestNote); // , int &harvest_sugar, int &harvest_TA, int &solids, string &date, string &harvest_name, string &harvest_not

private: 
	fstream harvestFile; 
};
