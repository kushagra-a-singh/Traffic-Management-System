// ----- Smart Traffic Management System -----
// Managing the record of Vehicles
// Managing the record of Challans
// Search the record of Vehicles
// Display information of Traffic in Control Booths
// Helpline Information and nearby Hospitals

// MADE BY: -
// BTECH, SY, SEM-3, PANEL-B(2023)
// Kushagra Singh (PRN- 1032220949, Rollnum- 23)
// Swamil Randive (PRN- 1032220375, Rollnum- 06)
// Ansh Tandale (PRN- 1032220887, Rollnum- 19)
// Kartik Maski (PRN- 1032220414, Rollnum- 08)
// Araham Sayeed (PRN- 1032220940, Rollnum- 22)

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

class TrafficManagementSystem
{
public:
    int welcome()
    {
        system("cls");
        time_t tt;
        struct tm *ti;
        time(&tt);
        ti = localtime(&tt);
        cout << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << " " << asctime(ti);
        delay_1();
        system("cls");

        cout << "---------------------------------------------\n";
        cout << "HEARTY WELCOME TO TRAFFIC MANAGEMENT SYSTEM\n";
        cout << "---------------------------------------------\n\n";
        cout << "Enter your desired option:\n";
        cout << "1. Get Record of Vehicles\n";
        cout << "2. Get Record of Challans\n";
        cout << "3. Search Record of Vehicles\n";
        cout << "4. Search Traffic Control Booths\n";
        cout << "5. Emergency Contacts and Hospital Locations\n";
        cout << "6. Exit\n";
        cout << "Please enter your desired choice-> ";

        int ch{0};
        cin >> ch;
        if (ch > 0 && ch < 7)
        {
            switch (ch)
            {
            case 1:
                system("cls");
                recordOfVehicle();
                break;
            case 2:
                system("cls");
                recordOfChallan();
                break;
            case 3:
                system("cls");
                vehSearch();
                break;
            case 4:
                system("cls");
                trafContBooth();
                break;
            case 5:
                system("cls");
                helpInfo();
                break;
            case 6:
                cout << "Exiting..." << endl;
                exit(0);
                break;
            }
        }
        else
        {
            cout << "Please enter a valid option!!" << endl;
            delay_0();
            system("cls");
            welcome();
        }
        return 0;
    }

    int delay_0()
    {
        #ifdef _WIN32
            Sleep(2000); // 3 seconds on Windows
        #else
            usleep(2000000); // 3 seconds on Linux
        #endif
        return 0;
    }

    int delay_1()
    {
        #ifdef _WIN32
            Sleep(2000); // 2 seconds on Windows
        #else
            usleep(2000000); // 2 seconds on Linux
        #endif
        return 0;
    }

    int delay_2()
    {
        #ifdef _WIN32
            Sleep(200); // 0.2 seconds on Windows
        #else
            usleep(200000);  // 0.2 seconds on Linux
        #endif
        return 0;
    }

    int recordOfVehicle()
    {
        cout << "---------------------------------------------\n";
        cout << "HEARTY WELCOME TO TRAFFIC MANAGEMENT SYSTEM\n";
        cout << "---------------------------------------------\n\n";
        cout << "**** Record of Vehicles ****\n\n";
        cout << "Select your desired option:\n";
        cout << "1. Add a New Vehicle Record\n";
        cout << "2. Search for a Vehicle Using its Registration Number\n";
        cout << "3. Search for a Vehicle through the Owner's Name\n";
        cout << "4. Delete a Vehicle Record\n\n";
        cout << "Press 0 to go back to the Home Screen.\n";
        cout << "Please enter your desired choice: ";

        int RegofChoice{0};
        cin >> RegofChoice;
        switch (RegofChoice)
        {
        case 0:
            system("cls");
            welcome();
            break;
        case 1:
            recordOfVehicle_1();
            break;
        case 2:
            recordOfVehicle_2();
            break;
        case 3:
            recordOfVehicle_3();
            break;
        case 4:
            deleteRecordOfVehicle();
            break;
        }
        return 0;
    }

