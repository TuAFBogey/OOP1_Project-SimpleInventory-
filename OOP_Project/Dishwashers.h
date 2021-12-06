/******************************************************
 * Filename		:	Dishwashers.h
 * Author		:	Hayrullah Uður Güvenen
 * Date			: 	06.01.2021
 * Description	:	Header File of Dishwashers Class
 * ***************************************************/

#ifndef DISHWASHERS_H
#define DISHWASHERS_H

#include <string>
#include <vector>
#include "BaseFeature.h"

using namespace std;

/// Dishwashers Class Definition - Inherit from BaseFeature class
class Dishwashers : public BaseFeature
{
	public:
		/// Constructor
		Dishwashers(string line=" ");
		/// set Water Consumption
		void setWaterCons(string);
		/// set Number of Programs
		void setPrograms(string);
		/// set Capacity
		void setCapacity(string);
		/// set Number of Racks
		void setRacks(string);
		/// set Maximum Spray Capacity
		void setMaxSprayCap(string);
		/// set Number of Dishwashers
		void setNumOfDish(string);
		/// Change Number of Dishwashers
		void changeNumber(int);
		/// Print All Dishwashers
		void printAllDish(vector<Dishwashers>&);
		/// Function to Read from .txt File	
		void ReadFile(vector<Dishwashers>&);
		/// Function to Add Dishwashers to .txt File
		void addDishwashers(vector<Dishwashers>&);
		/// Function to Change Number of Dishwashers in Inventory
		void change(vector<Dishwashers>&);
		/// Function to get All Feature of Dishwashers
		string getAllFeature();
		/// get Water Consumption
		string getWaterCons();
		/// get Number of Programs
		string getPrograms();
		/// get Capacity
		string getCapacity();
		/// get Cumber of Racks
		string getRacks();
		/// get Maximum Spray Capacity
		string getMaxSprayCap();
		/// get Number of Dishwashers
		string getNumOfDish();		
	
	protected:
	/// define parameter for Dishwashers class
		int waterCons;
		int programs;
		int capacity;
		int racks;
		int maxSprayCap;
		int numOfDish;
		vector<Dishwashers>::iterator itdish;
};

#endif
