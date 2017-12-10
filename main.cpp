//
//  main.cpp
//  final project
//
//  Created by Jianing Tang on 12/4/17.
//  Copyright © 2017 Jianing Tang. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include "harvestRecord.h"
#include "fermentRecord.h"
#include "fortificationRecord.h"
using namespace std;

//set each step into array

void sorting() {
    cout << "Sorting is not a critical quality point. However, sorting grapes provides better wine quality. This step is preffered but not required.\n";
    cout << "\n Next step : Crushing\n";
}

void crushing() {
    cout << "Crushing/destemming is not a critical quality point. \n"
    << "Typically, conventional roller crushers are used, and most wineries remove some of stlaks from grapes. \n"
    << "Stalks can add undesirable harsh and bitter characters to the wine. \n"
    << "After crushing, SO2 is added to the must. pH should be less than 3.6. If pH is greater than 3.6, tartaric acid should be added. ";
}

void settling() {
    cout << "Settling is not a critical quality point " << endl;
    cout << "There is no record that is needed to take in this stage. Yay~!" << endl;
}

void aging() {
    cout << "Aging is not a critical quality point " << endl;
    cout << "There is no record that is needed to take in this stage. Yay~!" << endl;
}

void fine() {
    cout << "Fining and filtering is not a critical quality point " << endl;
    cout << "There is no record that is needed to take in this stage. Yay~!" << endl;
}

void bottling() {
    cout << "Bottling is not a critical quality point " << endl;
    cout << "There is no record that is needed to take in this stage. Yay~!" << endl;
}


//*************************************************************************************************************************
//******************************************************  harvest   *******************************************************
//*************************************************************************************************************************



// Each record will have the following size:
// Supplier name -- 40 bytes + newline
// Grape variety -- 20 bytes + newline
// Quantity -- 10 bytes + newline
// Sugar content -- 10 bytes + newline
// TA -- 5 bytes + newline
// Dissolved solids -- 5 bytes + newline
// Date -- 20 bytes + newline
// Recorder name -- 30 bytes + newline
// Notes -- 30 bytes + newline


harvestRecord aharvestRecord;

// int id, string &supplier_name, string &grape_variety, string &quantity,
void harvestAdd() {
    int recordNum;
    string supplier_name, grape_variety, quantity;
    cout << "Please following the instruction to write all the record into the system. " << endl;
    cout << "Enter record number (0-99)" << endl;
    cin >> recordNum;
    cin.ignore();
    
    cout << "Enter supplier Name";
    getline(cin, supplier_name);
    cout << "Enter grape variety";
    getline(cin, grape_variety);
    cout << "Enter grape quantity";
    getline(cin, quantity);
    
    if (aharvestRecord.harvestAddRec(recordNum, supplier_name, grape_variety, quantity)) {
        cout << "Record is added successfully " << endl;
    }
    else {
        cout << "Error attempting to add record" << endl;
    }
}

void harvestUpdate() {
    int recordNum;
    string supplier_name, grape_variety, quantity;
    
    // Ask the user for the record number to update
    cout << "Enter the record number to update(0-99): ";
    cin >> recordNum;
    cin.ignore();
    
    // Make sure it exists
    if (!aharvestRecord.harvestGetRec(recordNum, supplier_name, grape_variety, quantity)) {
        cout << "ERROR:  there is no such record" << endl;
        return;
    }
    
    // Present record for updating
    cout << ((recordNum < 10) ? " " : "") << recordNum << ": " << supplier_name << grape_variety << " " << quantity << endl;
    cout << "Update this record?  <y/n> ";
    char input;
    cin>>input;
    cin.ignore();
    
    // If they don't want to update it, abort
    if (input != 'y') {
        cout << "Aborted..." << endl;
        return;
    }
    
    // Get new data
    cout << "Enter supplier Name ";
    getline(cin, supplier_name);
    cout << "Enter grape variety";
    getline(cin, grape_variety);
    cout << "Enter grape quantity";
    getline(cin, quantity);
    
    // Add new record to inventory
    if (aharvestRecord.harvestAddRec(recordNum, supplier_name, grape_variety, quantity)) {
        cout << "Record added successfully " << endl;
    }
    else {
        cout << "ERROR attempting to add record " << endl;
    }
}

