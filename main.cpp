#include <iostream>
using namespace std;

class Car{
  private:
    int model;
    string brand;
    double price;
    int year;
    double finalPrice;
    string fuelType;
  public:
    Car(){
      model = 0;
      brand = "";
      price = 0.0;
      year = 0;
      finalPrice = 0.0;
      string fuelType = "";
    }
    void setModel(int model){this->model = model;}
    int getModel(){return model;}

    void setYear(int year){this->year = year;}
    int getYear(){return year;}
    
    void setBrand(string brand){this->brand = brand;}
    string getBrand(){return brand;}
    
    void setFuelType(string fuelType){this->fuelType = fuelType;}
    string getFuelType(){return fuelType;}
    
    void setPrice(double price){this->price = price;}
    double getPrice(){return price;}
    
    void setFinalPrice(double finalPrice){this->finalPrice = finalPrice;}
    double getFinalPrice(){return finalPrice;}
};

class BMW: protected Car{
  private:
    bool passengerAirBag;
    bool alloyWheels;
    int numberOfAIModule;
    int gearCount;
  public:
    BMW(int model,string brand,double price,int year,double finalPrice,string fuelType){
      this->passengerAirBag = false;
      this->alloyWheels = false;
      this->numberOfAIModule = 0;
      this->gearCount = 0;
      setModel(model);
      setBrand(brand);
      setPrice(price);
      setYear(year);
      setFinalPrice(finalPrice);
      setFuelType(fuelType);
    }

    void setPassengerAirBag(bool passengerAirBag){this->passengerAirBag=passengerAirBag;}
    bool getPassengerAirBag(){return passengerAirBag;}

    void setAlloyWheels(bool alloyWheels){this->alloyWheels=alloyWheels;}
    bool getAlloyWheels(){return alloyWheels;}

    void setNumberOfAIModules(int numberOfAIModules){this->numberOfAIModule = numberOfAIModules;}
    int getNumberOfAIModules(){return numberOfAIModule;}
    
    void shiftGear(){
      gearCount+=1;
    }
};

int main() {
  cout << "Hello World!\n";
}