#include <iostream>
#include "Hotel.h"
namespace Records {
    const int kMaxHotels = 100;
    const int kFirstHotelNumber = 1000;
    class Database
    {
    public:
        Database();
        ~Database();
        Hotel& addHotel(std::string NameHotel, std::string NameCity);
        Hotel& getHotel(int inHotelNumber);
        void displayAll();
    protected:
        Hotel mHotels[kMaxHotels];
        int mNextSlot;
        int mNextHotelNumber;
    };
}