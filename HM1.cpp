#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
#include<vector>
using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void loading() {
    cout << "Loading";
    for(int i = 0; i < 5; i++) {
        cout << ".";
        Sleep(300);
    }
    cout << "\n";
}

void welcomeBanner() {
    setColor(11);
    cout << "===============================\n";
    cout << "   HOSPITAL MANAGEMENT SYSTEM\n";
    cout << "===============================\n";
    setColor(7);
    loading();
}

void addPatient() {
    string name, disease;
    int age;
    cout << "\nEnter Patient Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Disease: ";
    cin.ignore();
    getline(cin, disease);

    ofstream file("patients.txt", ios::app);
    file << name << "," << age << "," << disease << "\n";
    file.close();
    cout << "Patient record added!\n";
}

void viewPatients() {
    ifstream file("patients.txt");
    string line;
    cout << "\n-- Patient Records --\n";
    while(getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void addDoctor() {
    string name, spec;
    cout << "\nEnter Doctor Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Specialization: ";
    getline(cin, spec);

    ofstream file("doctors.txt", ios::app);
    file << name << "," << spec << "\n";
    file.close();
    cout << "Doctor record added!\n";
}

void viewDoctors() {
    ifstream file("doctors.txt");
    string line;
    cout << "\n-- Doctor List --\n";
    while(getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void bookAppointment() {
    string pname, dname, date;
    cout << "\nEnter Patient Name: ";
    cin.ignore();
    getline(cin, pname);
    cout << "Enter Doctor Name: ";
    getline(cin, dname);
    cout << "Enter Date (dd-mm-yyyy): ";
    getline(cin, date);

    ofstream file("appointments.txt", ios::app);
    file << pname << " with Dr. " << dname << " on " << date << "\n";
    file.close();
    cout << "Appointment booked!\n";
}

void generateBill() {
    string name;
    int consult = 500, tests = 1000;
    cout << "\nEnter Patient Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "\n--- Bill for " << name << " ---\n";
    cout << "Consultation: ₹" << consult << endl;
    cout << "Tests: ₹" << tests << endl;
    cout << "Total: ₹" << consult + tests << "\n";
}

void healthQuiz() {
    char ans;
    int score = 0;
    cout << "\nWelcome to the Health Quiz!\n";
    cout << "Q1. How many hours of sleep is ideal?\n";
    cout << "a) 4-5  b) 6-8  c) 10-12\nYour answer: ";
    cin >> ans;
    if(ans == 'b') score++;

    cout << "Q2. Which fruit is richest in Vitamin C?\n";
    cout << "a) Banana  b) Apple  c) Orange\nYour answer: ";
    cin >> ans;
    if(ans == 'c') score++;

    cout << "Your Score: " << score << "/2\n";
}

void allocateRoom() {
    int roomNo;
    string type, patient;
    cout << "\nEnter Room Number: ";
    cin >> roomNo;
    cin.ignore();
    cout << "Enter Room Type (General/Private/ICU): ";
    getline(cin, type);
    cout << "Assign to Patient Name: ";
    getline(cin, patient);

    ofstream file("rooms.txt", ios::app);
    file << roomNo << "," << type << ",Occupied," << patient << "\n";
    file.close();
    cout << "Room allocated successfully!\n";
}

void viewRooms() {
    ifstream file("rooms.txt");
    string line;
    cout << "\n-- Room Status --\n";
    while(getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void addMedicalRecord() {
    string name, diagnosis, treatment, report;
    cout << "\nEnter Patient Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Diagnosis: ";
    getline(cin, diagnosis);
    cout << "Enter Treatment: ";
    getline(cin, treatment);
    cout << "Enter Lab Report Summary: ";
    getline(cin, report);

    ofstream file("medical_records.txt", ios::app);
    file << name << "," << diagnosis << "," << treatment << "," << report << "\n";
    file.close();
    cout << "Medical record added.\n";
}

void viewMedicalRecords() {
    ifstream file("medical_records.txt");
    string line;
    cout << "\n-- Medical Records --\n";
    while(getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void manageInventory() {
    string item;
    int qty;
    cout << "\nEnter Item Name: ";
    cin.ignore();
    getline(cin, item);
    cout << "Enter Quantity: ";
    cin >> qty;

    ofstream file("inventory.txt", ios::app);
    file << item << "," << qty << "\n";
    file.close();
    cout << "Inventory updated.\n";
}

void viewInventory() {
    ifstream file("inventory.txt");
    string line;
    cout << "\n-- Inventory List --\n";
    while(getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void managePharmacy() {
    string med, batch;
    int qty;
    cout << "\nEnter Medicine Name: ";
    cin.ignore();
    getline(cin, med);
    cout << "Enter Batch No: ";
    getline(cin, batch);
    cout << "Enter Quantity: ";
    cin >> qty;

    ofstream file("pharmacy.txt", ios::app);
    file << med << "," << batch << "," << qty << "\n";
    file.close();
    cout << "Pharmacy stock updated.\n";
}

void viewPharmacy() {
    ifstream file("pharmacy.txt");
    string line;
    cout << "\n-- Pharmacy Records --\n";
    while(getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void manageLabTests() {
    string name, test, result;
    cout << "\nEnter Patient Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Test Scheduled: ";
    getline(cin, test);
    cout << "Enter Result: ";
    getline(cin, result);

    ofstream file("lab_tests.txt", ios::app);
    file << name << "," << test << "," << result << "\n";
    file.close();
    cout << "Lab test recorded.\n";
}

void viewLabTests() {
    ifstream file("lab_tests.txt");
    string line;
    cout << "\n-- Lab Test Results --\n";
    while(getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void adminDashboard() {
    int patientCount = 0, doctorCount = 0, appointmentCount = 0;
    string line;
    ifstream p("patients.txt"); while(getline(p, line)) patientCount++; p.close();
    ifstream d("doctors.txt"); while(getline(d, line)) doctorCount++; d.close();
    ifstream a("appointments.txt"); while(getline(a, line)) appointmentCount++; a.close();

    cout << "\n-- Admin Dashboard --\n";
    cout << "Total Patients: " << patientCount << endl;
    cout << "Total Doctors: " << doctorCount << endl;
    cout << "Total Appointments: " << appointmentCount << endl;
}

void mainMenu() {
    int choice;
    do {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Add Patient\n2. View Patients\n3. Add Doctor\n4. View Doctors\n";
        cout << "5. Book Appointment\n6. Generate Bill\n7. Take Health Quiz\n";
        cout << "8. View Rooms\n9. Allocate Room\n10. Add Medical Record\n";
        cout << "11. View Medical Records\n12. Manage Inventory\n13. View Inventory\n";
        cout << "14. Manage Pharmacy\n15. View Pharmacy\n16. Manage Lab Tests\n17. View Lab Tests\n";
        cout << "18. Admin Dashboard\n19. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: addDoctor(); break;
            case 4: viewDoctors(); break;
            case 5: bookAppointment(); break;
            case 6: generateBill(); break;
            case 7: healthQuiz(); break;
            case 8: viewRooms(); break;
            case 9: allocateRoom(); break;
            case 10: addMedicalRecord(); break;
            case 11: viewMedicalRecords(); break;
            case 12: manageInventory(); break;
            case 13: viewInventory(); break;
            case 14: managePharmacy(); break;
            case 15: viewPharmacy(); break;
            case 16: manageLabTests(); break;
            case 17: viewLabTests(); break;
            case 18: adminDashboard(); break;
            case 19: cout << "Thank you! Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 19);
}

int main() {
    welcomeBanner();
    mainMenu();
    return 0;
}