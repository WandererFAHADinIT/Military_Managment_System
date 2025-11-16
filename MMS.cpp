#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string toLower(string s);
void title();
void BranchSelection(int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch, int n);
void BranchSelection2(int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch, int n);
void ActionsMenu(int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch, int n);
void addInitialSoldiers(int nofSoldiers, int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch);
void ArmySoldierDatabase(int totalSoldiers, int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch);
void AirForceSoldierDatabase(int totalSoldiers, int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch);
void NavySoldierDatabase(int totalSoldiers, int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch);
void addSoldier(int &totalSoldiers, int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch);
void ArmyRanks();
void AirForceRanks();
void NavyRanks();
void preaddedSoldiers(int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch);
void deleteSoldierArmy(int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch);
void deleteSoldierAirForce(int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch);
void deleteSoldierNavy(int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch);
void searchSoldier(int totalSoldiers, int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch);
void updateSoldier(int totalSoldiers, int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch);
void promoteSoldier(int totalSoldiers, string *name, string *rank, string *branch);

int totalSoldiers = 0;
int MaxSoldiers = 100;
int n = 0;

void title()
{
    cout << "     \033[1;32;40m============================================\033[0m" << endl;
    cout << "     \033[1;32;40m||                                        ||\033[0m" << endl;
    cout << "     \033[1;32;40m||       MILITARY MANAGMENT SYSTEM        ||\033[0m" << endl;
    cout << "     \033[1;32;40m||                                        ||\033[0m" << endl;
    cout << "     \033[1;32;40m============================================\033[0m" << endl;
    cout << endl;
}

// duplicate function
void BranchSelection2(int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch, int n)
{
    int option;
    do
    {
        cout << "\033[1;32m Select the Branch:" << endl;
        cout << endl;
        cout << " 1. Air Force" << endl;
        cout << " 2. Land Army" << endl;
        cout << " 3. Navy" << endl;
        cout << " 4. Exit the System.." << endl;
        cout << endl;
        cout << "Your Choice : \033[0m";
        cin >> option;

        if (option == 1)
        {
            cout << "you choosed airforce" << endl;
            cout << endl;
            n = 1;
            ActionsMenu(soldiers, name, month, ssn, rank, service, branch, n);
        }
        else if (option == 2)
        {
            cout << "you choosed army" << endl;
            cout << endl;
            n = 2;
            ActionsMenu(soldiers, name, month, ssn, rank, service, branch, n);
        }
        else if (option == 3)
        {
            cout << "you choosed navy" << endl;
            cout << endl;
            n = 3;
            ActionsMenu(soldiers, name, month, ssn, rank, service, branch, n);
        }
        else if (option == 4)
        {
            cout << "........Exiting........" << endl;
        }
        else
        {
            cout << "\033[3;31m Invalid Selection! CHOOSE AGAIN!\033[0m" << endl;
            cout << endl;
        }
    } while (option < 1 or option > 4);
}

