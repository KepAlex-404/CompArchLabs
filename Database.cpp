#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"
using namespace std;
namespace Records {
    Database::Database()
    {
        mNextSlot = 0;
        mNextHotelNumber = kFirstHotelNumber;
    }
    Database::~Database()
    {
    }
    Hotel& Database::addHotel(string NameHotel, string NameCity)
    {
        if (mNextSlot >= kMaxHotels) {
            cerr << "There is no more room to add the new Hotel!" << endl;
            throw exception();
        }
        Hotel& theHotel = mHotels[mNextSlot++];
        theHotel.setNameHotel(NameHotel);
        theHotel.setIdHotel(mNextHotelNumber++);
        theHotel.setNameCity(NameCity);
        return theHotel;
    }
    Hotel& Database::getHotel(int IdHotel)
    {
        for (int i = 0; i < mNextSlot; i++) {
            if (mHotels[i].getIdHotel() == IdHotel) {
                return mHotels[i];
            }
        }
        cerr << "No Hotel with Hotel number " << IdHotel << endl;
        throw exception();
    }

    void Database::displayAll()
    {
        for (int i = 0; i < mNextSlot; i++) {
            cout << mHotels[i].getIdHotel() << ' ' << mHotels[i].getNameHotel() << ' ' << mHotels[i].getStars()
            << " Status - " <<mHotels[i].getStatus() << endl;
        }
    }

}