#pragma once

class Store
{
	private:
		string StoreName;
		double Price;
		vector<IRoom> Rooms;
	public:
		Store(string name)
		{
			StoreName = name;
			Rooms = vector<IRoom>();
		}
		void SetPrice(double price)
		{
			Price = price;
		}
		double GetPrice()
		{
			return Price;
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
		string ToString()
		{
			string result = "\tName: " + StoreName + "\n";
			result += "\tPrice: " + to_string(Price) + "\n";
			result += "\tNr of rooms: " + to_string(Rooms.size()) + "\n";
			return result;
		}
};