void BranchSelection(int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch, int n)
{
    int option;
    do
    {
        cout << "\033[1;32m Select the Branch:" << endl;
        cout << endl;
        cout << " 1. Air Force" << endl;
        cout << " 2. Land Army" << endl;
        cout << " 3. Navy" << endl;
        cout << " 4. Exit the System.." << endl;
        cout << endl;
        cout << "Press 0 to add some soldiers..." << endl;
        cout << "Press 5 to use preadded soldiers..." << endl;
        cout << endl;
        cout << "Your Choice : \033[0m";
        cin >> option;
        if (option == 0)
        {
            int nofSoldiers;
            cout << "How Many Number of Soldiers You want to add: ";
            cin >> nofSoldiers;
            addInitialSoldiers(nofSoldiers, soldiers, name, month, ssn, rank, service, branch);
            totalSoldiers = nofSoldiers;
        }

        else if (option == 1)
        {
            cout << "you choosed airforce" << endl;
            cout << endl;
            n = 1;
            ActionsMenu(soldiers, name, month, ssn, rank, service, branch, n);
        }
        else if (option == 2)
        {
            cout << "you choosed army" << endl;
            cout << endl;
            n = 2;
            ActionsMenu(soldiers, name, month, ssn, rank, service, branch, n);
        }
        else if (option == 3)
        {
            cout << "you choosed navy" << endl;
            cout << endl;
            n = 3;
            ActionsMenu(soldiers, name, month, ssn, rank, service, branch, n);
        }
        else if (option == 4)
        {

            cout << "........Exiting........" << endl;
        }
        else if (option == 5)
        {
            cout << endl;
            cout << "\033[3;33mAdding Default Soldiers........\033[0m" << endl;
            preaddedSoldiers(soldiers, name, month, ssn, rank, service, branch);
            cout << "\033[3;35m10 Soldiers Added\033[0m" << endl;
            cout << endl;
            totalSoldiers = 10;
            BranchSelection2(soldiers, name, month, ssn, rank, service, branch, n);
        }
        else
        {
            cout << "\033[3;31m Invalid Selection! CHOOSE AGAIN!\033[0m" << endl;
            cout << endl;
        }
    } while (option < 0 or option > 5);
}
void ActionsMenu(int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch, int n)
{
    int opt;
    do
    {
        cout << "\033[1;33mWHAT ACTION YOU WANT TO PERFORM:\033[0m" << endl;
        cout << endl;
        cout << "\033[0;32m1. Check Personals Database" << endl;
        cout << "2. Check Ranks" << endl;
        cout << "3. Add Soldier" << endl;
        cout << "4. Update Soldier Information" << endl;
        cout << "5. Search Soldier Information" << endl;
        cout << "6. Delete Soldier" << endl;
        cout << "7. Promote a Soldier" << endl;
        cout << "8. Display All Soldiers.." << endl;
        cout << "9. Exit the System!\033[0m" << endl;
        cout << endl;
        cout << "\033[1;32mMake Selection : \033[0m";
        cin >> opt;
        if (opt == 1)
        {
            char choose1;

            cout << "Personol database: " << endl;
            cout << endl;
            if (n == 2)
                ArmySoldierDatabase(totalSoldiers, soldiers, name, month, ssn, rank, service, branch);
            else if (n == 1)
                AirForceSoldierDatabase(totalSoldiers, soldiers, name, month, ssn, rank, service, branch);
            else if (n == 3)
                NavySoldierDatabase(totalSoldiers, soldiers, name, month, ssn, rank, service, branch);
            cout << "do you want to go to main menu(y/n) : ";
            cin >> choose1;
            if (choose1 == 'y' or choose1 == 'Y')
            {
                ActionsMenu(soldiers, name, month, ssn, rank, service, branch, n);
            }
        }
        else if (opt == 2)
        {
            char choose3;
            cout << "Current Ranks......" << endl;
            if (n == 2)
                ArmyRanks();
            else if (n == 1)
                AirForceRanks();
            else if (n == 3)
                NavyRanks();
            cout << "do you want to go to main menu(y/n) : ";
            cin >> choose3;
            if (choose3 == 'y' or choose3 == 'Y')
            {
                ActionsMenu(soldiers, name, month, ssn, rank, service, branch, n);
            }
        }

        else if (opt == 3)
        {
            char choose2;
            addSoldier(totalSoldiers, soldiers, name, month, ssn, rank, service, branch);
            cout << "Soldier Added....." << endl;
            cout << endl;
            cout << "do you want to go to main menu(y/n) : ";
            cin >> choose2;
            if (choose2 == 'y' or choose2 == 'Y')
            {
                ActionsMenu(soldiers, name, month, ssn, rank, service, branch, n);
            }
        }
        else if (opt == 5)
        {
            char choose2;
            searchSoldier(totalSoldiers, soldiers, name, month, ssn, rank, service, branch);
            cout << "do you want to go to main menu(y/n) : ";
            cin >> choose2;
            if (choose2 == 'y' or choose2 == 'Y')
            {
                ActionsMenu(soldiers, name, month, ssn, rank, service, branch, n);
            }
        }
        else if (opt == 4)
        {
            char choose2;
            updateSoldier(totalSoldiers, soldiers, name, month,
                          ssn, rank, service, branch);
            cout << "do you want to go to main menu(y/n) : ";
            cin >> choose2;
            if (choose2 == 'y' or choose2 == 'Y')
            {
                ActionsMenu(soldiers, name, month, ssn, rank, service, branch, n);
            }
        }
        else if (opt == 6)
        {
            char choose5;
            cout << "Delete a Soldier:" << endl;
            cout << endl;
            if (n == 2)
            {
                ArmySoldierDatabase(totalSoldiers, soldiers, name, month, ssn, rank, service, branch);
                cout << endl;
                deleteSoldierArmy(soldiers, name, month, ssn, rank, service, branch);
                cout << endl;
                cout << "\033[3;31m Deletion Done! After Deletion: \033[0m" << endl;
                cout << endl;
                ArmySoldierDatabase(totalSoldiers, soldiers, name, month, ssn, rank, service, branch);
            }
            else if (n == 1)
            {
                AirForceSoldierDatabase(totalSoldiers, soldiers, name, month, ssn, rank, service, branch);
                cout << endl;
                deleteSoldierAirForce(soldiers, name, month, ssn, rank, service, branch);
                cout << endl;
                cout << "\033[3;31m Deletion Done! After Deletion: \033[0m" << endl;
                cout << endl;
                AirForceSoldierDatabase(totalSoldiers, soldiers, name, month, ssn, rank, service, branch);
            }
            else if (n == 3)
            {
                NavySoldierDatabase(totalSoldiers, soldiers, name, month, ssn, rank, service, branch);
                cout << endl;
                deleteSoldierNavy(soldiers, name, month, ssn, rank, service, branch);
                cout << endl;
                cout << "\033[3;31m Deletion Done! After Deletion: \033[0m" << endl;
                cout << endl;
                NavySoldierDatabase(totalSoldiers, soldiers, name, month, ssn, rank, service, branch);
            }
            cout << "do you want to go to main menu(y/n) : ";
            cin >> choose5;
            if (choose5 == 'y' or choose5 == 'Y')
            {
                ActionsMenu(soldiers, name, month, ssn, rank, service, branch, n);
            }
        }
        else if (opt == 7)
        {
            char choose2;
            promoteSoldier(totalSoldiers, name, rank, branch);
            cin >> choose2;
            if (choose2 == 'y' or choose2 == 'Y')
            {
                ActionsMenu(soldiers, name, month, ssn, rank, service, branch, n);
            }
        }

        else if (opt == 8)
        {
            char choose4;
            cout << "All Soldiers....From all Branches." << endl;
            cout << "From AirForce: " << endl;
            AirForceSoldierDatabase(totalSoldiers, soldiers, name, month, ssn, rank, service, branch);
            cout << endl;
            cout << "From Army: " << endl;
            ArmySoldierDatabase(totalSoldiers, soldiers, name, month, ssn, rank, service, branch);
            cout << endl;
            cout << "From Navy: " << endl;
            NavySoldierDatabase(totalSoldiers, soldiers, name, month, ssn, rank, service, branch);
            cout << endl;
            cout << "do you want to go to main menu(y/n) : ";
            cin >> choose4;
            if (choose4 == 'y' or choose4 == 'Y')
            {
                ActionsMenu(soldiers, name, month, ssn, rank, service, branch, n);
            }
        }

        else if (opt == 9)
        {
            cout << ".......Exiting the army branch......." << endl;
            BranchSelection2(soldiers, name, month, ssn, rank, service, branch, n);
        }
        else
        {
            cout << "\033[3;31m Invalid Selection! CHOOSE AGAIN!\033[0m" << endl;
            cout << endl;
        }

    } while (opt > 9 or opt < 1);
}
void addInitialSoldiers(int noofSoldiers, int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch)
{
    cout << "First add the info of " << noofSoldiers << "soldiers: " << endl;
    for (int i = 0; i < noofSoldiers; i++)
    {
        cout << "Soldier " << i + 1 << " : " << endl;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name[i]);
        do
        {
            cout << "Enter Age: ";
            cin >> soldiers[i][0];
            if (soldiers[i][0] < 1 or soldiers[i][0] > 60)
            {

                cout << "Invalid age! ";
            }

        } while (soldiers[i][0] < 1 or soldiers[i][0] > 60);
        cout << "Enter Soldier_ID: ";
        cin >> soldiers[i][1];
        cout << "Enter Joining Month(i.e january , jan etc): ";
        cin >> month[i];
        cout << "Enter Joining Year: ";
        cin >> soldiers[i][2];
        cout << "Enter SSN: ";
        cin >> ssn[i];
        cout << "Enter Rank(i.e Captain , General , etc): ";
        cin.ignore();
        getline(cin, rank[i]);
        cout << "Enter Course or Service(long , short etc): ";
        cin >> service[i];
        cout << "Enter Branch(army , navy , airforce): ";
        cin >> branch[i];
        cout << endl;
    }
}
void ArmySoldierDatabase(int totalSoldiers, int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch)
{
    int j = 1;
    for (int i = 0; i < totalSoldiers; i++)
    {

        if (branch[i] == "army" or branch[i] == "Army" or branch[i] == "ARMY")
        {
            cout << "\033[0;32mSoldier " << j << " : \033[0m" << endl;
            cout << endl;
            cout << "\033[0;33mName : \033[0m" << name[i] << endl;
            cout << "\033[0;33mS_ID : \033[0m" << soldiers[i][1] << endl;
            cout << "\033[0;33mAge : \033[0m" << soldiers[i][0] << endl;
            cout << "\033[0;33mBranch : \033[0m" << branch[i] << endl;
            cout << "\033[0;33mSSN : \033[0m" << ssn[i] << endl;
            cout << "\033[0;33mRank : \033[0m" << rank[i] << endl;
            cout << "\033[0;33mJoining : \033[0m" << month[i] << " " << soldiers[i][2] << endl;
            cout << "\033[0;33mservice : \033[0m" << service[i] << endl;
            cout << endl;
            j++;
        }
    }
}
void AirForceSoldierDatabase(int totalSoldiers, int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch)
{
    int j = 1;
    for (int i = 0; i < totalSoldiers; i++)
    {

        if (branch[i] == "airforce" or branch[i] == "AirForce" or branch[i] == "AIRFORCE")
        {
            cout << "\033[0;32mSoldier " << j << " : \033[0m" << endl;
            cout << endl;
            cout << "\033[0;33mName : \033[0m" << name[i] << endl;
            cout << "\033[0;33mS_ID : \033[0m" << soldiers[i][1] << endl;
            cout << "\033[0;33mAge : \033[0m" << soldiers[i][0] << endl;
            cout << "\033[0;33mBranch : \033[0m" << branch[i] << endl;
            cout << "\033[0;33mSSN : \033[0m" << ssn[i] << endl;
            cout << "\033[0;33mRank : \033[0m" << rank[i] << endl;
            cout << "\033[0;33mJoining : \033[0m" << month[i] << " " << soldiers[i][2] << endl;
            cout << "\033[0;33mservice : \033[0m" << service[i] << endl;
            cout << endl;
            j++;
        }
    }
}
void NavySoldierDatabase(int totalSoldiers, int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch)
{
    int j = 1;
    for (int i = 0; i < totalSoldiers; i++)
    {

        if (branch[i] == "navy" or branch[i] == "Navy" or branch[i] == "NAVY")
        {
            cout << "\033[0;32mSoldier " << j << " : \033[0m" << endl;
            cout << endl;
            cout << "\033[0;33mName : \033[0m" << name[i] << endl;
            cout << "\033[0;33mS_ID : \033[0m" << soldiers[i][1] << endl;
            cout << "\033[0;33mAge : \033[0m" << soldiers[i][0] << endl;
            cout << "\033[0;33mBranch : \033[0m" << branch[i] << endl;
            cout << "\033[0;33mSSN : \033[0m" << ssn[i] << endl;
            cout << "\033[0;33mRank : \033[0m" << rank[i] << endl;
            cout << "\033[0;33mJoining : \033[0m" << month[i] << " " << soldiers[i][2] << endl;
            cout << "\033[0;33mservice : \033[0m" << service[i] << endl;
            cout << endl;
            j++;
        }
    }
}
void addSoldier(int &totalSoldiers, int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch)
{
    cout << "Add info of Soldier: " << endl;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name[totalSoldiers]);
    do
    {
        cout << "Enter Age: ";
        cin >> soldiers[totalSoldiers][0];
        if (soldiers[totalSoldiers][0] < 1 or soldiers[totalSoldiers][0] > 60)
        {

            cout << "Invalid age! ";
        }

    } while (soldiers[totalSoldiers][0] < 1 or soldiers[totalSoldiers][0] > 60);
    cout << "Enter Soldier_ID: ";
    cin >> soldiers[totalSoldiers][1];
    cout << "Enter Joining Month(i.e january , jan etc): ";
    cin >> month[totalSoldiers];
    cout << "Enter Joining Year: ";
    cin >> soldiers[totalSoldiers][2];
    cout << "Enter SSN: ";
    cin >> ssn[totalSoldiers];
    cout << "Enter Rank(i.e Captain , General , etc): ";
    cin.ignore();
    getline(cin, rank[totalSoldiers]);
    cout << "Enter Course or Service(long , short etc): ";
    cin >> service[totalSoldiers];
    cout << "Enter Branch(army , navy , airforce): ";
    cin >> branch[totalSoldiers];
    cout << endl;
    totalSoldiers++;
}
void ArmyRanks()
{
    cout << "--Army Ranks---" << endl;
    cout << endl;
    cout << "Commisioned Officer: " << endl;
    cout << endl;
    cout << "1 . Field Marshal" << endl;
    cout << "2 . General (Chief of Army Staff)" << endl;
    cout << "3 . Lieutenant General" << endl;
    cout << "4 . Major General" << endl;
    cout << "5 . Brigadier" << endl;
    cout << "6 . Colonel" << endl;
    cout << "7 . Lieutenant Colonel" << endl;
    cout << "8 . Major" << endl;
    cout << "9 . Captain" << endl;
    cout << "10 . Lieutenant" << endl;
    cout << "11 . Second Lieutenant" << endl;

    cout << "Non-Commisioned Officer: " << endl;
    cout << endl;
    cout << "Subedar" << endl;
    cout << "Naib Subedar" << endl;
    cout << "Soldier(Private)" << endl;
}
void NavyRanks()
{
    cout << "--Navy Ranks---" << endl;
    cout << endl;
    cout << "Commissioned Officers:" << endl;
    cout << endl;
    cout << "1 . Admiral (Chief of Naval Staff)" << endl;
    cout << "2 . Vice Admiral" << endl;
    cout << "3 . Rear Admiral" << endl;
    cout << "4 . Commodore" << endl;
    cout << "5 . Captain" << endl;
    cout << "6 . Commander" << endl;
    cout << "7 . Lieutenant Commander" << endl;
    cout << "8 . Lieutenant" << endl;
    cout << "9 . Sub-Lieutenant" << endl;
    cout << "10 . Midshipman" << endl;

    cout << endl;
    cout << "Non-Commissioned Officers:" << endl;
    cout << endl;
    cout << "Master Chief Petty Officer" << endl;
    cout << "Chief Petty Officer" << endl;
    cout << "Petty Officer" << endl;
    cout << "Leading Seaman" << endl;
    cout << "Able Seaman" << endl;
    cout << "Ordinary Seaman" << endl;
}
void AirForceRanks()
{
    cout << "--Air Force Ranks---" << endl;
    cout << endl;
    cout << "Commissioned Officers:" << endl;
    cout << endl;
    cout << "1 . Air Chief Marshal (Chief of Air Staff)" << endl;
    cout << "2 . Air Marshal" << endl;
    cout << "3 . Air Vice Marshal" << endl;
    cout << "4 . Air Commodore" << endl;
    cout << "5 . Group Captain" << endl;
    cout << "6 . Wing Commander" << endl;
    cout << "7 . Squadron Leader" << endl;
    cout << "8 . Flight Lieutenant" << endl;
    cout << "9 . Flying Officer" << endl;
    cout << "10 . Pilot Officer" << endl;

    cout << endl;
    cout << "Non-Commissioned Officers (Airmen):" << endl;
    cout << endl;
    cout << "Warrant Officer" << endl;
    cout << "Chief Technician" << endl;
    cout << "Senior Technician" << endl;
    cout << "Corporal Technician" << endl;
    cout << "Junior Technician" << endl;
    cout << "Senior Aircraftman" << endl;
    cout << "Leading Aircraftman" << endl;
    cout << "Aircraftman" << endl;
}

