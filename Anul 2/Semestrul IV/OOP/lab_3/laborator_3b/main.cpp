#include <iostream>
#include "Building.h"

int main()
{
	Building building = Building(BuildingType::CivilBuilding, "Bloc locativ", "Chisinau, Decebal 19");
	//Apartments
	for (size_t i = 0; i < 5; i++)
	{//generam 10 apartamente cu pretul 1199
		Apartment ap(1199);
		IRoom dormitor1 = IRoom("dormitor1",2,1,4,25,Bedroom);
		ap.AddRoom(dormitor1);
		IRoom dormitor2 = IRoom("dormitor2", 2, 1, 4, 30, Bedroom);
		ap.AddRoom(dormitor2);
		IRoom living = IRoom("living", 2, 1, 4, 25, LivingRoom);
		ap.AddRoom(living);
		IRoom bucatarie = IRoom("bucatarie", 2, 1, 4, 25, Kitchen);
		ap.AddRoom(bucatarie);
		IRoom baie = IRoom("baie", 2, 1, 4, 25, Bathroom);
		ap.AddRoom(baie);
		building.AddApartment(ap);
	}
	//end Apartments
	//magazin
	Store store = Store("Magazin");
	store.SetPrice(790);
	IRoom magazin = IRoom("magazin", 2, 1, 4, 25, Other);
	store.AddRoom(magazin);
	IRoom depozit = IRoom("depozit", 2, 1, 4, 50, Other);
	store.AddRoom(depozit);
	IRoom birou = IRoom("birou", 2, 1, 4, 25, Other);
	store.AddRoom(birou);
	IRoom wc = IRoom("wc", 2, 1, 4, 25, Bathroom);
	store.AddRoom(wc);
	//end magazin
	building.AddStore(store);
	//Building Rooms
	IRoom DepozitBloc = IRoom("Depozit bloc", 2, 1, 4, 100, Other);
	building.AddRoom(DepozitBloc);
	IRoom BirouBloc = IRoom("Birou bloc", 2, 1, 4, 25, Other);
	building.AddRoom(BirouBloc);
	IRoom CameraTehnica = IRoom("Camera tehnica", 2, 1, 4, 25, Other);
	building.AddRoom(CameraTehnica);
	//end Building Rooms
	//Building Info
	cout << "=================\n";
	cout << building.ToString();
	cout << "-----------------\n";
	//print the price of every apartment with the nr of rooms
	for (size_t i = 0; i < building.GetNrOfApartments(); i++)
	{
		Apartment ap = building.GetApartment(i);
		cout << "Apartment " << i + 1 <<endl;
		cout << ap.ToString();
	}
	//print info of stores from building
	cout << "-----------------\n";
	cout << "\tStores:\n";
	cout << "-----------------\n";
	for (size_t i = 0; i < building.GetNrOfStores(); i++)
	{
		Store store = building.GetStore(i);
		cout << "\tStore " << i + 1 << endl;
		cout << store.ToString();
	}
	//print info of technical rooms from building
	cout << "-----------------\n";
	cout << "Technical Rooms:\n";
	cout << "-----------------\n";
	for (size_t i = 0; i < building.GetNrOfRooms(); i++)
	{
		IRoom room = building.GetRoom(i);
		cout << "\tRoom " << i + 1 << endl;
		cout << room.ToString();
	}
}