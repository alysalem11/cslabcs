// patient.cpp

#include "patient.h"
#include <sstream>
#include <stdexcept> // For exception handling

// Constructor
Patient::Patient(const std::string &id, char gender, const std::string &arrivalTime, const std::string &type)
    : id(id), gender(gender), arrivalTime(arrivalTime), type(type) {

    // Validate input values
    if (!isValidID(id)) throw std::invalid_argument("Invalid ID");
    if (!isValidTime(arrivalTime)) throw std::invalid_argument("Invalid Time");
    if (!isValidType(type)) throw std::invalid_argument("Invalid Type");
}

// Getter methods
std::string Patient::getID() const {
    return id;
}

char Patient::getGender() const {
    return gender;
}

std::string Patient::getArrivalTime() const {
    return arrivalTime;
}

std::string Patient::getType() const {
    return type;
}

// Validation methods
bool Patient::isValidID(const std::string &id) {
    return id.length() == 14; // Check for valid length (Egyptian ID length)
}

bool Patient::isValidTime(const std::string &time) {
    // Simplified validation: "HH:MM"
    return time.length() == 5 && time[2] == ':' && std::isdigit(time[0]) && std::isdigit(time[1])
           && std::isdigit(time[3]) && std::isdigit(time[4]);
}

bool Patient::isValidType(const std::string &type) {
    return type == "Urgent" || type == "Normal";
}

// Convert arrival time to minutes for comparison
int Patient::timeToMinutes(const std::string &time) {
    std::stringstream ss(time);
    int hours, minutes;
    char colon;
    ss >> hours >> colon >> minutes;
    return hours * 60 + minutes;
}
