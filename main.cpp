#include <iostream>
#include <fstream>
using namespace std;

class Car{
  private:
    string model;
    string brand;
    double price;
    int year;
    double finalPrice;
    string fuelType;
  public:
    Car(){
      model = "";
      brand = "";
      price = 0.0;
      year = 0;
      finalPrice = 0.0;
      string fuelType = "";
    }
    void setModel(string model){this->model = model;}
    string getModel(){return model;}

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

class BMW: public Car{
  private:
    bool passengerAirBag;
    bool alloyWheels;
    int numberOfAIModule;
    int gearCount;
  public:
    BMW(string model,double price,int year,double finalPrice,string fuelType){
      this->passengerAirBag = false;
      this->alloyWheels = false;
      this->numberOfAIModule = 0;
      this->gearCount = 0;
      setModel(model);
      setBrand("BMW");
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
    
    void shiftGear(){gearCount+=1;}
    int getGearShift(){return gearCount;}
};

double calcFinalPrice(double tax, double price){
	return (tax + price);
}

int main() {
  fstream myfile;
  myfile.open ("11145.txt",ios::app);
  string model,fuelType;
  int year;
  double price,tax;
  cout << "Enter Model Name: ";
  cin >> model;
  cout << "Enter Fuel Type: ";
  cin >> fuelType;
  cout << "Enter Year: ";
  cin >> year;
  cout << "Enter Car Price: ";
  cin >> price;
  tx:
  cout << "Enter Car Tax: ";
  cin >> tax;
  if(tax < 25000) goto tx;
  BMW car(model,price,year,calcFinalPrice(tax,price),fuelType);
  cout << "Does the car have Air Bag for Passenger? ";
  bool airbag;
  cin >> airbag;
  if(airbag) car.setPassengerAirBag(airbag);
  cout << "Does the car have Alloy Wheels? ";
  bool alloy;
  if(alloy) car.setAlloyWheels(alloy);
  cout << "How many AI Module does the car have? ";
  int aim;
  if(aim > 0) car.setNumberOfAIModules(aim);
  cout << endl << "Shift Gear more than 3 times to save it to file";
  int counter = 0;
  do{
  	if(counter < 3){
  		cout << endl << "Press any key to shift up!";
  		system("pause");
  		car.shiftGear();
  		counter+=1;
	}else{
		break;
	}
  }while(true);
  myfile << "Model of the car is : " << car.getModel() << endl;
  myfile << "Model of the car is : " << car.getModel() << endl;
  myfile << "Model of the car is : " << car.getModel() << endl;
  myfile << "Model of the car is : " << car.getModel() << endl;
  myfile << "Model of the car is : " << car.getModel() << endl;
  myfile << endl;
  myfile << "Passenger Air Bags Included : " << car.getModel() << endl;
  myfile << "Alloy Wheels Included : " << car.getModel() << endl;
  myfile << "Number of AI Modules : " << car.getModel() << endl;
  myfile << "How Many time was the gear shifted : " << car.getModel() << endl;
  myfile.close();
}