void harvestDelete() {
    int recordNum;
    string supplier_name, grape_variety, quantity;
    
    // Ask the user for the record to delete
    cout << "Enter the record number to delete(0-99): ";
    cin >> recordNum;
    cin.ignore();
    
    // Does it exist?
    if (!aharvestRecord.harvestGetRec(recordNum, supplier_name, grape_variety, quantity)) {
        cout << "ERROR:  no such record" << endl;
        return;
    }
    
    // Present record for delete confirmation
    cout << ((recordNum < 10) ? " " : "") << recordNum << ": " << supplier_name << grape_variety << " " << quantity << endl;
    cout << "Delete this record?  <y/n> ";
    char input;
    cin>>input;
    cin.ignore();
    
    // If they confirm delete, proceed with the delete operation
    if (input == 'y') {
        supplier_name="";
        grape_variety="";
        quantity="";
        if (aharvestRecord.harvestAddRec(recordNum, supplier_name, grape_variety, quantity)) {
            cout << "Record deleted" << endl;
        }
        else {
            cout << "Record could not be deleted" << endl;
        }
    }
    else {
        cout << "Delete aborted" << endl;
    }
}

void harvestList() {
    string supplier_name, grape_variety, quantity;
    
    for (int i = 0; i<100; i++) {
        if (aharvestRecord.harvestGetRec(i, supplier_name, grape_variety, quantity)) {
            cout << ((i < 10) ? " " : "") << i << ": " << supplier_name << grape_variety << " " << quantity << endl;
        }
    }
}

void harvestRecordKeeping() {
    char harvestInput=0;
    
        cout << "Ruby port style wine HACCP record system -- Harvesting \n"
        << "===================================================================================" << endl;
        cout << "Harvesting is a critical quality point (CQP).\n"
        << "Grapes are usually harvested between the end of August and early October, depending on the location of vineyards and the weather condition of the season.\n"
        << "Wine maker should sample the grapes to determin the maturity. The parameters determine the maturity include: sugar content, pH, titratable acidity, dissolved solids"
        << "Enough sugar is essential for fermentation and desired residual sugar. Chaptilization may be allowed, but it not desirable. \n"
        << "Phenolic maturity for grapes is needed for ruby color and aroma (tannis and anthocyanins). Underripe fruit brings unwanted green aromas. \n"
        << "Wine maker should also pay attention to rotness \n";
        cout << "\n=========================================================\n";
        cout << "\n Critical limits : \n"
        << "\n1. Sugar content > 22 Brix \n"
        << "\n2. Qualitative of grape ripeness >= 85% \n"
        << "\n3. Rot percent < 70% \n";
        cout << "\n=========================================================\n";
        cout << "\nMonitoring: \n"<<endl;
        cout <<setw(20)<<"What " << setw(20) << "How" << setw(15) << "Frequency" <<endl;
        cout <<setw(20)<< "Sugar Content " << setw(20) << "Currently unknown" << setw(15) << "Once a day"<<endl;
        cout <<setw(20)<< "Ripeness " << setw(20) << "Visual Inspection" << setw(15) << "Once a day"<<endl;
        //<< setw(50) << "Dissolved solids\n"
        //<< setw(50) << "Sensory analysis for flavor\n";
        cout << "\n=========================================================\n"<<endl;
        cout << "Corrective actions : "<<endl;
        cout<< "1.Sugar content : Chaptalization (if residual sugar is too low)\n"
        << "2.Ripeness : Await ripeness. If berries do not reach full ripeness by time of harvest (ex: bad weather, etc), blend with other grapes\n";
        cout << " \nNext step : Sorting\n"<<endl;
        cout << "In harvesting stage, wine maker should measure sugar content, TA, dissolved solids. After measuring, please use this write them into the system to keep the record. \n"<<endl;
    while (harvestInput!='q'){
        cout << " (a) Add measured to system " << endl;
        cout << " (b) Update item in system " << endl;
        cout << " (c) Delete item in system " << endl;
        cout << " (d) List all items in system " << endl;
        cout << " (q) Quit" << endl << endl;
        cout << "Enter your choice: ";
        
        cin>>harvestInput;
        cin.ignore();
        
        switch (harvestInput)
        {
            case 'a':
                harvestAdd();
                break;
            case 'b':
                harvestUpdate();
                break;
            case 'c':
                harvestDelete();
                break;
            case 'd':
                harvestList();
                break;
            case 'q':
                break;
            default:
                cout << "Unrecognized command"<<endl;
                break;
        }
    }
}

