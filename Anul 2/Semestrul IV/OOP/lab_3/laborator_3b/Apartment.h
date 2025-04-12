#pragma once

#include "IRoom.h"
#include <vector>

class Apartment
{
	private:
		vector<IRoom> Rooms;
		double PricePerSqMeter;
	public:
		Apartment(double price)
		{
			Rooms = vector<IRoom>();
			PricePerSqMeter = price;
		}
		void AddRoom(IRoom room)
		{
			Rooms.push_back(room);
		}
		void RemoveRoom(int index)
		{
			Rooms.erase(Rooms.begin() + index);
		}
		IRoom GetRoom(int index)
		{
			return Rooms[index];
		}
		double GetTotalArea()
		{
			double totalArea = 0;
			for (int i = 0; i < Rooms.size(); i++)
			{
				totalArea += Rooms[i].GetArea();
			}
			return totalArea;
		}
		double GetPrice()
		{
			return GetTotalArea() * PricePerSqMeter;
		}
		int GetNrOfRooms()
		{
			return Rooms.size();
		}
		string ToString()
		{
			string result = "\tNr of rooms: " + to_string(GetNrOfRooms()) + "\n";
			result += "\tTotal area: " + to_string(GetTotalArea()) + "\n";
			result += "\tPrice per sq meter: " + to_string(PricePerSqMeter) + "\n";
			result += "\tTotal price: " + to_string(GetPrice()) + "\n";
			return result;
		}
		
};

