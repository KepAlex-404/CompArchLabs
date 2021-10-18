//// AirlineTicketTest.cpp
//#include <iostream>
//#include "Hotel.h"
//using namespace std;
//int main(int argc, char** argv)
//{
//    Hotel myHotel; // stack-based
//
//    myHotel.setIdHotel(555);
//    myHotel.setStars(5);
//    myHotel.setNameHotel("Haromy");
//    myHotel.setNameCountry("USA");
//    myHotel.setAddress("Kansas, Krasnodonskaya st. 20");
//    myHotel.setNameCity("Kansas-city");
//    myHotel.setContact("Sam");
//
//    bool a_slippers = myHotel.getSlippers();
//    bool a_pool = myHotel.getPoolStatus();
//
//    cout << "Hotel name - " << myHotel.getNameHotel() << endl;
//    cout << "Availability of slippers in Haromy- " << a_slippers << endl;
//    cout << "Availability of pool in Haromy- " << a_pool << endl;
//
//    cout << "---------------------------------------------" << endl;
//
//
//    Hotel* myHotel2; // heap-based
//    myHotel2 = new Hotel(); // allocate a new object
//    myHotel2->setIdHotel(666);
//    myHotel2->setStars(1);
//    myHotel2->setNameHotel("Klopovnik");
//    myHotel2->setNameCountry("UK");
//    myHotel2->setNameCity("London");
//
//    bool a_slippers_kl = myHotel2->getSlippers();
//    bool a_breakfast_kl = myHotel2->getBreakfastStatus();
//
//    cout << "Hotel name - " << myHotel2->getNameHotel() << endl;
//    cout << "Availability of slippers in Klopovnik - " << a_slippers_kl << endl;
//    cout << "Availability of breakfast in Klopovnik - " << a_breakfast_kl << endl;
//
//    delete myHotel2;
//    return 0;
//}

#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"
using namespace std;
using namespace Records;
int displayMenu();
void doAddHotel(Database& inDB);
void doFire(Database& inDB);
void doPromote(Database& inDB);

int main(int argc, char** argv)
{
    Database hotelDB;
    bool done = false;
    while (!done) {
        int selection = displayMenu();
        switch (selection) {
            case 1:
                doAddHotel(hotelDB);
                break;
            case 2:
                doFire(hotelDB);
                break;
            case 3:
                doPromote(hotelDB);
                break;
            case 4:
                hotelDB.displayAll();
                break;
            case 0:
                done = true;
                break;
            default:
                cerr << "Unknown command." << endl;
        }
    }
}
int displayMenu()
{
    int selection;
    cout << endl;
    cout << "hotel Database" << endl;
    cout << "-----------------" << endl;
    cout << "1) Hire a new hotel" << endl;
    cout << "2) Fire an hotel" << endl;
    cout << "3) Promote an hotel" << endl;
    cout << "4) List all hotels" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "---> ";
    cin >> selection;
    return selection;
}
void doAddHotel(Database& inDB)
{
    string NameHotel;
    string NameCity;
    cout << "NameHotel? ";
    cin >> NameHotel;
    cout << "NameCity? ";
    cin >> NameCity;
    try {
        inDB.addHotel(NameHotel, NameCity);
    } catch (std::exception ex) {
        cerr << "Unable to add new hotel!" << endl;
    }
}
void doFire(Database& inDB)
{
    int hotelId;
    cout << "hotel id? ";
    cin >> hotelId;
    try {
        Hotel& hotel = inDB.getHotel(hotelId);
        hotel.remove();
        cout << "hotel " << hotelId << " has been terminated." << endl;
    } catch (std::exception ex) {
        cerr << "Unable to terminate hotel!" << endl;
    }
}
void doPromote(Database& inDB) {
    int hotelId;
    int raiseAmount;
    cout << "hotel number? ";
    cin >> hotelId;
    cout << "How much of a raise? ";
    cin >> raiseAmount;
    try {
        Hotel &hotel = inDB.getHotel(hotelId);
        hotel.setStars(raiseAmount);
    } catch (...) {
        cerr << "Unable to promote hotel!" << endl;
    }
}