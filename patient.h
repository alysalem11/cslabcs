// patient.h

#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <stdexcept> // For exception handling

class Patient {
private:
    std::string id;
    char gender;
    std::string arrivalTime;
    std::string type;

public:
    // Constructor
    Patient(const std::string &id, char gender, const std::string &arrivalTime, const std::string &type);

    // Getters
    std::string getID() const;
    char getGender() const;
    std::string getArrivalTime() const;
    std::string getType() const;

    // Static Validation Methods
    static bool isValidID(const std::string &id);
    static bool isValidTime(const std::string &time);
    static bool isValidType(const std::string &type);

    // Convert time to minutes for comparison
    static int timeToMinutes(const std::string &time);
};

#endif // PATIENT_H