void preaddedSoldiers(int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch)
{
    string defaultnames[] = {"Muhammad Fahad", "Zaid Taj", "Tayyab Hayyat", "Saad", "Ahad Latif", "Asim munir", "Ahmad Ali", "Muhammad Umer", "Awais Aslam", "Ahamad Dogar"};
    string defaultMonth[] = {"April", "May", "August", "Feburary", "December", "January", "November", "March", "August", "October"};
    string defaultService[] = {"Long", "Short", "Long", "Long", "Long", "Short", "Long", "Short", "Short", "Long"};
    string defaultBranch[] = {"Army", "Navy", "AirForce", "Army", "Navy", "Army", "Navy", "AirForce", "Army", "AirForce"};
    string defaultRank[] = {"Major General", "Commander", "Aircraftman", "Brigadier", "Sailor", "Field Marshal", "Rear Admiral", "Air Marshal", "Lietenaunt", "Flying Officer"};
    long long int defaultSSN[] = {421017654321, 352028765432, 611017890123, 374019876543, 422017111122, 611019999999, 352011234567, 423017555556, 374019888877, 611017333344};
    int defaultsoldiers[10][3] = {{20, 1214, 2020}, {25, 1215, 2016}, {32, 1010, 2009}, {40, 999, 2001}, {56, 398, 1996}, {23, 1339, 2023}, {19, 1699, 2025}, {39, 1001, 2017}, {31, 800, 2022}, {42, 501, 2011}};

    for (int i = 0; i < 10; i++)
    {
        name[i] = defaultnames[i];
        month[i] = defaultMonth[i];
        service[i] = defaultService[i];
        branch[i] = defaultBranch[i];
        rank[i] = defaultRank[i];
        ssn[i] = defaultSSN[i];

        soldiers[i][0] = defaultsoldiers[i][0];
        soldiers[i][1] = defaultsoldiers[i][1];
        soldiers[i][2] = defaultsoldiers[i][2];
    }
}
void deleteSoldierArmy(int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch)
{
    int n;
    int count = 0;
    int count2 = 0;
    int a = 1;
    int b = 0;
    for (int i = 0; i < totalSoldiers; i++)
    {
        if (branch[i] == "army" or branch[i] == "Army" or branch[i] == "ARMY")
        {
            count2++;
        }
    }
    do
    {
        cout << "Enter the Soldier Number You want to delete: ";
        cin >> n;
        if (n > totalSoldiers or n < 0 or n > count2)
        {
            cout << "\033[3;33mInValid Soldier Number!\033[0m" << endl;
        }

    } while (n > totalSoldiers or n < 0 or n > count2);
    for (int i = 0; i < totalSoldiers; i++)
    {
        if (branch[i] == "army" or branch[i] == "Army" or branch[i] == "ARMY")
        {
            count++;
            if (count == n)
            {
                soldiers[i][0] = {0};
                soldiers[i][1] = {0};
                soldiers[i][2] = {0};
                name[i] = "";
                month[i] = "";
                ssn[i] = 0;
                rank[i] = "";
                branch[i] = "";
                service[i] = "";

                a = 0;
                b = i;
            }
        }
    }
    if (a == 0)
    {
        for (int i = b; i < totalSoldiers; i++)
        {
            name[i] = name[i + 1];
            soldiers[i][0] = soldiers[i + 1][0];
            soldiers[i][1] = soldiers[i + 1][1];
            soldiers[i][2] = soldiers[i + 1][2];
            rank[i] = rank[i + 1];
            branch[i] = branch[i + 1];
            ssn[i] = ssn[i + 1];
            month[i] = month[i + 1];
            service[i] = service[i + 1];
        }
        totalSoldiers--;
    }
}
void deleteSoldierAirForce(int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch)
{
    int n;
    int count = 0;
    int count2 = 0;
    int a = 1;
    int b = 0;
    for (int i = 0; i < totalSoldiers; i++)
    {
        if (branch[i] == "airforce" or branch[i] == "AIRFORCE" or branch[i] == "AirForce")
        {
            count2++;
        }
    }
    do
    {
        cout << "Enter the Soldier Number You want to delete: ";
        cin >> n;
        if (n > totalSoldiers or n < 0 or n > count2)
        {
            cout << "\033[3;33mInValid Soldier Number!\033[0m" << endl;
        }

    } while (n > totalSoldiers or n < 0 or n > count2);
    for (int i = 0; i < totalSoldiers; i++)
    {
        if (branch[i] == "airforce" or branch[i] == "AirForce" or branch[i] == "AIRFORCE")
        {
            count++;
            if (count == n)
            {
                soldiers[i][0] = {0};
                soldiers[i][1] = {0};
                soldiers[i][2] = {0};
                name[i] = "";
                month[i] = "";
                ssn[i] = 0;
                rank[i] = "";
                branch[i] = "";
                service[i] = "";

                a = 0;
                b = i;
            }
        }
    }
    if (a == 0)
    {
        for (int i = b; i < totalSoldiers; i++)
        {
            name[i] = name[i + 1];
            soldiers[i][0] = soldiers[i + 1][0];
            soldiers[i][1] = soldiers[i + 1][1];
            soldiers[i][2] = soldiers[i + 1][2];
            rank[i] = rank[i + 1];
            branch[i] = branch[i + 1];
            ssn[i] = ssn[i + 1];
            month[i] = month[i + 1];
            service[i] = service[i + 1];
        }
        totalSoldiers--;
    }
}
void deleteSoldierNavy(int **soldiers, string *name, string *month, long long int *ssn, string *rank, string *service, string *branch)
{
    int n;
    int count = 0;
    int count2 = 0;
    int a = 1;
    int b = 0;
    for (int i = 0; i < totalSoldiers; i++)
    {
        if (branch[i] == "navy" or branch[i] == "NAVY" or branch[i] == "Navy")
        {
            count2++;
        }
    }
    do
    {
        cout << "Enter the Soldier Number You want to delete: ";
        cin >> n;
        if (n > totalSoldiers or n < 0 or n > count2)
        {
            cout << "\033[3;33mInValid Soldier Number!\033[0m" << endl;
        }

    } while (n > totalSoldiers or n < 0 or n > count2);
    for (int i = 0; i < totalSoldiers; i++)
    {
        if (branch[i] == "Navy" or branch[i] == "navy" or branch[i] == "NAVY")
        {
            count++;
            if (count == n)
            {
                soldiers[i][0] = {0};
                soldiers[i][1] = {0};
                soldiers[i][2] = {0};
                name[i] = "";
                month[i] = "";
                ssn[i] = 0;
                rank[i] = "";
                branch[i] = "";
                service[i] = "";

                a = 0;
                b = i;
            }
        }
    }
    if (a == 0)
    {
        for (int i = b; i < totalSoldiers; i++)
        {
            name[i] = name[i + 1];
            soldiers[i][0] = soldiers[i + 1][0];
            soldiers[i][1] = soldiers[i + 1][1];
            soldiers[i][2] = soldiers[i + 1][2];
            rank[i] = rank[i + 1];
            branch[i] = branch[i + 1];
            ssn[i] = ssn[i + 1];
            month[i] = month[i + 1];
            service[i] = service[i + 1];
        }
        totalSoldiers--;
    }
}

