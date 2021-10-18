// Hotel.h
#include <string>
class Hotel
{
public:
    Hotel();
    ~Hotel();

    bool getPoolStatus();

    bool getBreakfastStatus();

    std::string getContact();
    void setContact(std::string newContact);

    std::string getNameHotel();
    void setNameHotel(std::string NameHotel);

    std::string getNameCountry();
    void setNameCountry(std::string NameCountry);

    std::string getNameCity();
    void setNameCity(std::string NameCity);

    std::string getAddress();
    void setAddress(std::string Address);


    void remove();

    int getStars();
    void setStars(int stars);

    bool getSlippers();

    int getIdHotel() const;
    void setIdHotel(int id_hotel);

    bool getStatus();

private:
    bool have_pool{};
    bool breakfast{};
    bool slippers{};

    std::string name_contact;
    std::string name_hotel;
    std::string name_country;
    std::string name_city;
    std::string address;

    int stars;
    int id_hotel;


    bool fInDb;

};