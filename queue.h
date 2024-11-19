// queue.h

#ifndef QUEUE_H
#define QUEUE_H

#include "patient.h"
#include <queue>
#include <vector>
#include <QString>
#include <QListWidget>
#include <QTextEdit>

class Queue {
private:
    struct PatientComparator {
        bool operator()(const Patient &a, const Patient &b) const {
            return Patient::timeToMinutes(a.getArrivalTime()) > Patient::timeToMinutes(b.getArrivalTime());
        }
    };

    std::priority_queue<Patient, std::vector<Patient>, PatientComparator> urgentQueue;
    std::priority_queue<Patient, std::vector<Patient>, PatientComparator> normalQueue;

    int totalPatients = 0;
    int urgentCount = 0;
    int normalCount = 0;
    int totalWaitingTime = 0;

public:
    void dispatchPatient(const Patient &patient);
    void servePatients(int n, QTextEdit *logTextEdit);
    void updateWaitingTimes(int minutes);
    void displayQueues(QListWidget *listWidget, const std::string &queueType);
    void displayStatistics(QListWidget *listWidget);
};

#endif // QUEUE_H