void searchSoldier(int totalSoldiers, int **soldiers, string *name, string *month,
                   long long int *ssn, string *rank, string *service, string *branch)
{
    cout << "\n=== SEARCH SOLDIER INFORMATION ===\n";

    int choice;
    bool valid = false;

    // Validate the search option
    do
    {
        cout << "Search by:\n1. Name\n2. Soldier ID\n3. Branch\nYour choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if (choice < 1 || choice > 3)
        {
            cout << "Invalid option! Try again.\n";
        }
        else
        {
            valid = true;
        }
    } while (!valid);

    bool found = false;
    string input;
    int id;

    cin.ignore(); // clear buffer

    // Search by NAME
    if (choice == 1)
    {
        cout << "Enter Soldier Name: ";
        getline(cin, input);
        string target = toLower(input);

        for (int i = 0; i < totalSoldiers; i++)
        {
            if (toLower(name[i]) == target)
            {
                cout << "\nSoldier Found!\n";
                cout << "Name: " << name[i] << "\n";
                cout << "Branch: " << branch[i] << "\n";
                cout << "Rank: " << rank[i] << "\n";
                found = true;
            }
        }
    }

    // Search by ID
    else if (choice == 2)
    {
        do
        {
            cout << "Enter Soldier ID: ";
            if (!(cin >> id))
            {
                cout << "Invalid ID! Must be a number.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else
                break;
        } while (true);

        for (int i = 0; i < totalSoldiers; i++)
        {
            if (soldiers[i][1] == id)
            {
                cout << "\nSoldier Found!\n";
                cout << "Name: " << name[i] << " (" << branch[i] << ")\n";
                found = true;
            }
        }
    }

    // Search by BRANCH
    else if (choice == 3)
    {
        cout << "Enter Branch: ";
        cin >> input;
        string target = toLower(input);

        for (int i = 0; i < totalSoldiers; i++)
        {
            if (toLower(branch[i]) == target)
            {
                cout << "Soldier: " << name[i]
                     << ", ID: " << soldiers[i][1] << endl;
                found = true;
            }
        }
    }

    if (!found)
        cout << "No matching soldier found.\n";
}
void updateSoldier(int totalSoldiers, int **soldiers, string *name, string *month,
                   long long int *ssn, string *rank, string *service, string *branch)
{
    cout << "\n=== UPDATE SOLDIER INFORMATION ===\n";

    int id;
    bool valid = false;

    // Validate ID input
    do
    {
        cout << "Enter Soldier ID to update: ";
        if (!(cin >> id))
        {
            cout << "Invalid ID! Enter numeric only.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else
            valid = true;
    } while (!valid);

    for (int i = 0; i < totalSoldiers; i++)
    {
        if (soldiers[i][1] == id)
        {
            cout << "\nSoldier Found: " << name[i] << "\n";

            cin.ignore();

            cout << "Enter new Rank: ";
            getline(cin, rank[i]);

            cout << "Enter new Service Type (Long/Short): ";
            cin >> service[i];

            cout << "Enter new Branch (Army/Navy/AirForce): ";
            cin >> branch[i];

            cout << "Soldier Updated Successfully!\n";
            return;
        }
    }

    cout << "No soldier found with that ID.\n";
}

void promoteSoldier(int totalSoldiers, string *name, string *rank, string *branch)
{
    cout << "\n=== PROMOTE A SOLDIER ===\n";

    cin.ignore();
    string input;
    cout << "Enter Soldier Name: ";
    getline(cin, input);
    string target = toLower(input);

    for (int i = 0; i < totalSoldiers; i++)
    {
        if (toLower(name[i]) == target)
        {
            cout << "Soldier Found: " << name[i] << endl;
            cout << "Current Rank: " << rank[i] << endl;

            string newRank;
            cout << "Enter New Rank: ";
            getline(cin, newRank);

            if (newRank.length() == 0)
            {
                cout << "Rank cannot be empty.\n";
                return;
            }

            rank[i] = newRank;
            cout << "Promotion Successful!\n";
            return;
        }
    }

    cout << "No soldier found with that name.\n";
}

string toLower(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
    }
    return s;
}

int main()
{

    int **soldiers;
    string *name;
    string *rank;
    string *month;
    long long int ssn[100] = {0};
    string *service;
    string *branch;

    soldiers = new int *[100];
    for (int i = 0; i < 100; i++)
    {
        soldiers[i] = new int[3];
    }
    name = new string[100];
    rank = new string[100];
    month = new string[100];
    service = new string[100];
    branch = new string[100];

    title();
    BranchSelection(soldiers, name, month, ssn, rank, service, branch, n);

    for (int i = 0; i < 100; i++)
    {
        delete[] soldiers[i];
    }
    delete[] soldiers;
    delete[] name;
    delete[] rank;
    delete[] month;
    delete[] branch;
    delete[] service;

    return 0;
}