    int recordOfVehicle_1()
    {
        system("cls");
        fstream fio;
        string text;
        cout << "Welcome to the Vehicle Registration Portal\n\n";
        cout << "***ENTER BELOW FIELDS WITHOUT SPACES IN BETWEEN***\n\n";
        cout << "Enter Vehicle's Registration Number: ";
        cin.ignore();
        getline(cin, text);
        fio.open("C:/Users/Kushagra/Desktop/MIT WPU/STUDY MATERIALS/SY/SEM-3/DT/Lab Notes & Assignments/TMS/RecordOfTheVehicles.txt", ios::app | ios::out | ios::in);
        fio << text << endl;
        cout << "Enter Owner's Name: ";
        getline(cin, text);
        fio << text << endl;
        fio.close();

        cout << "Your data has been entered successfully!!" << endl;
        delay_0();
        system("cls");
        return recordOfVehicle();
    }

    int recordOfVehicle_2()
    {
        system("cls");
        string path = "C:\\Users\\Kushagra\\Desktop\\MIT WPU\\STUDY MATERIALS\\SY\\SEM-3\\DT\\Lab Notes & Assignments\\TMS\\RecordOfTheVehicles.txt";
        ifstream file(path.c_str());
        if (file.is_open())
        {
            cout << " Welcome to the Registration Portal\n";
            cout << endl
                 << "Please enter the Registration Number of the Vehicle that you are searching for: ";
            string text;
            cin.ignore();
            cin >> text;
            int count = 0;
            string registrationNumber, ownerName;

            while (file >> registrationNumber >> ownerName)
            {
                if (text == registrationNumber)
                {
                    ++count;
                    cout << "Registration Number: " << registrationNumber << endl;
                    cout << "Owner's Name: " << ownerName << endl;
                }
            }

            if (count > 0)
            {
                int choice;
                cout << endl
                     << "Press 1 to go back to the Home Screen OR Press 2 if you want to enter the Registration Number again: ";
                cin >> choice;
                if (choice == 1)
                    recordOfVehicle();
                else if (choice == 2)
                    return recordOfVehicle_2();
            }
            else
            {
                cout << "Sorry!! Registration Number is not found!!";
                int choice;
                cout << endl
                     << "Press 1 to go back to the Home Screen OR Press 2 if you want to enter the Registration Number again: ";
                cin >> choice;
                if (choice == 1)
                    recordOfVehicle();
                else if (choice == 2)
                    return recordOfVehicle_2();
            }
        }
        else
        {
            cerr << "Error!! 401!\n";
            delay_0();
            welcome();
        }
        return 0;
    }

    int recordOfVehicle_3()
    {
        system("cls");
        string path = "C:\\Users\\Kushagra\\Desktop\\MIT WPU\\STUDY MATERIALS\\SY\\SEM-3\\DT\\Lab Notes & Assignments\\TMS\\RecordOfTheVehicles.txt";
        ifstream file(path.c_str());
        if (file.is_open())
        {
            cout << " Welcome to the Registration Portal\n";
            cout << endl
                 << "Please enter the Owner's Name of the Vehicle that you are searching for: ";
            string text;
            cin.ignore();
            cin >> text;
            int count = 0;
            string registrationNumber, ownerName;

            while (file >> registrationNumber >> ownerName)
            {
                if (text == ownerName)
                {
                    ++count;
                    cout << "Registration Number: " << registrationNumber << endl;
                    cout << "Owner's Name: " << ownerName << endl;
                }
            }

            if (count > 0)
            {
                int choice;
                cout << endl
                     << "Press 1 to go back to the Home Screen OR Press 2 if you want to enter the Owner's Name again: ";
                cin >> choice;
                if (choice == 1)
                    recordOfVehicle();
                else if (choice == 2)
                    return recordOfVehicle_3();
            }
            else
            {
                cout << "Owner's Name not found!!";
                int choice;
                cout << endl
                     << "Press 1 to go back to the Home Screen OR Press 2 if you want to enter the Owner's Name again: ";
                cin >> choice;
                if (choice == 1)
                    recordOfVehicle();
                else if (choice == 2)
                    return recordOfVehicle_3();
            }
        }
        else
        {
            cerr << "Error!! 401!\n";
            delay_0();
            welcome();
        }
        return 0;
    }