//*************************************************************************************************************************
//****************************************************  fermentation   ****************************************************
//*************************************************************************************************************************


fermentRecord afermentRecord;
// int fermentId, string &fermentSugar, string &fermentAlcohol, string &temperature, string &color, string &time, string &fermentName, string &fermentNotes
void fermentAdd() {
    int recordNum;
    string fermentSugar, fermentAlcohol, temperature, color, time, fermentName, fermentNotes;
    
    cout << "Please following the instruction to write all the record into the system. " << endl;
    cout << "The recommended frequency of measurement during fermentation is one hour." << endl;
    cout << "Enter record number (0-99)" << endl;
    cin >> recordNum;
    cin.ignore();
    
    cout << "Enter sugar content ";
    getline(cin, fermentSugar);
    cout << "Enter alcohol content";
    getline(cin, fermentAlcohol);
    cout << "Enter temperature";
    getline(cin, temperature);
    cout << "Enter color analysis, such as brown, red, etc";
    getline(cin, color);
    cout << "Enter name of the recorder";
    getline(cin, fermentName);
    cout << "Enter other abonomalities during fermentation or notes";
    getline(cin, fermentNotes);
    
    if (afermentRecord.fermentAddRec(recordNum, fermentSugar, fermentAlcohol, temperature, color, time, fermentName, fermentNotes)) {
        cout << "Record added successfully " << endl;
    }
    else {
        cout << "ERROR attempting to add record" << endl;
    }
}


void fermentUpdate() {
    int recordNum;
    string fermentSugar, fermentAlcohol, temperature, color, time, fermentName, fermentNotes;
    
    // Ask the user for the record number to update
    cout << "Enter the record number to update(0-99): ";
    cin >> recordNum;
    cin.ignore();
    
    // Make sure it exists
    if (!afermentRecord.fermentAddRec(recordNum, fermentSugar, fermentAlcohol, temperature, color, time, fermentName, fermentNotes)) {
        cout << "ERROR:  no such record" << endl;
        return;
    }
    
    // Present record for updating
    cout << ((recordNum < 10) ? " " : "") << recordNum << ": " << fermentSugar  << fermentAlcohol << " " << temperature << color << time << fermentName << fermentNotes << endl;
    cout << "Update this record?  <y/n> ";
    char input;
    cin>>input;
    cin.ignore();
    
    // If they don't want to update it, abort
    if (input != 'y') {
        cout << "Aborted..." << endl;
        return;
    }
    
    // Get new data
    cout << "Enter sugar content ";
    getline(cin, fermentSugar);
    cout << "Enter alcohol content";
    getline(cin, fermentAlcohol);
    cout << "Enter temperature";
    getline(cin, temperature);
    cout << "Enter color analysis, such as brown, red, etc";
    getline(cin, color);
    cout << "Enter name of the recorder";
    getline(cin, fermentName);
    cout << "Enter other abonomalities during fermentation or notes";
    getline(cin, fermentNotes);
    
    if (afermentRecord.fermentAddRec(recordNum, fermentSugar, fermentAlcohol, temperature, color, time, fermentName, fermentNotes)) {
        cout << "Record added successfully!" << endl;
    }
    else {
        cout << "ERROR attempting to add record" << endl;
    }
}


void fermentDelete() {
    int recordNum;
    string fermentSugar, fermentAlcohol, temperature, color, time, fermentName, fermentNotes;
    
    // Ask the user for the record to delete
    cout << "Enter the record number to delete(0-99): ";
    cin >> recordNum;
    cin.ignore();
    
    // Does it exist?
    if (!afermentRecord.fermentAddRec(recordNum, fermentSugar, fermentAlcohol, temperature, color, time, fermentName, fermentNotes)) {
        cout << "ERROR:  no such record" << endl;
        return;
    }
    
    // Present record for delete confirmation
    cout << ((recordNum < 10) ? " " : "") << recordNum << ": " << fermentSugar << fermentAlcohol << " " << temperature << color << time << fermentName << fermentNotes << endl;
    cout << "Delete this record?  <y/n> ";
    char input;
    cin>>input;
    cin.ignore();
    
    // If they confirm delete, proceed with the delete operation
    if (input == 'y') {
        fermentSugar="";
        fermentAlcohol="";
        temperature="";
        color="";
        time="";
        fermentName="";
        fermentNotes="";
        if (afermentRecord.fermentAddRec(recordNum, fermentSugar, fermentAlcohol, temperature, color, time, fermentName, fermentNotes)) {
            cout << "Record deleted" << endl;
        }
        else {
            cout << "Record could not be deleted" << endl;
        }
    }
    else {
        cout << "Delete aborted" << endl;
    }
}

