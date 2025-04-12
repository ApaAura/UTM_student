#pragma once
#include <string>

using namespace std;

enum RoomType 
{ 
	Kitchen, 
	LivingRoom, 
	Bedroom, 
	Bathroom, 
	Garage, 
	Garden, 
	Other 
};

class IRoom
{
	private:
		string RoomName;
		int NrOfDors;
		int NrOfWindows;
		int NrOfWalls;
		double Area;
		RoomType Type;
	public:
		IRoom(string roomName, int nrOfDors, int nrOfWindows, int nrOfWalls, double area ,RoomType type)
		{
			RoomName = roomName;
			NrOfDors = nrOfDors;
			NrOfWindows = nrOfWindows;
			NrOfWalls = nrOfWalls;
			Area = area;
			Type = type;
		}
		//getters
		string GetRoomName() { return RoomName; }
		int GetNrOfDors() { return NrOfDors; }
		int GetNrOfWindows() { return NrOfWindows; }
		int GetNrOfWalls() { return NrOfWalls; }
		RoomType GetType() { return Type; }
		double GetArea() { return Area; }
		//setters
		void SetRoomName(string roomName) { RoomName = roomName; }
		void SetNrOfDors(int nrOfDors) { NrOfDors = nrOfDors; }
		void SetNrOfWindows(int nrOfWindows) { NrOfWindows = nrOfWindows; }
		void SetNrOfWalls(int nrOfWalls) { NrOfWalls = nrOfWalls; }
		void SetType(RoomType type) { Type = type; }
		void SetArea(double area) { Area = area; }
		string ToString()
		{
			string result = "Room name: " + RoomName + "\n";
			//area
			result += "Area: " + to_string(Area) + "\n";
			//room type
			result += "Room type: ";
			switch (Type)
			{
			case Kitchen:
				result += "Kitchen";
				break;
			case LivingRoom:
				result += "Living room";
				break;
			case Bedroom:
				result += "Bedroom";
				break;
			case Bathroom:
				result += "Bathroom";
				break;
			case Garage:
				result += "Garage";
				break;
			case Garden:
				result += "Garden";
				break;
			case Other:
				result += "Other";
				break;
			default:
				break;
			}
			result += "\n";
			return result;
		}
};


