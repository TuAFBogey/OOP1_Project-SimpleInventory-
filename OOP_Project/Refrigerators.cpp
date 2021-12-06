/******************************************************
 * Filename		:	Refrigerators.cpp
 * Author		:	Hayrullah Uður Güvenen
 * Date			: 	06.01.2021
 * Description	:	Refrigerators Class Implementation
 * ***************************************************/

#include "Refrigerators.h"
#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <cmath>

using namespace std;

/// Constructor initializes parameters
Refrigerators::Refrigerators(string line)
:BaseFeature() /// member initialize for BaseFeature class constructor
{
	int pos = 0;
	string token;

	while ((pos = line.find(" ")) != string::npos) {
    token = line.substr(0, pos);
    
    tokenlist.push_back(token);
    line.erase(0, pos + 1);
}
    /// Calling set Functions
    setId(tokenlist[0]);
    setHeight(tokenlist[1]);
    setLength(tokenlist[2]);
    setWidth(tokenlist[3]);
	setEnergyCons(tokenlist[4]);
    setMinTemp(tokenlist[5]);
    setVolume(tokenlist[6]);
    setNumberDoors(tokenlist[7]);
    setDefrost(tokenlist[8]);
    setEnginePower(tokenlist[9]);
	setEngineRotation(tokenlist[10]);
    setmMaxCoolingCap(tokenlist[11]);
    setNumOfRef(tokenlist[12]);
}
/// set Minimum Temperature
void Refrigerators::setMinTemp(string token)
{
	int temp;
	stringstream(token)>>temp;
	minTemp=temp;    
}
/// get Minimum Temperature
string Refrigerators::getMinTemp()
{
	ostringstream temp;
    temp<<minTemp;
 	string temp2=temp.str();
    
	return temp2;
}
/// set Volume - Returns absolute value even though a negative value is entered
void Refrigerators::setVolume(string token)
{
	int temp;
	stringstream(token)>>temp;
	volume=abs(temp);
}
/// get volume
string Refrigerators::getVolume()
{
	ostringstream temp;
    temp<<volume;
 	string temp2=temp.str();
    
	return temp2;
}
/// set Number of Doors - Returns absolute value even though a negative value is entered
void Refrigerators::setNumberDoors(string token)
{
    int temp;
	stringstream(token)>>temp;
	numberDoors=abs(temp);
}
/// get Number of Doors
string Refrigerators::getNumberDoors()
{
	ostringstream temp;
    temp<<numberDoors;
 	string temp2=temp.str();
    
	return temp2;
}
/// set Defrost Property to 't/T' or 'f/F'
void Refrigerators::setDefrost(string token)
{
	if(token[0]=='t' || token[0]=='T') {token[0] = 'T'; }
	else if(token[0]=='f' || token[0]=='F') {token[0] = 'F'; }
	else throw invalid_argument("t/T or f/F must be entered!");
	if(token[0]=='T' || token[0]=='F'){	defrost=token; }
	else throw invalid_argument("t/T or f/F must be entered!");
}
/// get Defrost Property
string Refrigerators::getDefrost()
{
	return defrost;
}
/// set Maximum Cooling Capacity - Returns absolute value even though a negative value is entered
void Refrigerators::setmMaxCoolingCap(string token)
{
	int temp;
	stringstream(token)>>temp;
	maxCoolingCap=abs(temp);
}
/// get Maximum Cooling Capacity
string Refrigerators::getMaxCoolingCap()
{
	ostringstream temp;
    temp<<maxCoolingCap;
 	string temp2=temp.str();
    
	return temp2;
}
/// set Number of Refrigerators - Returns absolute value even though a negative value is entered
void Refrigerators::setNumOfRef(string token)
{
	int temp;
	stringstream(token)>>temp;
	numOfRef=abs(temp);
}
/// get Number of Refrigerators
string Refrigerators::getNumOfRef()
{
	ostringstream temp;
    temp<<numOfRef;
 	string temp2=temp.str();
    
	return temp2;
}
/// Change Number of Refrigerators - Returns absolute value even though a negative value is entered	
void Refrigerators::changeNumber(int number)
{
	numOfRef=abs(number);
}
/// getting All Feature of Refrigerators
string Refrigerators::gettingAllFeature()
{
	return getId()+" "+getHeight()+" "+getLength()+" "+getWidth()+" "+getEnergyCons()+" "+getMinTemp()+" "+getVolume()+" "+getNumberDoors()+" "+getDefrost()+" "+getEnginePower()+" "+getEngineRotation()+" "+getMaxCoolingCap()+" "+getNumOfRef();
}
/// Print All Refrigerators
void Refrigerators::printAllRef(vector<Refrigerators>& ref)
{ 
	for(itref=ref.begin();itref!=ref.end();itref++){
    	cout<<(*itref).gettingAllFeature()<<endl;
    }
}
/// Read from .txt File	
void Refrigerators::ReadFile(vector<Refrigerators>& ref) 
{
	fstream file("householdAppliances.txt"); 
  	string line;
  	
	while ( getline(file, line) ){
	if(line[0]=='R' || line[0]=='r'){
    		Refrigerators R1(line);
    		ref.push_back(R1);
    		cout<<line<<endl;
		}
	}
	file.close(); 
}
/// Add Refrigerators to .txt File
void Refrigerators::addRefrigerator(vector<Refrigerators>& ref)
{
	cout<<"Write with a space between the features. (a b c ...)"<<endl;
	string line;
	
	ofstream file;
  	file.open ("householdAppliances.txt",ios::app);
  	file << endl;
  	for(int i=0; i<13; i++){
  	cin>>line;
  	file << line+" ";
  	}
  	file.close(); 
}
/// Change Number of Refrigerators in Inventory
void Refrigerators::change(vector<Refrigerators>& ref)
{
	string Idcode;
	string Idref;
	vector<string> tempLines;
	vector<string>::iterator itLines;

	cout<<"Refrigerators:"<<endl;

	for(itref=ref.begin();itref!=ref.end();itref++){
    	cout<<(*itref).getId()<<endl;
    }
    
	cout<<"Please select the ID of product:"<<endl;	
	cin>>Idcode;

	for(itref=ref.begin();itref!=ref.end();itref++){
    	Idref=(*itref).getId();
    	if(Idcode==Idref){
    		int newNumber;
    		cout<<"Enter the new number of refrigerators"<<endl;
    		cin>>newNumber; 
    		(*itref).changeNumber(newNumber); 
    		
    		fstream inventory("householdAppliances.txt"); 
      			if ( inventory.is_open() ){
            		string lineId="";
            			while ( getline(inventory, lineId) ){
      						tempLines.push_back(lineId); 
						}
				}
      			inventory.close(); 
    		
				ofstream inventorynew("householdAppliances.txt");  
   					if (inventorynew.is_open()){
           				for (itLines=tempLines.begin();itLines!=tempLines.end();itLines++) {
							if((*itLines).find(Idcode)!= std::string::npos){
   	        					inventorynew<<(*itref).id<<" "<<(*itref).height<<" "<<(*itref).length<<" "<<(*itref).width<<" "<<(*itref).energyCons<<" "<<(*itref).minTemp<<" "<<(*itref).volume<<" "<<(*itref).numberDoors<<" "<<(*itref).defrost<<" "<<(*itref).enginePower<<" "<<(*itref).engineRotation<<" "<<(*itref).maxCoolingCap<<" "<<(*itref).numOfRef<<" "<<endl;
   								itLines++;
							}
							inventorynew<<(*itLines)<<endl;	
							}
					}
					inventorynew.close();
		}		
	}
}
