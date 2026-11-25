/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
// methods and main

#include "SmartParking.h"


HardwareComponent::HardwareComponent(std::string name) { // Constructor of the abstract parent class.
    this->name = name;
}

HardwareComponent::~HardwareComponent() { // Destructor of the abstract parent class.
}

//functions
//ultrasound
DistanceSensor :: DistanceSensor(std::string name)
	: HardwareComponent(name), distance(50.0){    
		
}
void DistanceSensor::initialize() {
}

void DistanceSensor::update() {
}
	double DistanceSensor::readDistance(){
		return distance; 
		
	}
DistanceSensor::~DistanceSensor() {
}
	
	

//buzzer
Buzzer :: Buzzer(std::string name)
	:HardwareComponent(name), beepInterval(0), isBeeping(false){
		
}
void Buzzer::initialize() {
}

void Buzzer::update() {
}

void Buzzer::startBeeping(){
	isBeeping = true; 
}
void Buzzer::stopBeeping(){
	isBeeping = false;
	beepInterval = 0;
}
void Buzzer::setBeepInterval(double distance){
	beepInterval = distance * 10;
}
Buzzer::~Buzzer() {
}


//LED
LED :: LED (std::string name)
	: HardwareComponent(name), isOn(true) {
}

void LED::initialize() {
}

void LED::update() {
}
void LED:: setStatus(bool status){
	isOn = status;
}
bool LED::getStatus(){
	return isOn;
}
LED::~LED() {
}


//LCD
LCD :: LCD (std:: string name)
	: HardwareComponent(name), batteryLevel(0) {
	}
void LCD::initialize() {
}

void LCD::update() {
}

	
void LCD::displayBatteryLevel(int level){
	batteryLevel = level; 
}

LCD::~LCD() {
}

//rotatory encoder
RotaryEncoder :: RotaryEncoder(std::string name)
	:HardwareComponent(name),  rotation(0){
	}
void RotaryEncoder::initialize() {
}

void RotaryEncoder::update() {
}
int RotaryEncoder::readRotation(){
	return rotation; 
}

RotaryEncoder::~RotaryEncoder() {
}

//vehicle
Vehicle :: Vehicle(int battery)
		:batteryLevel(battery){
	}
	
int Vehicle::getBatteryLevel(){
	return batteryLevel;
}

void Vehicle :: setBatteryLevel (int battery){
	batteryLevel = battery;
}

void Vehicle::increaseBatteryLevel (int amount){
	batteryLevel += amount;
}
Vehicle::~Vehicle() {
}


//parking space
ParkingSpace :: ParkingSpace()
			:isOccupied (false){
}
void ParkingSpace :: setStatus (bool occupied){
	isOccupied = occupied;
}
bool ParkingSpace :: getStatus (){
	return isOccupied;
}
ParkingSpace::~ParkingSpace() {
}

//charging station
ChargingStation :: ChargingStation ()
	:isCharging(false){
}
	
void ChargingStation::setChargingStatus(bool charging){
		isCharging = charging;
}

void ChargingStation::updateCharging(int rotation, Vehicle& vehicle){
	if (rotation > 0 && isCharging) {
        vehicle.increaseBatteryLevel(rotation);

        if (vehicle.getBatteryLevel() >= 100) {
            vehicle.setBatteryLevel(100);
            setChargingStatus(false);
        }
    }
}
bool ChargingStation::getChargingStatus(){
	return isCharging;
}
ChargingStation::~ChargingStation() {
}


//Parking manager
ParkingManager::ParkingManager(
    DistanceSensor& sensor,
    Buzzer& buzzer,
    LED& led,
    LCD& lcd,
    RotaryEncoder& encoder,
    ParkingSpace& parkingSpace,
    Vehicle& vehicle,
    ChargingStation& chargingStation
)
    : sensor(sensor),
      buzzer(buzzer),
      led(led),
      lcd(lcd),
      encoder(encoder),
      parkingSpace(parkingSpace),
      vehicle(vehicle),
      chargingStation(chargingStation) {
}
void ParkingManager::manageParking(){
}	
void ParkingManager::manageApproach(){
}	
void ParkingManager::manageCharging(){
}
void ParkingManager::manageDeparture(){
	
}
ParkingManager::~ParkingManager() {
}

