/*********************************************************************
 * @file  Apllication.h
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier header de l'application
 *********************************************************************/

/*Declaration of 
	- 10 classes
	- their attributes
	- methods
	-relationsips */
	
#ifndef SMARTPARKING_H
#define SMARTPARKING_H

#include <iostream>
#include <string>


//abstract parent class
class HardwareComponent {
	protected:
			std::string name;
			
	public:
		HardwareComponent(std::string name);
		
		virtual void initialize ()=0; //every child class need their own version of this method
		virtual void update ()= 0;
		virtual ~HardwareComponent();
};


// we use override when the parent class has a virtual method
class DistanceSensor : public HardwareComponent{
	private: 
		double distance; //stores the last measured distance
	
	public:
	DistanceSensor(std::string name); //constructor
	
	void initialize() override;
	void update()override;
	double readDistance();
	~DistanceSensor() override;
	
};


class Buzzer : public HardwareComponent {
private:
    int beepInterval; // Time between two beeps, in milliseconds.
    bool isBeeping;   // Indicates whether the buzzer is active.

public:
    // Constructor
    Buzzer(std::string name);

    void initialize() override;
    void update() override;
    void startBeeping();
    void stopBeeping();    
    void setBeepInterval(double distance); // Changes the interval between beeps according to distance.
    ~Buzzer() override;
};


class LED : public HardwareComponent {
private:
    bool isOn; // true = ON, false = OFF

public:
    LED(std::string name);

    void initialize() override;
    void update() override;

    void setStatus(bool status);
    bool getStatus();

    ~LED() override;
};


class LCD : public HardwareComponent {
private:
    int batteryLevel; 

public:
    // Constructor
    LCD(std::string name);

    void initialize() override;
    void update() override;
    void displayBatteryLevel(int level);
    
    // Destructor
    ~LCD() override;
};

class RotaryEncoder : public HardwareComponent {
private:
    int rotation; // Stores the latest rotation direction.

public:
    // Constructor
    RotaryEncoder(std::string name);
    void initialize() override;
    void update() override;
    int readRotation();

    ~RotaryEncoder() override;
};

class Vehicle {
private:
    int batteryLevel; // Stores the battery percentage (0 to 100).

public:
    // Constructor
    Vehicle(int battery);

    // Returns the current battery percentage.
    int getBatteryLevel();

    // Changes the battery percentage.
    void setBatteryLevel(int battery);

    // Increases the battery percentage.
    void increaseBatteryLevel(int amount);

    ~Vehicle();
};


class ParkingSpace {
private:
    bool isOccupied; //true = occupied, false = free

public:    
    
    ParkingSpace();//constructor: the parking space starts free.
    void setStatus(bool occupied);   
    bool getStatus(); //returns true if occupied, false if free.

    ~ParkingSpace();
};


class ChargingStation {
	private:
    bool isCharging; //true = charging, false = not charging

public:
    
    ChargingStation();//charging is initially stopped.

  
    void setChargingStatus(bool charging);    
    void updateCharging(int rotation, Vehicle& vehicle); //updates the battery according to the encoder rotation.
    bool getChargingStatus();
    ~ChargingStation();
};

//coordinates all the components of the Smart Parking system
class ParkingManager {
private:
    // Hardware components
    DistanceSensor& sensor;
    Buzzer& buzzer;
    LED& led;
    LCD& lcd;
    RotaryEncoder& encoder;

    // Application components
    ParkingSpace& parkingSpace;
    Vehicle& vehicle;
    ChargingStation& chargingStation;

public:
    //constructor: receives all the components used by the system.
    ParkingManager(
        DistanceSensor& sensor,
        Buzzer& buzzer,
        LED& led,
        LCD& lcd,
        RotaryEncoder& encoder,
        ParkingSpace& parkingSpace,
        Vehicle& vehicle,
        ChargingStation& chargingStation
    );

    
    void initializeSystem();    
    void manageParking(); //main method that manages the parking cycle.    
    void manageApproach(); //manages the car approaching the parking space.
    void manageCharging();    
    void manageDeparture(); //manages the car leaving the parking space.
    ~ParkingManager();
};

#endif