    int deleteRecordOfVehicle()
    {

        string path = "C:\\Users\\Kushagra\\Desktop\\MIT WPU\\STUDY MATERIALS\\SY\\SEM-3\\DT\\Lab Notes & Assignments\\TMS\\RecordOfTheVehicles.txt";

        cout << "Enter the Registration Number of the Vehicle to delete: ";
        string registrationNumber;
        cin >> registrationNumber;

        ifstream inFile(path.c_str());
        if (!inFile.is_open())
        {
            cerr << "Error opening the file." << endl;
            delay_0();
            system("cls");
            return recordOfVehicle();
        }

        vector<string> lines;
        string line;
        bool found = false;

        while (getline(inFile, line))
        {
            if (line.find(registrationNumber) == string::npos)
            {
                lines.push_back(line);
            }
            else
            {
                found = true;
            }
        }

        inFile.close();

        if (!found)
        {
            cout << "Vehicle record not found." << endl;
            delay_0();
            system("cls");
            return recordOfVehicle();
        }

        ofstream outFile(path.c_str(), ios::trunc);
        if (!outFile.is_open())
        {
            cerr << "Error opening the file." << endl;
            delay_0();
            system("cls");
            return recordOfVehicle();
        }

        for (const string &str : lines)
        {
            outFile << str << endl;
        }

        outFile.close();

        cout << "Vehicle record with Registration Number '" << registrationNumber << "' has been deleted." << endl;
        delay_0();
        system("cls");
        return recordOfVehicle();
    }

    int recordOfChallan()
    {
        cout << "---------------------------------------------\n";
        cout << "WELCOME TO TRAFFIC MANAGEMENT SYSTEM\n";
        cout << "**** ----Record of Challan---- ****\n";
        cout << "---------------------------------------------\n\n";
        cout << "Enter your desired option:\n\n";
        cout << "1. Add a New Challan Record\n";
        cout << "2. Search for Challan Using Registration Number\n";
        cout << "3. Search for Challan Using Owner's Name\n";
        cout << "4. Delete a Challan Record\n\n";
        cout << "Press 0 to go back to the Home Screen.\n";
        cout << "Enter your desired choice: ";

        int ROCChoice{0};
        cin >> ROCChoice;
        switch (ROCChoice)
        {
        case 0:
            system("cls");
            welcome();
            break;
        case 1:
            recordOfChallan_1();
            break;
        case 2:
            recordOfChallan_2();
            break;
        case 3:
            recordOfChallan_3();
            break;
        case 4:
            deleteRecordOfChallan();
            break;
        default:
            cout << "Please enter a Valid Case!" << endl;
        }
        return 0;
    }

    int recordOfChallan_1()
    {
        system("cls");
        fstream fio;
        string text;
        cout << "Welcome to the Challan Management Portal\n\n";
        cout << "***ENTER BELOW FIELDS WITHOUT SPACES IN BETWEEN***\n\n";
        cout << "Enter Vehicle's Registration Number: ";
        cin.ignore();
        getline(cin, text);
        fio.open("C:\\Users\\Kushagra\\Desktop\\MIT WPU\\STUDY MATERIALS\\SY\\SEM-3\\DT\\TMS\\RecordOfTheChallan.txt", ios::app | ios::out | ios::in);

        fio << text << endl;

        cout << "Enter Owner's Name: ";
        getline(cin, text);
        fio << text << endl;

        cout << "Enter Reason for Challan: ";
        getline(cin, text);
        fio << text << endl;

        cout << "Enter Challan Price: ";
        getline(cin, text);
        fio << text << endl;
        fio.close();

        cout << "Your data has been entered successfully!!" << endl;
        delay_0();
        system("cls");
        return recordOfChallan();
    }

    int recordOfChallan_2()
    {
        system("cls");
        string path = "C:\\Users\\Kushagra\\Desktop\\MIT WPU\\STUDY MATERIALS\\SY\\SEM-3\\DT\\Lab Notes & Assignments\\TMS\\RecordOfTheChallan.txt";
        ifstream file(path.c_str());
        if (file.is_open())
        {
            cout << " Welcome to Challan Management System\n"
                 << endl;
            cout << "Enter the Registration Number of the Vehicle that you are searching for: ";
            string text;
            cin.ignore();
            cin >> text;
            int count = 0;
            string registrationNumber, ownerName, reason, price;

            while (file >> registrationNumber >> ownerName >> reason >> price)
            {
                if (text == registrationNumber)
                {
                    ++count;
                    cout << "Registration Number: " << registrationNumber << endl;
                    cout << "Owner's Name: " << ownerName << endl;
                    cout << "Reason for Challan: " << reason << endl;
                    cout << "Challan Price: " << price << endl;
                }
            }

            if (count > 0)
            {
                int choice;
                cout << endl
                     << "Press 1 to go back to the Home Screen OR Press 2 if you want to enter the Registration Number again: ";
                cin >> choice;
                if (choice == 1)
                    recordOfChallan();
                else if (choice == 2)
                    return recordOfChallan_2();
            }
            else
            {
                cout << "Sorry!! Registration Number is not found!!";
                int choice;
                cout << endl
                     << "Press 1 to go back to the Home Screen OR Press 2 if you want to enter the Registration Number again: ";
                cin >> choice;
                if (choice == 1)
                    recordOfChallan();
                else if (choice == 2)
                    return recordOfChallan_2();
            }
        }
        else
        {
            cerr << "Error!! 402!" << endl;
            delay_0();
            welcome();
        }
        return 0;
    }

