# cslabcs
# cslabcs  Bashar and Aly Salem

//Patient Class
The Patient class represents a patient with information such as ID, gender, arrival time, and the type of visit (Urgent or Normal).
Key Features:
1.    Constructor:
o    The constructor takes four parameters: ID, gender, arrival time, and visit type. It validates these inputs when the object is created, and throws an error if any of the values are invalid.
2.    Getter Methods:
o    getID(): Returns the patient's ID.
o    getGender(): Returns the patient's gender.
o    getArrivalTime(): Returns the arrival time.
o    getType(): Returns the type of visit (Urgent or Normal).
3.    Validation Methods:
o    isValidID(): Checks if the ID is 14 characters long (for Egyptian IDs).
o    isValidTime(): Ensures the time format is valid (e.g., "HH
").
o    isValidType(): Validates the type of visit, ensuring it is either "Urgent" or "Normal".
4.    Time Conversion:
o    timeToMinutes(): Converts the arrival time (in "HH
" format) into the total minutes for easier comparison.


//patient.cpp - Patient Class Implementation
This file contains the implementation of the Patient class. The class represents a patient with information such as ID, gender, arrival time, and type of care. Here's what each part of the code does:
1.    Constructor:
o    The constructor initializes a patient's details (ID, gender, arrival time, and type). It also validates these inputs:
    ID: Must be 14 characters long.
    Arrival Time: Must follow the format "HH
".
    Type: Can either be "Urgent" or "Normal". If any of these are invalid, an exception is thrown.
2.    Getter Methods:
o    getID(): Returns the patient's ID.
o    getGender(): Returns the patient's gender.
o    getArrivalTime(): Returns the patient's arrival time.
o    getType(): Returns the patient's care type.
3.    Validation Methods:
o    isValidID(): Checks if the ID is 14 characters long.
o    isValidTime(): Validates if the time is in the correct "HH
" format.
o    isValidType(): Ensures that the care type is either "Urgent" or "Normal".
4.    Time Conversion:
o    timeToMinutes(): Converts the arrival time (in "HH
" format) to total minutes for easier comparison.


//queue.h - Queue Class Header
This file defines the Queue class, which manages two patient queues: one for urgent patients and one for normal patients. It handles dispatching, serving, and displaying information about patients. Here's an overview of its components:
1.    Private Members:
o    PatientComparator: A helper struct used to compare patients based on their arrival time (earlier arrival time gets higher priority). It is used to order patients in the priority queue.
o    urgentQueue: A priority queue that holds urgent patients, sorted by arrival time.
o    normalQueue: A priority queue for normal patients, also sorted by arrival time.
o    Statistics:
    totalPatients: Total number of patients processed.
    urgentCount: Number of urgent patients.
    normalCount: Number of normal patients.
    totalWaitingTime: Sum of the waiting time for all patients.
2.    Public Methods:
o    dispatchPatient(): Adds a patient to the appropriate queue (urgent or normal) based on their type.
o    servePatients(): Serves (removes) a certain number of patients from the queue and logs the details in a QTextEdit widget.
o    updateWaitingTimes(): Updates the waiting time for patients in the queues as time passes.
o    displayQueues(): Displays the current state of the queues (urgent or normal) in a QListWidget.
o    displayStatistics(): Displays statistics (such as the number of patients and total waiting time) in a QListWidget.


//queue.cpp - Queue Class Implementation
This file implements the functions of the Queue class, which manages the dispatch and serving of patients in two separate queues: urgent and normal. Here's what each function does:
1.    dispatchPatient():
o    Adds a patient to either the urgent or normal queue based on their type.
o    Increments counters for total, urgent, and normal patients.
2.    servePatients():
o    Serves a specified number of patients (n), prioritizing urgent patients first.
o    Logs the details of each served patient (ID and gender) in a QTextEdit widget.
o    Updates the total waiting time based on the patient's arrival time.
3.    updateWaitingTimes():
o    Increases the total waiting time for all patients in both queues as time passes (the minutes argument is multiplied by the number of patients).
4.    displayQueues():
o    Displays the patients in either the urgent or normal queue in a QListWidget.
o    Creates a temporary copy of the queue to avoid altering the original while displaying it.
5.    displayStatistics():
o    Displays the total number of patients, counts of urgent and normal cases, and the average waiting time (if available) in a QListWidget.