void fermentList() {
    string fermentSugar, fermentAlcohol, temperature, color, time, fermentName, fermentNotes;
    
    for (int i = 0; i<100; i++) {
        if (afermentRecord.fermentGetRec(i, fermentSugar, fermentAlcohol, temperature, color, time, fermentName, fermentNotes)) {
            cout << ((i < 10) ? " " : "") << i << ": " << fermentSugar << fermentAlcohol << " " << temperature << color << time << fermentName << fermentNotes << endl;
        }
    }
}

void fermentationRecordKeeping() {
    char fermentInput=0;
    
        cout << "Ruby port style wine HACCP record system -- Fermentation and maceration \n"
        << "===================================================================================" << endl;
        cout << "\n\nFermentation and maceration is a critical quality point \n"
        << "Traditionally fermentation was carried out in shallow (1 m) granite troughts, holding 7-5 tonnes of must, and macereated by regular treading session of barelegged workers. (2003 Lea, Piggott)\n"
        << "Wine maker should pay attention to alcohol content, sugar content, color/tannin, fermentation temperature \n"
        << "Fermentation must be stopped early to get expected residual sugar and sweetness. Color/tannin contributes to wine aroma and flavor profile. Temperature is related to fermentaiton speed and yeast growth\n" << endl;
        cout << "================================================================\n";
        cout << "\n Critical limits : \n"
        << "\n1. Sugar content should be around 10 Brix \n"
        << "\n2. Visual inspection of tannin depends on the wine maker's experience \n"
        << "\n3. Fermentation temperature should be 26-28 degree celcius\n";
        cout << "\n================================================================\n";
        cout << "\nMonitoring: "<<endl;
        cout <<setw(28)<< "What " << setw(18) << "How" << setw(15) << "Frequency" <<endl;
        cout <<setw(28)<< "Sugar and alcohol content " << setw(18) << "currently unknown" << setw(15) << "Once a day"<<endl;
        cout <<setw(28)<< "Color/tannin " << setw(18) << "Visual analysis" << setw(15) << "Once a day"<<endl;
        //<< setw(50) << "sensory analysis \n"
        //<< setw(50) << "Sensory analysis for flavor\n";
        cout << "\n================================================================\n";
        cout << "\nCorrective actions : \n"
        << "\n1. Sugar content/alcohol content :\n"
        << setw(10) << "low: Chaptalization if sugar content is too low\n"
        << setw(10) << "Excess sugar can be fixed by dilution"
        << setw(10) << "If the alcohol content is not right, it can be fixed at fortification step \n"
        << "\n2. Color/tanin : \n"
        << setw(10) << "Pumpover to get more color and tannin extraction";
        cout << " \nNext step : Fortification and pressing \n";
        
        cout << "In fermentation and maceration stage, wine maker should measure sugar content, alcohol content, fermentation tempreature, wine color. After measuring, please use this write them into the system to keep the record. \n";
        while (fermentInput!='q')
        {
            cout << " (1) Write measured to system " << endl;
            cout << " (2) Update item in system " << endl;
            cout << " (3) Delete item in system " << endl;
            cout << " (4) List all items in system " << endl;
            cout << " (q) Quit from fermentation" << endl << endl;
            cout << "Enter your choice: ";
        
            cin>>fermentInput;
            cin.ignore();
        
        switch (fermentInput)
        {
            case '1':
                fermentAdd();
                break;
            case '2':
                fermentUpdate();
                break;
            case '3':
                fermentDelete();
                break;
            case '4':
                fermentList();
                break;
            case 'q':
                break;
            default:
                cout << "Unrecognized command"<<endl;
                break;
        }
    }
}

