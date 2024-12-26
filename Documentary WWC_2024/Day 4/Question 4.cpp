
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>

struct Patient {
    std::string name;
    int triagePriority; 
    int severity;       
    std::chrono::time_point<std::chrono::system_clock> arrivalTime; 

 
    Patient(std::string n, int tp, int s)
        : name(n), triagePriority(tp), severity(s), arrivalTime(std::chrono::system_clock::now()) {}
};

bool comparePatients(const Patient &a, const Patient &b) {

    if (a.triagePriority != b.triagePriority) {
        return a.triagePriority < b.triagePriority; 
    }
  
    if (a.severity != b.severity) {
        return a.severity < b.severity; 
    }

    return a.arrivalTime < b.arrivalTime; 
}

void printPatients(const std::vector<Patient> &patients) {
    std::cout << "Patients in order of priority:\n";
    for (const auto &patient : patients) {
        std::cout << "Name: " << patient.name 
                  << ", Triage Priority: " << patient.triagePriority 
                  << ", Severity: " << patient.severity << "\n";
    }
}

int main() {
    std::vector<Patient> patients;

   
    patients.emplace_back("Aman", 2, 3); // Triage priority 2, severity 3
    patients.emplace_back("Ben", 1, 1);   // Triage priority 1, severity 1
    patients.emplace_back("Chahat", 2, 2); // Triage priority 2, severity 2
    patients.emplace_back("Dev", 3, 4); // Triage priority 3, severity 4

    std::sort(patients.begin(), patients.end(), comparePatients);

    printPatients(patients);

    std::cout << "\nNew patient arrives:\n";
    patients.emplace_back("Enna", 1, 2); // New patient with high priority
    std::sort(patients.begin(), patients.end(), comparePatients); 

   
    printPatients(patients);

    return 0;
}
