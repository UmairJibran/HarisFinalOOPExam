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

void write(BMW car){
  fstream myfile;
  myfile.open ("11145.txt",ios::app);
  myfile << "Model of the car is : " << car.getModel() << endl;
  myfile << "Brand of the car is : " << car.getBrand() << endl;
  myfile << "Price of the car is : " << car.getPrice() << endl;
  myfile << "Built Year of the car is : " << car.getYear() << endl;
  myfile << "Final Price of the car is : " << car.getFinalPrice() << endl;
  myfile << endl;
  myfile << "Passenger Air Bags Included : " << car.getPassengerAirBag() << endl;
  myfile << "Alloy Wheels Included : " << car.getAlloyWheels() << endl;
  myfile << "Number of AI Modules : " << car.getNumberOfAIModules() << endl;
  myfile << "How Many time was the gear shifted : " << car.getGearShift() << endl;
  myfile.close();
}

int main() {
	cout << "press 1 to write another car. or 2 to read old: ";
	int temp;
	cin >> temp;
	if(temp == 1){	
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
	  int temp;
	  cout << "Does the car have Air Bag for Passenger? ";
	  cin >> temp;
	  if(temp == 1) car.setPassengerAirBag(true);
	  cout << "Does the car have Alloy Wheels? ";
	  cin >> temp;
	  if(temp == 1) car.setAlloyWheels(true);
	  cout << "How many AI Module does the car have? ";
	  int aim;
	  cin >> aim;
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
			int temp;
			cout << "Press 1 for another shift or 0 for no shift";
			cin >> temp;
			if(temp == 1) car.shiftGear();
			else break;
		}
	  }while(true);
	  write(car);
	}else{
	  string line;
	  fstream myfile;
	  myfile.open ("11145.txt");
	  while ( getline (myfile,line) )    {
	      cout << line << '\n';
	  }
	  myfile.close();
	}
}