//*************************************************************************************************************************
//****************************************************  fortification   ***************************************************
//*************************************************************************************************************************


fortificationRecord afortificationRecord;

float spiritCalculate() {
    float alcoholContF, volWine, alcoholContW, desireAlc;
    cout << "In fortification stage, wine maker should calculate how much wine spirit needs to add in order to achieve desired 18-21% alcohol content" << endl;
    cout << "Luckily, this system will calculate for you. Just by inputing some numbers. Let's try!" << endl;
    cout << "The equation of calculating wine spirit needed to add in your wine is : " << endl;
    cout << "X = [V(C-A)]/(B-C) " << endl;
    cout << "X = gallons of fortifying alcohol " << "\n" << "B = alcohol content of fortifying alcohol " << "\n" << "V = gallons of wine " << "\n" << "A = alcohol content of wine " << "\n" << "C = desired alcohol content of fortified wine " << endl;
    cout << "Sample calculation : " << endl;
    cout << "B = 170 proof = 85% of forifying alcohol " << endl;
    cout << "V = 20 gallons " << endl;
    cout << "A = 11.0% " << endl;
    cout << "C = 20.0% " << endl;
    cout << "X = [20(20-11)]/(85-20) = 2.8 gallons. The system will calculate this number for you and give you the result. " << endl;
    cout << "Please enter alcohol content of fortifying alcohol. " << endl;
    cin >> alcoholContF;
    cout << "Please enter gallons of wine (estimated number)." << endl;
    cin >> volWine;
    cout << "Please enter alcohol content of wine. " << endl;
    cin >> alcoholContW;
    cout << "Please enter disired alcohol content of fortified wine. " << endl;
    cin >> desireAlc;
    
    float calcWine = (volWine*(desireAlc - alcoholContW)) / (alcoholContF - desireAlc);
    return calcWine;
}

// string &alcoholAdd, string &finalSugar, string &finalAlcohol, string &pH, string &fortificationDate, string &fortificationName, string &fortificationNotes
void fortificationAdd() {
    int recordNum;
    string alcoholAdd, finalSugar, finalAlcohol, pH, fortificationDate, fortificationName, fortificationNotes;
    
    cout << "Please following the instruction to write all the record into the system. " << endl;
    cout << "The recommended frequency of measurement during fermentation is once per tank, at the end of pressing." << endl;
    cout << "Enter record number (0-99)" << endl;
    cin >> recordNum;
    cin.ignore();
    
    cout << "Enter the gallon of wine spirit added in during fortification (number only) ";
    getline(cin, alcoholAdd);
    cout << "Enter alcohol content";
    getline(cin, finalSugar);
    cout << "Enter temperature";
    getline(cin, finalAlcohol);
    cout << "Enter color analysis, such as brown, red, etc";
    getline(cin, pH);
    cout << "Enter enter time of this entry";
    getline(cin, fortificationDate);
    cout << "Enter the recorder name";
    getline(cin, fortificationName);
    cout << "Enter other abonomalities during fortification and pressing or notes";
    getline(cin, fortificationNotes);
    
    if (afortificationRecord.fortificationAddRec(recordNum, alcoholAdd, finalSugar, finalAlcohol, pH, fortificationDate, fortificationName, fortificationNotes)) {
        cout << "Record added successfully " << endl;
    }
    else {
        cout << "ERROR attempting to add record" << endl;
    }
}

