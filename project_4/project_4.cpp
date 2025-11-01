#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Struct to represent a patient
struct Patient {
    string id;
    int severity;
    int arrivalTime;
    int treatedTime; // Time when the patient gets treated
};

// Custom comparator for priority queue
struct ComparePatients {
    bool operator()(const Patient& a, const Patient& b) const {
        if (a.severity == b.severity)
            return a.arrivalTime > b.arrivalTime; // Earlier arrival gets higher priority
        return a.severity < b.severity; // Higher severity gets higher priority
    }
};

int main() {
    ifstream inFile("hospitalData.txt");
    ofstream outFile("results.csv");
    string line, substring;
    stringstream ss;

    priority_queue<Patient, vector<Patient>, ComparePatients> pq;

    vector<Patient> treatedPatients;

    int currentTime = 0;
    int doctorFreeAt = 0;

    vector<Patient> allPatients;

    // Read and store all patients
    while (getline(inFile, line)) {
        ss.str(line);
        Patient p;
        getline(ss, p.id, ' ');
        getline(ss, substring, ' ');
        p.severity = stoi(substring);
        getline(ss, substring, ' ');
        p.arrivalTime = stoi(substring);
        allPatients.push_back(p);
        ss.clear();
    }

    size_t i = 0;
    while (i < allPatients.size() || !pq.empty()) {
        // Add all patients who arrive at this current time
        while (i < allPatients.size() && allPatients[i].arrivalTime <= currentTime) {
            pq.push(allPatients[i]);
            i++;
        }

        if (currentTime >= doctorFreeAt && !pq.empty()) {
            Patient next = pq.top();
            pq.pop();
            next.treatedTime = currentTime;
            treatedPatients.push_back(next);
            doctorFreeAt = currentTime + 5;
        }

        currentTime++;
    }

    inFile.close();

    // Write to results.csv
    outFile << "Severity,WaitTime" << endl;
    for (auto& p : treatedPatients) {
        int waitTime = p.treatedTime - p.arrivalTime;
        outFile << p.severity << "," << waitTime << endl;
    }
    outFile.close();

    // Calculate average wait time per severity level
    vector<int> totalWaitTime(11, 0);
    vector<int> count(11, 0);

    for (auto& p : treatedPatients) {
        int waitTime = p.treatedTime - p.arrivalTime;
        totalWaitTime[p.severity] += waitTime;
        count[p.severity]++;
    }

    ofstream summary("results.txt");
    summary << fixed << setprecision(2);
    for (int s = 1; s <= 10; ++s) {
        double avg = (count[s] == 0) ? 0.0 : (double)totalWaitTime[s] / count[s];
        summary << "Severity " << s << ": Average Wait Time = " << avg << " minutes" << endl;
    }
    summary.close();

    return 0;
}
