//
//  harvestRecord.cpp
//  final project
//
//  Created by Jianing Tang on 12/4/17.
//  Copyright © 2017 Jianing Tang. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
#include "harvestRecord.h"

using namespace std;

harvestRecord::harvestRecord() {
    harvestFile.open("Harvest_Record.txt", ios::out | ios::in | ios::trunc);
    if (!harvestFile) {
        cout << "Error attempting to open file" << endl;
        return;
    }
    // Each record will have the following size:
    // Supplier name -- 40 bytes + newline
    // Grape variety -- 20 bytes + newline
    // Quantity -- 10 bytes + newline
	// Sugar content -- 10 bytes + newline
    // Ripeness -- 40 bytes + newline
    // Date -- 20 bytes + newline
    // Recorder name -- 30 bytes + newline
    // Notes -- 30 bytes + newline
    
    // Put blanks in for all 100 records
    for (int i = 0; i<100; i++) {
        harvestFile << "                                        " << endl; //supplier name
        harvestFile << "                    " << endl; // grape variety
        harvestFile << "          " << endl; //grape quantity
		harvestFile << "          " << endl; //grape sugar content
		harvestFile << "                                        " << endl; //grape ripeness
		harvestFile << "                    " << endl; // Date
		harvestFile << "                              " << endl; //Recorder name
		harvestFile << "                              " << endl; //Notes
    }
}

harvestRecord::~harvestRecord()
{
    harvestFile.close();
}


bool harvestRecord::harvestGetRec(int id, string &supplier_name, string &grape_variety, string &quantity, string &harvestSugar, string &ripeness, string &harvestDate, string &harvestName, string &harvestNote) // , int &harvest_sugar, int &harvest_TA, int &solids, string &date, string &harvest_name, string &harvest_note
{
    // First, validate id
    if ((id < 0) || (id > 99)) {
        cout << "Error, invalid record number" << endl;
        return false;
    }
    
    // Seek to correct location in file
    int offset = 73 * id;
    harvestFile.seekg(offset);
    
    char buf[73];  // longest possible string
    
    // Retrieve data from file
    harvestFile.getline(buf, 41);
    supplier_name = buf;
    harvestFile.getline(buf, 21);
    grape_variety = buf;
    harvestFile.getline(buf, 11);
    quantity = buf;
    
    /*If name is empty, this is not a valid record
     if (name[0] == ' ')
     return false;*/
    
    return true;
}


// Add a record to the specified location with the
// , int &harvest_sugar, int &harvest_TA, int &solids, string &date, string &harvest_name, string &harvest_note
// passed-in data
bool harvestRecord::harvestAddRec(int id, string &supplier_name, string &grape_variety, string &quantity, string &harvestSugar, string &ripeness, string &harvestDate, string &harvestName, string &harvestNote)
{
    string harvestSupplier = supplier_name;
    string harvestGrape = grape_variety;
    string harvestQuantity = quantity;
	string harvest_sugar = harvestSugar;
	string harvestRipe = ripeness;
	string harvest_date = harvestDate;
	string harvest_name = harvestName;
	string harvest_note = harvestNote;
    
    // First, validate id
    if ((id < 0) || (id > 99)) {
        cout << "Error, invalid record number" << endl;
        return false;
    }
    
    // Pad out entries given the following:
    // Supplier name:  40 bytes
    // Grape variety:  20 bytes
    // Quantity: 10 bytes
	// Sugar : 10 bytes
	// Ripeness -- 40 bytes
	// Date -- 20 bytes 
	// Recorder name -- 30 bytes 
	// Notes -- 30 bytes 

    for (int i = supplier_name.length(); i<40; i++)
        harvestSupplier += " ";
    
    for (int j = grape_variety.length(); j<20; j++)
        harvestGrape += " ";
    
    for (int k = quantity.length(); k<10; k++)
        harvestQuantity += " ";

	for (int l = harvestSugar.length(); l < 10; l++)
		harvest_sugar += " ";

	for (int p = ripeness.length(); p < 40; p++)
		harvestRipe += " ";

	for (int t = harvestDate.length(); t < 20; t++)
		harvest_date += " ";
	
	for (int q = harvestName.length(); q < 30; q++)
		harvest_name += " ";

	for (int m = harvestNote.length(); m < 30; m++)
		harvest_note += " ";
	
    
    // Next, advance to proper place in file
    int offset = (208 * id);
    // Adding record, seeking to:  offset 
    harvestFile.seekp(offset);
    
    // write data
    harvestFile << harvestSupplier << endl;
    offset=offset+41;
    harvestFile.seekp(offset);
    harvestFile << harvestGrape << endl;
    offset=offset+21;
    harvestFile.seekp(offset);
    harvestFile << harvestQuantity << endl;
	offset = offset + 11;
	harvestFile << harvestSugar << endl;
	offset = offset + 11;
	harvestFile << ripeness << endl;
	offset = offset + 41;
	harvestFile << harvestDate << endl;
	offset = offset + 21;
	harvestFile << harvestName << endl;
	offset = offset + 31;
	harvestFile << harvestNote << endl;
	offset = offset + 31;

		// Supplier name:  40 bytes
		// Grape variety:  20 bytes
		// Quantity: 10 bytes
		// Sugar : 10 bytes
		// Ripeness -- 40 bytes
		// Date -- 20 bytes 
		// Recorder name -- 30 bytes 
		// Notes -- 30 bytes
    return true;
}

