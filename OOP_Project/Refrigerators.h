/******************************************************
 * Filename		:	Refrigerators.h
 * Author		:	Hayrullah Uður Güvenen
 * Date			: 	06.01.2021
 * Description	:	Header File of Refrigerators Class
 * ***************************************************/

#ifndef REFRIGERATORS_H
#define REFRIGERATORS_H

#include <string>
#include <vector>
#include "BaseFeature.h"

using namespace std;

/// Refrigerators Class Definition- Inherit from BaseFeature class
class Refrigerators : public BaseFeature
{
	public:
		/// Constructor
		Refrigerators(string line=" ");
		/// set Minimum Temperature
		void setMinTemp(string);
		/// set Volume
		void setVolume(string);
		/// set Number of Doors
		void setNumberDoors(string);
		/// set Defrost Property
		void setDefrost(string);
		/// set Maximum Cooling Capacity
		void setmMaxCoolingCap(string);
		/// set Number of Refrigerators
		void setNumOfRef(string);
		/// Function to change Number of Refrigerators	
		void changeNumber(int);
		/// Print All Refrigerators
		void printAllRef(vector<Refrigerators>&);
		/// Function to Read from .txt File	
		void ReadFile(vector<Refrigerators>&);
		/// Function to Add Refrigerators to .txt File
		void addRefrigerator(vector<Refrigerators>&);
		/// Function to Change Number of Refrigerators in Inventory
		void change(vector<Refrigerators>& ref);
		/// Function to get All Feature of Refrigerator
		string gettingAllFeature();
		/// get Minimum Temperature
		string getMinTemp();
		/// get Volume
		string getVolume();		
		/// get Number of Doors
		string getNumberDoors();
		/// get Defrost Property
		string getDefrost();
		/// get Maximum Cooling Capacity
		string getMaxCoolingCap();
		/// get Number of Refrigerators
		string getNumOfRef();
		
	protected:
		/// define parameter for Refrigerators class
		int minTemp;
		int volume;
		int numberDoors;
		string defrost;
		int maxCoolingCap;
		int numOfRef;
		vector<Refrigerators>::iterator itref;
};

#endif
