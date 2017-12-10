//
//  fortificationRecord.cpp
//  final project
//
//  Created by Jianing Tang on 12/4/17.
//  Copyright © 2017 Jianing Tang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "fortificationRecord.h"

using namespace std;

fortificationRecord::fortificationRecord() {
    fortificationFile.open("Fortification_Record.txt", ios::out | ios::in | ios::trunc);
    if (!fortificationFile) {
        cout << "Error attempting to open file" << endl;
        return;
    }
    // Each record will have the following size:
    // wine spirit add -- 20 bytes + newline
    // sugar content -- 10 bytes + newline
    // alcohol content -- 10 bytes + newline
    // pH -- 5 bytes + newline
    // Date -- 20 bytes + newline
    // Recorder name -- 30 bytes + newline
    // Notes -- 30 bytes + newline
    
    // Put blanks in for all 100 records
    for (int i = 0; i<100; i++) {
        fortificationFile << "                    " << endl;
        fortificationFile << "          " << endl;
        fortificationFile << "          " << endl;
        fortificationFile << "     " << endl;
        fortificationFile << "                    " << endl;
        fortificationFile << "                              " << endl;
        fortificationFile << "                              " << endl;
    }
}

fortificationRecord::~fortificationRecord() {
    fortificationFile.close();
}


// wine spirit add -- 20 bytes + newline
// sugar content -- 10 bytes + newline
// alcohol content -- 10 bytes + newline
// pH -- 5 bytes + newline
// Date -- 20 bytes + newline
// Recorder name -- 30 bytes + newline
// Notes -- 30 bytes + newline
bool fortificationRecord::fortificationGetRec(int fortificationId, string &alcoholAdd, string &finalSugar, string &finalAlcohol, string &pH, string &fortificationDate, string &fortificationName, string &fortificationNotes) {
    // First, validate id
    if ((fortificationId < 0) || (fortificationId > 99)) {
        cout << "Error, invalid record number" << endl;
        return false;
    }
    
    // Seek to correct location in file
    int offset = 132 * fortificationId;
    fortificationFile.seekg(offset);
    
    char buf[73];  // longest possible string
    
    // Retrieve data from file
    fortificationFile.getline(buf, 21);
    alcoholAdd = buf;
    fortificationFile.getline(buf, 11);
    finalSugar = buf;
    fortificationFile.getline(buf, 11);
    finalAlcohol = buf;
    fortificationFile.getline(buf, 6);
    pH = buf;
    fortificationFile.getline(buf, 21);
    fortificationDate = buf;
    fortificationFile.getline(buf, 31);
    fortificationName = buf;
    fortificationFile.getline(buf, 31);
    fortificationNotes = buf;
    
    /*If name is empty, this is not a valid record
     if (name[0] == ' ')
     return false;*/
    return true;
    
}


bool fortificationRecord::fortificationAddRec(int fortificationId, string &alcoholAdd, string &finalSugar, string &finalAlcohol, string &pH, string &fortificationDate, string &fortificationName, string &fortificationNotes)
{
    string alcohol_add = alcoholAdd;
    string final_sugar = finalSugar;
    string final_alcohol = finalAlcohol;
    string fort_pH = pH;
    string fortification_Date = fortificationDate;
    string fortification_name = fortificationName;
    string fortification_notes = fortificationNotes;
    
    // First, validate id
    if ((fortificationId < 0) || (fortificationId > 99)) {
        cout << "Error, invalid record number" << endl;
        return false;
    }
    
    // Pad out entries given the following:
    // Sugar content:  10 bytes
    // alcohol content:  10 bytes
    // fermentation temperature: 10 bytes
    // wine color: 10 bytes
    // time: 20 bytes
    // recorder name: 30 bytes
    // notes: 30 bytes
    for (int i = alcoholAdd.length(); i<10; i++)
        alcohol_add += " ";
    
    for (int j = finalSugar.length(); j<10; j++)
        final_sugar += " ";
    
    for (int k = finalAlcohol.length(); k<10; k++)
        final_alcohol += " ";
    
    for (int l = pH.length(); l < 10; l++)
        fort_pH += " ";
    
    for (int a = fortificationDate.length(); a < 20; a++)
        fortification_Date += " ";
    
    for (int t = fortificationName.length(); t < 30; t++)
        fortification_name += " ";
    
    for (int r = fortificationNotes.length(); r < 30; r++)
        fortification_notes += " ";
    

    // Next, advance to proper place in file
    int offset = (127 * fortificationId);
    //"Writing record, seeking to:  offset 
    fortificationFile.seekp(offset);
    
    // write data
    fortificationFile << alcohol_add << endl;
    offset=offset+11;
    fortificationFile.seekp(offset);
    fortificationFile << final_sugar << endl;
    offset=offset+11;
    fortificationFile.seekp(offset);
    fortificationFile << final_alcohol << endl;
    offset=offset+11;
    fortificationFile.seekp(offset);
    fortificationFile << fort_pH << endl;
    offset=offset+11;
    fortificationFile.seekp(offset);
    fortificationFile << fortification_Date << endl;
    offset=offset+21;
    fortificationFile.seekp(offset);
    offset=offset+31;
    fortificationFile.seekp(offset);
    fortificationFile << fortification_name << endl;
    offset=offset+31;
    fortificationFile.seekp(offset);
    fortificationFile << fortification_notes << endl;
    
    return true;
}
