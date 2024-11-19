#include "queue.h"

void Queue::dispatchPatient(const Patient &patient) {
    if (patient.getType() == "Urgent") {
        urgentQueue.push(patient);
        urgentCount++;
    } else {
        normalQueue.push(patient);
        normalCount++;
    }
    totalPatients++;
}

void Queue::servePatients(int n, QTextEdit *logTextEdit) {
    int servedCount = 0;

    // Serve patients from urgent queue first
    while (servedCount < n && !urgentQueue.empty()) {
        Patient patient = urgentQueue.top();
        urgentQueue.pop();

        // Log the served patient
        logTextEdit->append("Served Urgent Patient: " + QString::fromStdString(patient.getID()) +
                            " (" + QString(patient.getGender()) + ")");

        // Update total waiting time
        totalWaitingTime += Patient::timeToMinutes(patient.getArrivalTime());
        servedCount++;
    }

    // Serve remaining patients from normal queue
    while (servedCount < n && !normalQueue.empty()) {
        Patient patient = normalQueue.top();
        normalQueue.pop();

        // Log the served patient
        logTextEdit->append("Served Normal Patient: " + QString::fromStdString(patient.getID()) +
                            " (" + QString(patient.getGender()) + ")");

        // Update total waiting time
        totalWaitingTime += Patient::timeToMinutes(patient.getArrivalTime());
        servedCount++;
    }
}

void Queue::updateWaitingTimes(int minutes) {
    // Increment waiting time for all patients remaining in both queues
    totalWaitingTime += minutes * (urgentQueue.size() + normalQueue.size());
}

void Queue::displayQueues(QListWidget *listWidget, const std::string &queueType) {
    listWidget->clear();

    // Copy the priority queue to avoid modifying the original
    std::priority_queue<Patient, std::vector<Patient>, PatientComparator> tempQueue =
        (queueType == "Urgent") ? urgentQueue : normalQueue;

    // Display patients in the queue
    while (!tempQueue.empty()) {
        const Patient &patient = tempQueue.top();
        listWidget->addItem(QString::fromStdString(patient.getID()) + " (" + QString(patient.getGender()) + ")");
        tempQueue.pop();
    }
}

void Queue::displayStatistics(QListWidget *listWidget) {
    listWidget->clear();

    listWidget->addItem("Total Patients: " + QString::number(totalPatients));
    listWidget->addItem("Urgent Cases: " + QString::number(urgentCount));
    listWidget->addItem("Normal Cases: " + QString::number(normalCount));

    if (totalPatients > 0) {
        int averageWaitingTime = totalWaitingTime / totalPatients;
        listWidget->addItem("Average Waiting Time: " + QString::number(averageWaitingTime) + " minutes");
    } else {
        listWidget->addItem("Average Waiting Time: N/A");
    }
}