void fortificationUpdate() {
    int recordNum;
    string alcoholAdd, finalSugar, finalAlcohol, pH, fortificationDate, fortificationName, fortificationNotes;
    
    // Ask the user for the record number to update
    cout << "Enter the record number to update(0-99): ";
    cin >> recordNum;
    cin.ignore();
    
    // Make sure it exists
    if (!afortificationRecord.fortificationAddRec(recordNum, alcoholAdd, finalSugar, finalAlcohol, pH, fortificationDate, fortificationName, fortificationNotes)) {
        cout << "ERROR:  no such record" << endl;
        return;
    }
    
    // Present record for updating
    cout << ((recordNum < 10) ? " " : "") << recordNum << ": " << alcoholAdd << finalSugar << " " << finalAlcohol << pH << fortificationDate << fortificationName << fortificationNotes << endl;
    cout << "Update this record?  <y/n> ";
    char input;
    cin>>input;
    cin.ignore();
    
    // If they don't want to update it, abort
    if (input != 'y') {
        cout << "Aborted..." << endl;
        return;
    }
    
    // Get new data
    cout << "Enter the gallon of wine spirit added in during fortification (number only) ";
    getline(cin, alcoholAdd);
    cout << "Enter alcohol content";
    getline(cin, finalSugar);
    cout << "Enter temperature";
    getline(cin, finalAlcohol);
    cout << "Enter color analysis, such as brown, red, etc";
    getline(cin, pH);
    cout << "Enter enter time of this entry";
    getline(cin, fortificationDate);
    cout << "Enter the recorder name";
    getline(cin, fortificationName);
    cout << "Enter other abonomalities during fortification and pressing or notes";
    getline(cin, fortificationNotes);
    
    if (afortificationRecord.fortificationAddRec(recordNum, alcoholAdd, finalSugar, finalAlcohol, pH, fortificationDate, fortificationName, fortificationNotes)) {
        cout << "Record added successfully " << endl;
    }
    else {
        cout << "ERROR attempting to add record" << endl;
    }
}

void fortificationDelete() {
    int recordNum;
    string alcoholAdd, finalSugar, finalAlcohol, pH, fortificationDate, fortificationName, fortificationNotes;
    
    // Ask the user for the record to delete
    cout << "Enter the record number to delete(0-99): ";
    cin >> recordNum;
    cin.ignore();
    
    // Does it exist?
    if (!afortificationRecord.fortificationGetRec(recordNum, alcoholAdd, finalSugar, finalAlcohol, pH, fortificationDate, fortificationName, fortificationNotes)) {
        cout << "ERROR:  no such record" << endl;
        return;
    }
    
    // Present record for delete confirmation
    cout << ((recordNum < 10) ? " " : "") << recordNum << ": " << alcoholAdd << finalSugar << " " << finalAlcohol << pH << fortificationDate << fortificationName << fortificationNotes << endl;
    cout << "Delete this record?  <y/n> ";
    char input;
    cin>>input;
    cin.ignore();
    
    // If they confirm delete, proceed with the delete operation
    if (input == 'y') {
        alcoholAdd="";
        finalSugar="";
        finalAlcohol="";
        pH="";
        fortificationDate="";
        fortificationName="";
        fortificationNotes="";
        if (afortificationRecord.fortificationAddRec(recordNum, alcoholAdd, finalSugar, finalAlcohol, pH, fortificationDate, fortificationName, fortificationNotes)) {
            cout << "Record deleted" << endl;
        }
        else {
            cout << "Record could not be deleted" << endl;
        }
    }
    else {
        cout << "Delete aborted" << endl;
    }
}

void fortificationList() {
    string alcoholAdd, finalSugar, finalAlcohol, pH, fortificationDate, fortificationName, fortificationNotes;
    
    for (int i = 0; i<100; i++) {
        if (afortificationRecord.fortificationGetRec(i, alcoholAdd, finalSugar, finalAlcohol, pH, fortificationDate, fortificationName, fortificationNotes)) {
            cout << ((i < 10) ? " " : "") << i << ": " << alcoholAdd << finalSugar << " " << finalAlcohol << pH << fortificationDate << fortificationName << fortificationNotes << endl;
        }
    }
}

