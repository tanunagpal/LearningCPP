/*Need for builder pattern
--complex product with extensive configuration
--multiple parameters in a constructor
--separate the construction and representation of an object
-- it is a creational type of design pattern
*/
//The following example focus on building different type of house eg wood, concrete etc

#include <iostream>
using namespace std;

class House{
    string _house;
    unsigned int _stories;
    string _door_type;
    string _roof_type;

    public:
    House(string houseType) : _house{houseType} {}
    void set_stories(unsigned int n) {_stories = n;}
    void set_door_type(string s) {_door_type = s;}
    void set_roof_type(string s) {_roof_type = s;}
    unsigned int get_stories() {return _stories;}
    string get_door_type() {return _door_type;}
    string get_roof_type(){return _roof_type;}

    void show()
    {
        cout<<"house type "<<_house<<endl;
        cout<<"storeies "<<_stories<<endl;
        cout<<"door_type "<<_door_type<<endl;
        cout<<"roof_type "<<_roof_type<<endl;
    }

};

//Abstract class: all builder must implement these methods
class HouseBuilder{
    protected:
    House *_house;
    public:
    virtual void get_house_type() = 0;
        virtual void get_stories() = 0;
        virtual void get_door_type() = 0;
        virtual void get_roof_type() = 0;
        House* getHouse(){return _house;}
};

class SingleStory : public HouseBuilder
{
    public:
    void get_house_type() {_house = new House("Single Story");}
    void get_stories() {_house->set_stories(1);}
    void get_door_type() {_house->set_door_type("single");}
    void get_roof_type() {_house->set_roof_type("pointy");}
};

class DoubleStory : public HouseBuilder
{
    void get_house_type() {_house = new House("Double Story");}
    void get_stories() {_house->set_stories(1);}
    void get_door_type() {_house->set_door_type("two");}
    void get_roof_type() {_house->set_roof_type("flat");}
};

class Director
{
    public:
    House* createHouse(HouseBuilder* builder)
    {
        builder->get_house_type();
        builder->get_stories();
        builder->get_door_type();
        builder->get_roof_type();
        return builder->getHouse();
    }
};

int main()
{
    Director dir;
    SingleStory ss;
    DoubleStory ts;

    House *s1 = dir.createHouse(&ss);
    House *s2 = dir.createHouse(&ts);
    
    s1->show();
    s2->show();

    delete s1;
    delete s2;

    return 0;
}
