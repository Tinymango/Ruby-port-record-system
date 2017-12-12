//
//  fermentRecord.cpp
//  final project
//
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "fermentRecord.h"
fermentRecord::fermentRecord() {
    fermentFile.open("Ferment_Record.txt", ios::out | ios::in | ios::trunc);
    if (!fermentFile) {
        cout << "Error attempting to open file" << endl;
        return;
    }
    // sugar content, alcohol content, fermentation tempreature, wine color
    // Each record will have the following size:
    // sugar content -- 10 bytes + newline
    // alcohol content -- 10 bytes + newline
    // fermentation temperature -- 10 bytes + newline
    // wine color -- 10 bytes + newline
    // time -- 20 bytes + newline
    // Recorder name -- 30 bytes + newline
    // Notes -- 30 bytes + newline
    
    // Put blanks in for all 100 records
    for (int i = 0; i<100; i++) {
        fermentFile << "          " << endl;
        fermentFile << "          " << endl;
        fermentFile << "          " << endl;
    }
}

fermentRecord::~fermentRecord()
{
    fermentFile.close();
}


bool fermentRecord::fermentGetRec(int fermentId, string &fermentSugar, string &fermentAlcohol, string &temperature, string &color, string &time, string &fermentName, string &fermentNotes)
{
    // First, validate id
    if ((fermentId < 0) || (fermentId > 99)) {
        cout << "Error, invalid record id" << endl;
        return false;
    }
    
    // Seek to correct location in file
    int offset = 73 * fermentId;
    fermentFile.seekg(offset);
    
    char buf[73];  // longest possible string
    
    // Retrieve data from file
    fermentFile.getline(buf, 11);
    fermentSugar = buf;
    fermentFile.getline(buf, 11);
    fermentAlcohol = buf;
    fermentFile.getline(buf, 11);
    temperature = buf;
    fermentFile.getline(buf, 11);
    color = buf;
    fermentFile.getline(buf, 21);
    time = buf;
    fermentFile.getline(buf, 31);
    fermentName = buf;
    fermentFile.getline(buf, 31);
    fermentNotes = buf;
    
    /*If name is empty, this is not a valid record
     if (name[0] == ' ')
     return false;*/
    return true;
}

bool fermentRecord::fermentAddRec(int fermentId, string &fermentSugar, string &fermentAlcohol, string &temperature, string &color, string &time, string &fermentName, string &fermentNotes)
{
    string ferment_sugar = fermentSugar;
    string ferment_alcohol = fermentAlcohol;
    string temp = temperature;
    string fermentColor = color;
    string fermentTime = time;
    string ferment_name = fermentName;
    string ferment_notes = fermentNotes;
    
    // First, validate id
    if ((fermentId < 0) || (fermentId > 99)) {
        cout << "Error, invalid record id" << endl;
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
    for (int i = fermentSugar.length(); i<10; i++)
        ferment_sugar += " ";
    
    for (int j = fermentAlcohol.length(); j<10; j++)
        ferment_alcohol += " ";
    
    for (int k = temperature.length(); k<10; k++)
        temp += " ";
    
    for (int l = color.length(); l < 10; l++)
        fermentColor += " ";
    
    for (int a = time.length(); a < 20; a++)
        fermentTime += " ";
    
    for (int t = fermentName.length(); t < 30; t++)
        ferment_name += " ";
    
    for (int r = ferment_notes.length(); r < 30; r++)
        ferment_notes += " ";
    
    
    
    
    // Next, advance to proper place in file
    int offset = (127 * fermentId);
    //"Writing record, seeking to:  offset 
    fermentFile.seekp(offset);
    
    // write data
    fermentFile << ferment_sugar << endl;
    offset=offset+11;
    fermentFile.seekp(offset);
    fermentFile << ferment_alcohol << endl;
    offset=offset+11;
    fermentFile.seekp(offset);
    fermentFile << temp << endl;
    offset=offset+11;
    fermentFile.seekp(offset);
    fermentFile << fermentColor << endl;
    offset=offset+11;
    fermentFile.seekp(offset);
    fermentFile << fermentTime << endl;
    offset=offset+21;
    fermentFile.seekp(offset);
    fermentFile << ferment_name << endl;
    offset=offset+31;
    fermentFile.seekp(offset);
    fermentFile << ferment_notes << endl;
    
    return true;
}

