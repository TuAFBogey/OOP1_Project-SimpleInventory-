/******************************************************
 * Filename		:	Washmachines.cpp
 * Author		:	Hayrullah Uður Güvenen
 * Date			: 	06.01.2021
 * Description	:	Washmachines Class Implementation
 * ***************************************************/

#include "Washmachines.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cmath>

using namespace std;

/// Constructor initializes parameters
Washmachines::Washmachines(string line)
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
	setWaterCons(tokenlist[5]);
	setPrograms(tokenlist[6]);		
	setCapacity(tokenlist[7]);		
	setSpeed(tokenlist[8]);		
	setEnginePower(tokenlist[9]);
	setEngineRotation(tokenlist[10]);
	setMaxHeatCap(tokenlist[11]);		
	setNumOfWash(tokenlist[12]);	
}   		
/// set Water Consumption	
void Washmachines::setWaterCons(string token)
{
	int temp;
	stringstream(token)>>temp;
	waterCons=abs(temp);
}
/// get Water Consumption
string Washmachines::getWaterCons()
{
	ostringstream temp;
    temp<<waterCons;
 	string temp2=temp.str();
    
	return temp2;
}		
/// set Number of Programs - Returns absolute value even though a negative value is entered
void Washmachines::setPrograms(string token)
{
	int temp;
	stringstream(token)>>temp;
	programs=abs(temp);
}
/// get Number of Programs
string Washmachines::getPrograms()
{
	ostringstream temp;
    temp<<programs;
 	string temp2=temp.str();
    
	return temp2;
}	
/// set Capacity - Returns absolute value even though a negative value is entered
void Washmachines::setCapacity(string token)
{
	int temp;
	stringstream(token)>>temp;
	capacity=abs(temp);
}
/// get Capacity
string Washmachines::getCapacity()
{
	ostringstream temp;
    temp<<capacity;
    string temp2=temp.str();
    
	return temp2;
}    
/// set Squeeze Speed - Returns absolute value even though a negative value is entered	
void Washmachines::setSpeed(string token) 
{
	int temp;
	stringstream(token)>>temp;
	speed=abs(temp);
}
/// get Squeeze Speed
string Washmachines::getSpeed()
{
	ostringstream temp;
    temp<<speed;
 	string temp2=temp.str();
    
	return temp2;
}		
/// set Maximum Heating Capacity - Returns absolute value even though a negative value is entered
void Washmachines::setMaxHeatCap(string token)
{
	int temp;
	stringstream(token)>>temp;
	maxHeatCap=abs(temp);
}
/// get Maximum Heating Capacity
string Washmachines::getMaxHeatCap()
{
	ostringstream temp;
    temp<<maxHeatCap;
 	string temp2=temp.str();
    
	return temp2;
}		
/// set Number of Washing Machines - Returns absolute value even though a negative value is entered
void Washmachines::setNumOfWash(string token)
{
	int temp;
	stringstream(token)>>temp;
	numOfWash=abs(temp);
}
/// get Number of Washing Machines
string Washmachines::getNumOfWash()
{
	ostringstream temp;
    temp<<numOfWash;
 	string temp2=temp.str();
    
	return temp2;
}
/// Change Number of Washing Machines - Returns absolute value even though a negative value is entered
void Washmachines::changeNumber(int number)
{
	numOfWash=abs(number);
}  	
/// getting All Feature of Washing Machines
string  Washmachines::getAllFeature()
{
	return getId()+" "+getHeight()+" "+getLength()+" "+getWidth()+" "+getEnergyCons()+" "+getWaterCons()+" "+getPrograms()+" "+getCapacity()+" "+getSpeed()+" "+getEnginePower()+" "+getEngineRotation()+" "+getMaxHeatCap()+" "+getNumOfWash();	
}
/// Print All Washmachines
void Washmachines::printAllWash(vector<Washmachines> wash)
{
	for(itwash=wash.begin();itwash!=wash.end();itwash++){
    	cout<<(*itwash).getAllFeature()<<endl;
    	}
}
/// Read from .txt File	
void Washmachines::ReadFile(vector<Washmachines>& wash)
{
fstream file("householdAppliances.txt"); 
  	string line;
  	
	while ( getline(file, line) ){
	if(line[0]=='W' || line[0]=='w'){
    		Washmachines W1(line);
    		wash.push_back(W1);
    		cout<<line<<endl;
		}
	}
	file.close();
}
/// Add Washing Machines to .txt File
void Washmachines::addWashmachines(vector<Washmachines>& wash)
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
/// Change Number of Washing Machines in Inventory
void Washmachines::change(vector<Washmachines>& wash) 
{
	string Idcode;
	string Idwash;
	vector<string> tempLines;
	vector<string>::iterator itLines;

	cout<<"Washing machines:"<<endl;

	for(itwash=wash.begin();itwash!=wash.end();itwash++){
    	cout<<(*itwash).getId()<<endl;
    	
	}
    
	cout<<"Please select the ID of product:"<<endl;	
	cin>>Idcode;
	for(itwash=wash.begin();itwash!=wash.end();itwash++){
    	Idwash=(*itwash).getId();
    	if(Idcode==Idwash){
    	
    		int newNumber;
    		cout<<"Enter the new number of washing machines"<<endl;
    		cin>>newNumber;
    		(*itwash).changeNumber(newNumber);
    		
    		fstream inventory("householdAppliances.txt");
      		if ( inventory.is_open() ){
            	string lineId="";
            
            	while ( getline(inventory, lineId) ){
      	
      				tempLines.push_back(lineId);
				}
			}
			inventory.close();
      
      		ofstream inventorynew("householdAppliances.txt");
      		if ( inventorynew.is_open() ){
            	for (itLines=tempLines.begin();itLines!=tempLines.end();itLines++) {
					if((*itLines).find(Idcode)!= std::string::npos){
      	        		inventorynew<<(*itwash).id<<","<<(*itwash).height<<","<<(*itwash).length<<","<<(*itwash).width<<","<<(*itwash).energyCons<<","<<(*itwash).waterCons<<","<<(*itwash).programs<<","<<(*itwash).capacity<<","<<(*itwash).speed<<","<<(*itwash).enginePower<<","<<(*itwash).engineRotation<<","<<(*itwash).maxHeatCap<<","<<(*itwash).numOfWash<<","<<endl;
      					itLines++;  																								
					}
				inventorynew<<(*itLines)<<endl;
				}
			}
			inventorynew.close();
		} 		
	}	
}
