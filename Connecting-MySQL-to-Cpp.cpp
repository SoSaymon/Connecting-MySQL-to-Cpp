#include <iostream>
#include <mysql.h>

int qstate;

int main()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);

    conn = mysql_real_connect(conn, "localhost", "root", "password", "tutorial", 3306, NULL, 0);

    if (conn) 
    {
        std::cout << "Successful connection to DB\n";

        std::string query = "SELECT * FROM test";
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {
                std::cout << "ID: " << row[0] << ", Name: " << row[1] << ", Score: " << row[2] << "\n";
            }
        }
        else
        {
            std::cout << "Query failed: " << mysql_error(conn) << "\n";
        }
    }
    else
    {
        std::cout << "Connection has failed\n";
    }

    return 0;
}