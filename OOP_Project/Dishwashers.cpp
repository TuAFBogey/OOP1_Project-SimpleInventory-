/******************************************************
 * Filename		:	Dishwashers.cpp
 * Author		:	Hayrullah Uður Güvenen
 * Date			: 	06.01.2021
 * Description	:	Dishwashers Class Implementation
 * ***************************************************/

#include "Dishwashers.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cmath>

using namespace std;

/// Constructor initializes parameters
Dishwashers::Dishwashers(string line)
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
	setRacks(tokenlist[8]);
	setEnginePower(tokenlist[9]);
	setEngineRotation(tokenlist[10]);
	setMaxSprayCap(tokenlist[11]);	
	setNumOfDish(tokenlist[12]);
}
/// set Water Consumption - Returns absolute value even though a negative value is entered	
void Dishwashers::setWaterCons(string token)
{
	int temp;
	stringstream(token)>>temp;
	waterCons=abs(temp);

}
/// get Water Consumption
string Dishwashers::getWaterCons()
{
	ostringstream temp;
    temp<<waterCons;
 	string temp2=temp.str();
    
	return temp2;
}
/// set Number of Programs - Returns absolute value even though a negative value is entered	
void Dishwashers::setPrograms(string token)
{
	int temp;
	stringstream(token)>>temp;
	programs=abs(temp);
}
/// get Number of Programs
string Dishwashers::getPrograms()
{
	ostringstream temp;
    temp<<programs;
 	string temp2=temp.str();
    
	return temp2;
}	
/// set Capacity - Returns absolute value even though a negative value is entered
void Dishwashers::setCapacity(string token)
{
	int temp;
	stringstream(token)>>temp;
	capacity=abs(temp);
	
}
/// get Capacity
string Dishwashers::getCapacity()
{
	ostringstream temp;
    temp<<capacity;
 	string temp2=temp.str();
    
	return temp2;
}
/// set Number of Racks - Returns absolute value even though a negative value is entered		
void Dishwashers::setRacks(string token)
{
	int temp;
	stringstream(token)>>temp;
	racks=abs(temp);
}
/// get Number of Racks
string Dishwashers::getRacks()
{
	ostringstream temp;
    temp<<racks;
 	string temp2=temp.str();
    
	return temp2;
}
/// set Maximum Spray Capacity - Returns absolute value even though a negative value is entered		
void Dishwashers::setMaxSprayCap(string token)
{
	int temp;
	stringstream(token)>>temp;
	maxSprayCap=abs(temp);
}
/// get Maximum Spray Capacity
string Dishwashers::getMaxSprayCap()
{
	ostringstream temp;
    temp<<maxSprayCap;
 	string temp2=temp.str();
    
	return temp2;
}
/// set Number of Dishwashers - Returns absolute value even though a negative value is entered		
void Dishwashers::setNumOfDish(string token)
{
	int temp;
	stringstream(token)>>temp;
	numOfDish=abs(temp);
}
/// get Number of Dishwashers
string Dishwashers::getNumOfDish()
{
	ostringstream temp;
    temp<<numOfDish;
 	string temp2=temp.str();
    
	return temp2;
}
/// Change Number of Dishwashers - Returns absolute value even though a negative value is entered
void Dishwashers::changeNumber(int number)
{
	numOfDish=abs(number);
}  	
/// getting All Feature of Dishwashers
string  Dishwashers::getAllFeature()
{
	return getId()+" "+getHeight()+" "+getLength()+" "+getWidth()+" "+getEnergyCons()+" "+getWaterCons()+" "+getPrograms()+" "+getCapacity()+" "+getRacks()+" "+getEnginePower()+" "+getEngineRotation()+" "+getMaxSprayCap()+" "+getNumOfDish();
	
}
/// Print All Dishwashers
void Dishwashers::printAllDish(vector<Dishwashers>& dish)
{
	for(itdish=dish.begin();itdish!=dish.end();itdish++){
    	cout<<(*itdish).getAllFeature()<<endl;
   }
}
/// Read from .txt File	
void Dishwashers::ReadFile(vector<Dishwashers>& dish)
{
fstream file("householdAppliances.txt");
  	string line;
  	
	while ( getline(file, line) ){
	if(line[0]=='D' || line[0]=='d'){
    		Dishwashers D1(line);
    		dish.push_back(D1);
    		cout<<line<<endl;
		}
	}
	file.close();
}
/// Add Dishwashers to .txt File
void Dishwashers::addDishwashers(vector<Dishwashers>& dish)
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
/// Change Number of Dishwashers in Inventory
void Dishwashers::change(vector<Dishwashers>& dish) 
{
	string Idcode;
	string Iddish;
	vector<string> tempLines;
	vector<string>::iterator itLines;

	cout<<"Dishwashers:"<<endl;
	
	for(itdish=dish.begin();itdish!=dish.end();itdish++){
    	cout<<(*itdish).getId()<<endl;
	}
    
	cout<<"Please select the ID of product:"<<endl;	
	cin>>Idcode; 
	
	for(itdish=dish.begin();itdish!=dish.end();itdish++){
    	Iddish=(*itdish).getId();
    	if(Idcode==Iddish){
    		int newNumber;
    		cout<<"Enter the new number of dishwashers"<<endl;
    		cin>>newNumber;
    		(*itdish).changeNumber(newNumber);
    		
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
      	        		inventorynew<<(*itdish).id<<" "<<(*itdish).height<<" "<<(*itdish).length<<" "<<(*itdish).width<<" "<<(*itdish).energyCons<<" "<<(*itdish).waterCons<<" "<<(*itdish).programs<<" "<<(*itdish).capacity<<" "<<(*itdish).racks<<" "<<(*itdish).enginePower<<" "<<(*itdish).engineRotation<<" "<<(*itdish).maxSprayCap<<" "<<(*itdish).numOfDish<<" "<<endl;
      					itLines++;
					}
				inventorynew<<(*itLines)<<endl;
				}
			}
			inventorynew.close();
		} 		
	}	
}
