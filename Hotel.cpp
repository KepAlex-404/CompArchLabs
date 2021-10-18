// Hotel.cpp
#include <iostream>
#include <utility>
#include "Hotel.h"
using namespace std;
Hotel::Hotel()
{
    id_hotel = 0;
    fInDb = true;
    stars = 1;
}
Hotel::~Hotel()
{
}

bool Hotel::getPoolStatus()
{
    slippers = (stars > 4);

    return slippers;
}

bool Hotel::getBreakfastStatus()
{
    return breakfast;
}

string Hotel::getContact()
{
    return name_contact;
}
void Hotel::setContact(string newContact)
{
    name_contact = newContact;
}

std::string Hotel::getNameHotel() {
    return name_hotel;
}
void Hotel::setNameHotel(string new_name)
{
    name_hotel = new_name;
}

string Hotel::getNameCountry()
{
    return name_country;
}
void Hotel::setNameCountry(string newCountry)
{
    name_country = newCountry;
}

string Hotel::getNameCity()
{
    return name_city;
}
void Hotel::setNameCity(string newCity)
{
    name_city = newCity;
}

string Hotel::getAddress()
{
    return address;
}
void Hotel::setAddress(string newAddress)
{
    address = newAddress;
}


void Hotel::setIdHotel(int new_id){
    id_hotel = new_id;
}



int Hotel::getStars()
{
    return stars;
}

void Hotel::setStars(int newStars)
{
    if ( newStars > 0 & newStars < 6){
        stars = newStars;
    }
    else{
        cout << "Wrong Stars Number";
    }
}


bool Hotel::getSlippers()
{
    slippers = (stars != 1);

    return slippers;
}


void Hotel::remove()
{
    fInDb = false;
}

bool Hotel::getStatus()
{
    return fInDb;
}

int Hotel::getIdHotel() const {
    return id_hotel;
}
