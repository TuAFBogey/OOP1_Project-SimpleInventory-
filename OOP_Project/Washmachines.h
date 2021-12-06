/******************************************************
 * Filename		:	Washmachines.h
 * Author		:	Hayrullah Uður Güvenen
 * Date			: 	06.01.2021
 * Description	:	Header File of Washmachines Class
 * ***************************************************/

#ifndef WASHMACHINES_H
#define WASHMACHINES_H
 
#include <string>
#include <vector>
#include "BaseFeature.h"

using namespace std;

/// Washmachines Class Definition - Inherit from BaseFeature class
class Washmachines : public BaseFeature
{
	public:
		/// Constructor
		Washmachines(string line=" ");
		/// set Water Consumption		
		void setWaterCons(string);
		/// set Number of Programs
		void setPrograms(string);
		/// set Capacity
		void setCapacity(string);
		/// set Squeeze Speed
		void setSpeed(string);
		/// set Maximum Heating Capacity
		void setMaxHeatCap(string);
		/// set Number of Washmachines
		void setNumOfWash(string);
		/// Change Cumber of Washmachines
		void changeNumber(int);
		/// Print All Washmachines
		void printAllWash(vector<Washmachines>);
		/// Function to Read from .txt File	
		void ReadFile(vector<Washmachines>&);
		/// Function to Add Washing Machine to .txt File
		void addWashmachines(vector<Washmachines>&);
		/// Function to Change Number of Washing Machines in Inventory
		void change(vector<Washmachines>&);
		/// Function to get All Feature of Washing Machine
		string getAllFeature();
		/// get Water Consumption
		string getWaterCons();
		/// get Number of Programs
		string getPrograms();
		/// get Capacity
		string getCapacity();
		/// get Squeeze Speed
		string getSpeed();
		/// get Maximum Heating Capacity
		string getMaxHeatCap();
		/// get Number of Washing Machines
		string getNumOfWash();
		
	protected:
		/// define parameter for Washmachines class
		int waterCons;
		int programs;
		int capacity;
		int speed;
		int maxHeatCap;
		int numOfWash;
		vector<Washmachines>::iterator itwash;
};

#endif
