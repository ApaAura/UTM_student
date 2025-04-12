#pragma once
#include "IRoom.h"
#include "Apartment.h"
#include "Store.h"

using namespace std;

enum BuildingType {
	CivilBuilding,
	IndustrialBuilding,
	AgroBuilding
};

class Building
{
	private:
		BuildingType Type;
		string Name;
		string Address;
		vector<Apartment> Apartments;
		vector<IRoom> Rooms;
		vector<Store> Stores;
	public:
		Building(BuildingType type, string name, string address)
		{
			Type = type;
			Name = name;
			Address = address;
			Rooms = vector<IRoom>();
			Stores = vector<Store>();
			Apartments = vector<Apartment>();
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
		void AddStore(Store store)
		{
			Stores.push_back(store);
		}
		void RemoveStore(int index)
		{
			Stores.erase(Stores.begin() + index);
		}
		Store GetStore(int index)
		{
			return Stores[index];
		}
		void AddApartment(Apartment apartment)
		{
			Apartments.push_back(apartment);
		}
		void RemoveApartment(int index)
		{
			Apartments.erase(Apartments.begin() + index);
		}
		Apartment GetApartment(int index)
		{
			return Apartments[index];
		}
		int GetNrOfApartments()
		{
			return Apartments.size();
		}
		int GetNrOfStores()
		{
			return Stores.size();
		}
		int GetNrOfRooms()
		{
			return Rooms.size();
		}
		string ToString()
		{
			string res = "";
			res += "Building type: ";
			switch (Type)
			{
			case CivilBuilding:
				res += "Civil";
				break;
			case IndustrialBuilding:
				res += "Industrial";
				break;
			case AgroBuilding:
				res += "Agro";
				break;
			default:
				break;
			}
			res += "\nBuilding name: " + Name + "\n";
			res += "Building address: " + Address + "\n";
			res += "Number of stores: " + to_string(Stores.size()) + "\n";
			res += "Number of apartments: " + to_string(GetNrOfApartments()) + "\n";
			return res;
		}
};