    int recordOfChallan_3()
    {
        system("cls");
        string path = "C:\\Users\\Kushagra\\Desktop\\MIT WPU\\STUDY MATERIALS\\SY\\SEM-3\\DT\\Lab Notes & Assignments\\TMS\\RecordOfTheChallan.txt";
        ifstream file(path.c_str());
        if (file.is_open())
        {
            cout << " Welcome to the Challan Management Portal\n"
                 << endl;
            cout << "Enter the Vehicle Owner's Name that you are searching for: ";
            string text;
            cin.ignore();
            cin >> text;
            int count = 0;
            string registrationNumber, ownerName, reason;
            float price;

            while (file >> registrationNumber >> ownerName >> reason >> price)
            {
                if (text == ownerName)
                {
                    ++count;
                    cout << "Registration Number: " << registrationNumber << endl;
                    cout << "Owner's Name: " << ownerName << endl;
                    cout << "Reason for Challan: " << reason << endl;
                    cout << "Price to be Paid: " << price << endl;
                }
            }

            if (count > 0)
            {
                int choice;
                cout << endl
                     << "Press 1 to go back to the Home Screen OR Press 2 if you want to enter the Owner's Name again: ";
                cin >> choice;
                if (choice == 1)
                    recordOfChallan();
                else if (choice == 2)
                    return recordOfChallan_3();
            }
            else
            {
                cout << "Owner's Name not found!!";
                int choice;
                cout << endl
                     << "Press 1 to go back to the Home Screen OR Press 2 if you want to enter the Owner's Name again: ";
                cin >> choice;
                if (choice == 1)
                    recordOfChallan();
                else if (choice == 2)
                    return recordOfChallan_3();
            }
        }
        else
        {
            cerr << "Error!! 402!\n";
            delay_0();
            welcome();
        }
        return 0;
    }

    int deleteRecordOfChallan()
    {
        string path = "C:\\Users\\Kushagra\\Desktop\\MIT WPU\\STUDY MATERIALS\\SY\\SEM-3\\DT\\Lab Notes & Assignments\\TMS\\RecordOfTheChallan.txt";

        cout << "Enter the Registration Number of the Vehicle for which you want to delete the Challan: ";
        string registrationNumber;
        cin >> registrationNumber;

        ifstream inFile(path.c_str());
        if (!inFile.is_open())
        {
            cerr << "Error opening the file." << endl;
            delay_0();
            system("cls");
            return recordOfChallan();
        }

        vector<string> lines;
        string line;
        bool found = false;

        while (getline(inFile, line))
        {
            if (line.find(registrationNumber) == string::npos)
            {
                lines.push_back(line);
            }
            else
            {
                found = true;
            }
        }

        inFile.close();

        if (!found)
        {
            cout << "Challan record not found." << endl;
            delay_0();
            system("cls");
            return recordOfChallan();
        }

        ofstream outFile(path.c_str(), ios::trunc);
        if (!outFile.is_open())
        {
            cerr << "Error opening the file." << endl;
            delay_0();
            system("cls");
            return recordOfChallan();
        }

        for (const string &str : lines)
        {
            outFile << str << endl;
        }

        outFile.close();

        cout << "Challan record for Vehicle with Registration Number '" << registrationNumber << "' has been deleted." << endl;
        delay_0();
        system("cls");
        return recordOfChallan();
    }

