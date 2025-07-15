#include <stdlib.h>
#include <iostream>
#include <string>
#include "SQLstuff.h"
#include <sstream>
#include <optional>

#include <jdbc.h>
using  namespace std;

//for demonstration only. never save your password in the code!
const string server = "tcp://127.0.0.1:3306";
const string username = "jUser";


sql::Driver* driver;
sql::Connection* con;
sql::PreparedStatement* pstmt;
sql::ResultSet* res;

bool pwCheck(string password)
{
    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
        con->setSchema("journal");
    }
    
    catch (sql::SQLException e)
    {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        system("pause");
        //exit(1);

        return 0;
    }
} 


int sqlWrite(string textEntry, string entryID)
{
    /*
    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
        con->setSchema("journal");
    }
    
    catch (sql::SQLException e)
    {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        system("pause");
        //exit(1);

        return 0;
    }
    */

    try
    {

        pstmt = con->prepareStatement("INSERT INTO jentry (entryID, entryText) VALUES (?,?);");
        

        pstmt->setString(1, entryID);
        pstmt->setString(2, textEntry);
        
        pstmt->executeQuery();

        cout << "\nEntry inserted.\n" << endl;
    }
    catch (sql::SQLException e)
    {
        cout << "Statement went wrong. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }

   //delete pstmt;
   //delete con;
    system("pause");
    return 0;
}

int sqlRead(string entryID)
{
    
    try
    {
        pstmt = con->prepareStatement("SELECT entryText FROM jentry WHERE entryID = (?);");

        pstmt->setString(1, entryID);
        res = pstmt->executeQuery();

        while (res->next()) {
            
            string readEntry{ res->getString(1) };

            cout << readEntry;

        }

        cout << "Entry found." << endl;
    }
    catch (sql::SQLException e)
    {
        cout << "Statement went wrong. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }

    //delete pstmt;
    //delete con;
    system("pause");
    return 0;
}

int sqlList()
{
   
    try
    {
        std::cout << "\n|Entry ID         |            Entry Date|\n";
        for (int underLine{ 1 }; underLine <= 42; ++underLine)
            cout << "-";

        cout << '\n';
        pstmt = con->prepareStatement("SELECT entryID, entryDate FROM jentry;");

        
        res = pstmt->executeQuery();

        while (res->next()) {

            string entryList1{ res->getString(1) };
            string entryList2{ res->getString(2) };

            
            cout << "|" << entryList1 << "   |   " << entryList2 << "|" << '\n';



        }
        cout << '\n';
        std::cout << "Entry found." << endl;
    }
    catch (sql::SQLException e)
    {
        cout << "Statement went wrong. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }

    //delete pstmt;
    //delete con;
    system("pause");
    return 0;
}

int sqlDelete(string entryID)
{
    
    try
    {
        pstmt = con->prepareStatement("DELETE FROM jentry WHERE entryID = (?);");

        pstmt->setString(1, entryID);
        pstmt->executeQuery();

        cout << "Entry deleted." << endl;
    }
    catch (sql::SQLException e)
    {
        cout << "Statement went wrong. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }

    //delete pstmt;
    //delete con;
    system("pause");
    return 0;
}

void sqlQuit()
{
    delete pstmt;
    delete con;
}