void fortificationRecordKeeping() {
    char fortInput=0;
        cout << "Ruby port style wine HACCP record system -- Fortification and pressing " << endl;
        cout << "===================================================================================" << endl;
        cout << "Fortification and pressing is a critical quality point"
        << "Ruby port style wine is a fortified wine made by adding spirit after fermentation. Fortification stop fermentation immediately before all sugar has been utilized. \n"
        << "The residual sugar in wine is high and provide a sweet flavor. Wine making requires quick extraction of color/tannin, and precise timing for spirit add "
        << "Short aging in neutral oak barrels is an indicative of ruby port style wine \n"
        << "Alcohol content, sugar content and pH are three important points should be focused on in this step. "
        << "18-21% alcohol content and 8-11% residual sugar content are symbol of ruby port style wine. pH can balance with sugar, and contributes to sensory profile of the wine.  \n";
        cout << "\n=========================================================\n";
        cout << "\n Critical limits : \n"
        << "\n1. Alcohol content should be around 18-21% "
        << "\n2. Residual sugar should be 80-120 g/L"
        << "\n3. pH should be less than 3.6\n";
        cout << "\n=========================================================\n";
        cout << "\nMonitoring: "<<endl;
        cout<< setw(20)<< "What " << setw(10) << "How" << setw(45) << "Frequency" <<endl;
        cout<< setw(20)<< "Alcohol content " << setw(10) << "unknown" << setw(45) << "Once per tank, at the end of pressing"<<endl;
        cout<< setw(20)<< "Sugar content " << setw(10) << "unknown" << setw(45) << "Once per tank, at the end of pressing"<<endl;
        cout<< setw(20)<< "pH " << setw(10) << "unknown" << setw(45) << "Once per tank, at the end of pressing"<<endl;
        cout<< "\nSensory profile and flavor should also be monitored at this stage \n";
        cout << "\n=========================================================\n";
        cout << "\n Corrective actions : \n"
        << "\n1. Alcohol content :\n"
        << setw(10) << "low: adding wine spirits if alcohol content is below 18% \n"
        << setw(10) << "high: dilute by adding raw wine if alcohol content is higher than 21% \n"
        << "\n2. Sugar content : \n"
        << setw(10) << "low: Chaptalization if sugar content is less than 80 g/L \n"
        << setw(10) << "high: adding acid to balance the sugar if it's too high \n"
        << "\n3. pH : \n"
        << setw(10) << "low: deacidifing by adding calcium carbonate or other deacidifier if pH is too low \n"
        << setw(10) << "high: adding tartaric acid if pH is higher than 3.6 \n";
        cout << " \nNext step : Settling \n";
        
        spiritCalculate();
        
        cout << "Wine maker should measure sugar content, alcohol content, fermentation tempreature, wine color. After measuring, please use this write them into the system to keep the record. \n" << endl;
    while (fortInput!='q')
    {
        cout << "\n (1) Write measured to system " << endl;
        cout << " (2) Update item in system " << endl;
        cout << " (3) Delete item in system " << endl;
        cout << " (4) List all items in system " << endl;
        cout << " (q) Quit" << endl << endl;
        cout << "Enter your choice: ";
        
        cin>>fortInput;
        cin.ignore();
        
        switch (fortInput)
        {
            case '1':
                fortificationAdd();
                break;
            case '2':
                fortificationUpdate();
                break;
            case '3':
                fortificationDelete();
                break;
            case '4':
                fortificationList();
                break;
            case 'q':
                break;
            default:
                cout << "Unrecognized command";
                break;
        }
    }
}



//*************************************************************************************************************************
//************************************************  mainMenu choices below ************************************************
//*************************************************************************************************************************

// mainMenu case 1: exhibiting the procedure of HACCP
void HACCP_guide() {
    int step_no;
    int i = 0;
    //int userChoice;
    string step_content[9] = { "Grapes harvested/transfered to winery", "Sorting", "Crush/destem", "Fermentation and maceration", "Fortification and Pressing",
        "Seeting", "Aging", "Fine & filter", "Bottling" };
    
    for (step_no = 1; step_no < 10; step_no++) {
        cout << "Step: " << step_no << setw(10) << step_content[i] << endl;
        cout << setw(15) << "|" << endl;
        cout << setw(15) << "|" << endl;
        cout << setw(15) << "|" << endl;
        cout << setw(15) << "V" << endl;
        i++;
    }
    
    //cout << "More information can be found in the record system. " << endl;
    //cout << "Please enter 1 go back to the main menu, enter 2 for record system, enter 3 for author information, enter 4 for acknoledgement " << endl;
    //cin >> userChoice;
    
    
    }


