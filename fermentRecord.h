#include <fstream>
#include <string>

using namespace std; 


class fermentRecord {
public:
	fermentRecord();
	~fermentRecord();
	bool fermentAddRec(int fermentId, string &fermentSugar, string &fermentAlcohol, string &temperature, string &color, string &time, string &fermentName, string &fermentNotes);
	bool fermentGetRec(int fermentId, string &fermentSugar, string &fermentAlcohol, string &temperature, string &color, string &time, string &fermentName, string &fermentNotes); 

private:
	fstream fermentFile;
};