    int vehSearch()
    {
        cout << "---------------------------------------------\n";
        cout << "WELCOME TO TRAFFIC MANAGEMENT SYSTEM\n";
        cout << "**** ----Search for the Record of Vehicles---- ****\n";
        cout << "---------------------------------------------\n\n";

        string path = "C:\\Users\\Kushagra\\Desktop\\MIT WPU\\STUDY MATERIALS\\SY\\SEM-3\\DT\\Lab Notes & Assignments\\TMS\\RecordOfTheVehicles.txt";
        ifstream file(path.c_str());

        if (file.is_open())
        {
            string word;
            cin.ignore();
            cout << "Enter the Vehicle's Registration Number: ";
            getline(cin, word);

            int countwords = 0;
            string candidate;

            while (getline(file, candidate))
            {
                if (word == candidate)
                {
                    ++countwords;
                    break;
                }
            }

            file.close();

            if (countwords > 0)
            {
                cout << "The entered Registration Number '" << word << "' has been found successfully in our records." << endl;
                int choice;
                cout << "\nPress 1 to go back to the Home Screen OR Press 2 if you want to enter the Registration Number again: ";
                cin >> choice;

                if (choice == 1)
                {
                    system("cls");
                    welcome();
                }
                else if (choice == 2)
                {
                    return vehSearch();
                }
            }
            else
            {
                cout << "Sorry!! Registration Number is not found!!" << endl;
                int choice;
                cout << "\nPress 1 to go back to the Home Screen OR Press 2 if you want to enter the Registration Number again: ";
                cin >> choice;

                if (choice == 1)
                {
                    system("cls");
                    welcome();
                }
                else if (choice == 2)
                {
                    return vehSearch();
                }
            }
        }
        return 0;
    }

    int trafContBooth()
    {
        cout << "---------------------------------------------\n";
        cout << "WELCOME TO TRAFFIC MANAGEMENT SYSTEM\n";
        cout << "**** ----Traffic Control Booths---- ****\n";
        cout << "---------------------------------------------\n\n";
        cout << "Enter your desired option:\n\n";
        cout << "1. Indore Traffic Control Booth\n";
        cout << "2. Bhopal Traffic Control Booth\n";
        cout << "3. Nagpur Traffic Control Booth\n\n";
        cout << "Press 0 to go back to the Home Screen.\n";
        cout << "Enter your desired choice-> ";

        int TrafficCBChoice{0};
        cin >> TrafficCBChoice;
        switch (TrafficCBChoice)
        {
        case 0:
            system("cls");
            welcome();
            break;
        case 1:
            trafficContBooth_1();
            break;
        case 2:
            trafficContBooth_2();
            break;
        case 3:
            trafficContBooth_3();
            break;
        }
        return 0;
    }

    int trafficContBooth_1()
    {
        system("cls");
        for (int i = 0; i < 100; ++i)
        {
            int exitingCount = i + (rand() % 10);
            int enteringCount = i * 7 + (rand() % 10);

            cout << " Indore Traffic Control Booth " << endl;
            cout << "===========================================" << endl;
            cout << " Vehicles Exiting the City: " << exitingCount << endl;
            cout << " Vehicles Entering the City: " << enteringCount << endl;
            cout << "===========================================" << endl;
            cout << "\nPress 0 to go back to the Traffic Control Booth Menu: ";

            int choice;
            cin >> choice;
            if (choice == 0)
                return trafContBooth();

            delay_0();
            system("cls");
        }
        return 0;
    }

    int trafficContBooth_2()
    {
        system("cls");
        for (int i = 0; i < 100; ++i)
        {
            int exitingCount = i + (rand() % 10);
            int enteringCount = i * 7 + (rand() % 10);

            cout << " Bhopal Traffic Control Booth " << endl;
            cout << "===========================================" << endl;
            cout << " Vehicles Exiting the City: " << exitingCount << endl;
            cout << " Vehicles Entering the City: " << enteringCount << endl;
            cout << "===========================================" << endl;
            cout << "\nPress 0 to go back to the Traffic Control Booth Menu: ";

            int choice;
            cin >> choice;
            if (choice == 0)
                return trafContBooth();

            delay_0();
            system("cls");
        }
        return 0;
    }

