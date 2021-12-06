/******************************************************
 * Filename		:	BaseFeature.h
 * Author		:	Hayrullah Uður Güvenen
 * Date			: 	06.01.2021
 * Description	:	Header File of BaseFeature Class
 * ***************************************************/

#ifndef BASEFEATURE_H
#define BASEFEATURE_H

#include <string>
#include <vector>

using namespace std;

/// BaseFeature Class Definition
class BaseFeature
{
	public:
		/// Constructor
		BaseFeature();
		/// set Idcode
		void setId(string);
		/// set Height
		void setHeight(string);
		/// set Lenght
		void setLength(string);
		/// set Width
		void setWidth(string);
		/// set energy consumption
		void setEnergyCons(string);
		/// set engine power
		void setEnginePower(string);
		/// set engine rotation
		void setEngineRotation(string);
		/// get Id
		string getId();
		/// get Height
		string getHeight();
		/// get Lenght
		string getLength();
		/// get Width
		string getWidth();
		/// get Energy Consumption
		string getEnergyCons();
		/// get Engine Power
		string getEnginePower();
		/// get Engine Rotation
		string getEngineRotation();

	protected:
		/// define parameter for BaseFeature class
		string id;
		int height;
		int length;
		int width;
		string energyCons;
		double enginePower;
		int engineRotation;
		string line;
		vector<string> tokenlist;
};

#endif