// mainMenu case 2: manipulate record
void recordKeeping() {
    cout << "There are 9 steps for making Ruby port sytle wine. They are : " << endl;
    int step_no;
    int i = 0;
    char choice;
    string step_content[9] = { "Grapes harvested/transfered to winery", "Sorting", "Crush/destem", "Fermentation and maceration", "Fortification and Pressing",
        "Seeting", "Aging", "Fine & filter", "Bottling" };
    
    for (step_no = 1; step_no < 10; step_no++) {
        cout << setw(10) << "Step: (" << step_no << ")"<< step_content[i] << "\n" << endl;
        i++;
    }
    cout<<"   (q) Quit from Critical Control Point Recor Keeping System"<<endl;
    cout << "\n==================================================================================================\n"<< endl;
    cout << "\n" << "However, only three steps are critical quality point. For these three steps, wine makers need to monitor different aspects and record the results into this system." << endl;
    cout << "The record system is only for three quality points, it displays the information for that step, including an introduction, critical limits, monitoring, corrective action, and record system. " << endl;
    cout << "In the record system, it asks wine maker for the measurements needed to record. It's simple and easy, just follow the instructions. " << endl;
    cout << "\nEnter other steps will give you information for that step, but not the record system. " << endl;
    cout << "Please enter the step number (number only) to get more information. Enter q to quit." << endl;
    cin >> choice;
    switch (choice)
    {
        case '1':
            harvestRecordKeeping();
            break;
        case '2':
            sorting();
            break;
        case '3':
            crushing();
            break;
        case '4':
            fermentationRecordKeeping();
            break;
        case '5':
            fortificationRecordKeeping();
            break;
        case '6':
            settling();
            break;
        case '7':
            aging();
            break;
        case '8':
            fine();
            break;
        case '9':
            bottling();
            break;
        case 'q':
            break;
        default:
            cout << "Unrecognized command, please enter valid number " << endl;
            break;
    }
    
}
// mainMenu case 3: author
void author() {
    cout << "\n Author name : Xianjia Zeng " << setw(5) << " MPS candidate; " << setw(5) << "Jianing Tang " << setw(5) << "MPS candidate \n\n"
    << " Address : 129 Stocking Hall, Ithaca, NY 14853-5701 \n\n"
    << " Contact information : xianjiazeng@gmail.com \n\n"
    << " Cornell University Food Science Department \n\n"
    << " Date : Dec 02 2017";
}

// mainMenu case 4: acknowledgement
void acknowledgement() {
    cout << "\n This program is based on FDSC 4500 Winemaking Theory and Practice I HACCP project. The project is desgiend by Xianjia Zeng, Carolyn Schwarts, Shelby Head. " << endl;
	cout << "\n This system is for CS 2024 C++ programming final project. " << endl;
	cout << "\n I would like to thank Professor Dwayne Bershaw and Professor Ron Dinapoli gave us suggestion for our project. \n"
    << "\n I would also thank my partner Jianning Tang, who helped me debug this program. \n"
    << "\n" << "\n" << "\n"
	<< " Xianjia Zeng " << endl;
}
//*************************************************************************************************************************
//**********************************************  mainMenu and display    *************************************************
//*************************************************************************************************************************



void mainMenu(char mainChoice) {
    switch (mainChoice)
    {
        case '1':
            HACCP_guide();
            break;
        case '2':
            recordKeeping();
            break;
        case '3':
            author();
            break;
        case '4':
            acknowledgement();
            break;
        case 'q':
            break;
        default:
            cout << "Unrecognized command\n";
            break;
    }
}


void menuDisplay() {
    char mainChoice=0;
    cout << "***Welcome to Ruby Port Style HACCP plan guide and record keeping system*** " << endl;
    cout << "\nRuby port-style wine is a sweet, fruity, full-bodied dessert wine with smooth, subtle tannins fortified to 18-21% alcohol. \n"
    << "This system is designed for user to get guide of ruby-port wine HACCP plan. Record system is for user to record critical measured.\n";
    
    while (mainChoice != 'q') {
		cout << "\n==================================================================================================\n" << endl;
		cout << setw(22) << "**************" << endl;
		cout << setw(20) << "Main Menu" << endl;
		cout << setw(22) << "**************" << endl;
		cout << "(1) Display Ruby Port flow chart \n" 
		 << "(2) Critical Control Point Record Keeping System\n" 
		 << "(3) Author Information\n" 
		 << "(4) Acknoledgement\n" 
         << "(q) Quit \n" << endl;
        cout << "\n==================================================================================================\n"<<endl;
        cout << "\nPlease enter your choice. (Number only) \n";
        cin>>mainChoice;     // Get next character
        cin.ignore();   // Ignore the newline
        
        mainMenu(mainChoice);
    }
}

//*************************************************************************************************************************
//*******************************************************  main function  *************************************************
//*************************************************************************************************************************




int main() {
    menuDisplay();
    system("pause");
    return 0;
}
