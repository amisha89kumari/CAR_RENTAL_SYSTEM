#include "car.h"
#include "customer.h"
#include "database.h"

using namespace std;

int main() {
    MYSQL* conn = Database::connectDB();
    int choice;

    while (true) {
        cout << "\n===== Car Rental System =====\n";
        cout << "1. Add Car\n";
        cout << "2. View Cars\n";
        cout << "3. Rent a Car\n";
        cout << "4. Return a Car\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Car::addCar(conn);
                break;
            case 2:
                Car::viewCars(conn);
                break;
            case 3:
                Customer::rentCar(conn);
                break;
            case 4:
                Customer::returnCar(conn);
                break;
            case 5:
                cout << "Exiting...\n";
                mysql_close(conn);
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}