    int trafficContBooth_3()
    {
        system("cls");
        for (int i = 0; i < 100; ++i)
        {
            int exitingCount = i + (rand() % 10);
            int enteringCount = i * 7 + (rand() % 10);

            cout << " Nagpur Traffic Control Booth " << endl;
            cout << "===========================================" << endl;
            cout << " Vehicles Exiting the City: " << exitingCount << endl;
            cout << " Vehicles Entering the City: " << enteringCount << endl;
            cout << "===========================================" << endl;
            cout << "\nPress 0 to go back to the Traffic Control Booth Menu: ";

            int choice;
            cin >> choice;
            if (choice == 0)
                return trafContBooth();

            delay_0();
            system("cls");
        }
        return 0;
    }

    int helpInfo()
    {
        cout << "---------------------------------------------\n";
        cout << "WELCOME TO TRAFFIC MANAGEMENT SYSTEM\n";
        cout << "**** ----Helpline Info and Nearby Healthcare Centers---- ****\n";
        cout << "---------------------------------------------\n\n";
        cout << "Enter your desired option:\n\n";
        cout << "1. Get the Helpline Number\n";
        cout << "2. Get info on Hospitals in Bhopal\n";
        cout << "3. Get info on Hospitals in Nagpur\n\n";
        cout << "Press 0 to go back to the Home Screen.\n";
        cout << "Enter your desired choice: ";

        int CChoice{0};
        cin >> CChoice;
        switch (CChoice)
        {
        case 0:
            system("cls");
            welcome();
            break;
        case 1:
        {
            system("cls");
            string para;
            ifstream myfile("C:\\Users\\Kushagra\\Desktop\\MIT WPU\\STUDY MATERIALS\\SY\\SEM-3\\DT\\Lab Notes & Assignments\\TMS\\HelplineNumbers.txt");
            if (myfile.is_open())
            {
                while (getline(myfile, para))
                {
                    cout << para << '\n';
                }
                myfile.close();
            }
            else
                cout << "Error!! 403!";
            int ch;
            cout << endl
                 << "Press 1 if you want to go back to the Home Page:" << endl;
            cin >> ch;
            if (ch == 1)
            {
                system("cls");
                helpInfo();
            }
            else
            {
                cout << endl
                     << "Please Enter a Valid option!!";
                cout << endl
                     << endl
                     << "Press 1 if you want to go back to the Home Page:" << endl;
                cin >> ch;
                if (ch == 1)
                {
                    system("cls");
                    helpInfo();
                }
            }
            return 0;
        }

        case 2:
        {
            system("cls");
            string line;
            ifstream myfile("C:\\Users\\Kushagra\\Desktop\\MIT WPU\\STUDY MATERIALS\\SY\\SEM-3\\DT\\Lab Notes & Assignments\\TMS\\HBhopal.txt");
            if (myfile.is_open())
            {
                while (getline(myfile, line))
                {
                    cout << line << '\n';
                }
                myfile.close();
            }
            else
                cout << "Error!! 403!";
            int ch;
            cout << endl
                 << "Press 1 if you want to go back to the Home Page:" << endl;
            cin >> ch;
            if (ch == 1)
            {
                system("cls");
                helpInfo();
            }
            else
            {
                cout << endl
                     << "Please Enter a Valid option!!";
                cout << endl
                     << endl
                     << "Press 1 if you want to go back to the Home Page:" << endl;
                cin >> ch;
                if (ch == 1)
                {
                    system("cls");
                    helpInfo();
                }
            }
            return 0;
        }

        break;

        case 3:
        {
            system("cls");
            string line;
            ifstream myfile("C:\\Users\\Kushagra\\Desktop\\MIT WPU\\STUDY MATERIALS\\SY\\SEM-3\\DT\\Lab Notes & Assignments\\TMS\\HNagpur.txt");
            if (myfile.is_open())
            {
                while (getline(myfile, line))
                {
                    cout << line << '\n';
                }
                myfile.close();
            }
            else
                cout << "Error!! 403!";
            int ch;
            cout << endl
                 << "Press 1 if you want to go back to the Home Page:" << endl;
            cin >> ch;
            if (ch == 1)
            {
                system("cls");
                helpInfo();
            }
            else
            {
                cout << endl
                     << "Please Enter a Valid option!!";
                cout << endl
                     << endl
                     << "Press 1 if you want to go back to the Home Page:" << endl;
                cin >> ch;
                if (ch == 1)
                {
                    system("cls");
                    helpInfo();
                }
            }
            return 0;
        }
        }
    }
};

int main()
{
    TrafficManagementSystem ob1;
    ob1.welcome();
}