#include <fstream>
#include <string>

using namespace std; 

class fortificationRecord {
public:
	fortificationRecord();
	~fortificationRecord();
	bool fortificationAddRec(int fortificationId, string &alcoholAdd, string &finalSugar, string &finalAlcohol, string &pH, string &fortificationDate, string &fortificationName, string &fortificationNotes); // , int &harvest_sugar, int &harvest_TA, int &solids, string &date, string &harvest_name, string &harvest_note
	bool fortificationGetRec(int fortificationId, string &alcoholAdd, string &finalSugar, string &finalAlcohol, string &pH, string &fortificationDate, string &fortificationName, string &fortificationNotes); // , int &harvest_sugar, int &harvest_TA, int &solids, string &date, string &harvest_name, string &harvest_not

private:
	fstream fortificationFile;
};
