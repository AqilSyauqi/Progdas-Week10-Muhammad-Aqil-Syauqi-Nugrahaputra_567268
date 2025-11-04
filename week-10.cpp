#include <iostream>
using namespace std;

struct studentType { // structure declaration
    string studentFname;
    string studentLname;
    double testScore;
    char grade;
};

void studentinfo (studentType& rep) { // function to input student information
    cout << " input student first name : ";
    cin >> rep.studentFname;
    cout << " enter student last name : ";
    cin >> rep.studentLname;
    cout << " input test score : ";
    cin >> rep.testScore;
};

void assigngrade(studentType& rep) { // function to assign grade based on test score
    if (rep.testScore >= 90)
        rep.grade = 'A';
    else if (rep.testScore >= 70)
        rep.grade = 'B';
    else if (rep.testScore >= 50)
        rep.grade = 'C';
    else if (rep.testScore >= 30)
        rep.grade = 'D';
    else
        rep.grade = 'F';
};

void displayreport (const studentType& rep) { // function to display student report
    cout << " student name : " << rep.studentLname << ", " << rep.studentFname <<endl;
    cout << " test score : " << rep.testScore <<endl;
    cout << " Grade : " << rep.grade <<endl;
    cout << "---------------------------" << endl;
    };

int main() {
    int n;
    studentType classreport [20]; // array of structure to hold up to 20 students
    cout << " input how much student : ";
    cin >> n;

    for (int i = 0; i < n; i++) { // loop to input data for each student
        cout << "\n=== Input data student #" << i + 1 << " ===" << endl;
        studentinfo(classreport[i]);
        assigngrade(classreport[i]);
    }

    cout << "\n=== Class Report ===" << endl;
    for (int i = 0; i < n; i++) { // loop to display report for each student
        displayreport(classreport[i]);
    }

    double highest = classreport[0].testScore; // find the highest test score
    for (int i = 1; i < n; i++) {
        if (classreport[i].testScore > highest) {
            highest = classreport[i].testScore;
             cout << "\n===the highest score of the class is===" << endl;
            displayreport(classreport[i]);
        }
    }
        
    return 0;
}