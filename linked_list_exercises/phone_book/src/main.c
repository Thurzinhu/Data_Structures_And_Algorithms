#include <stdio.h>
#include <stdlib.h>
#include "../include/container.h"
#include "../include/dynamic_operations.h"
#include "../include/static_operations.h"

int main(int argc, char *argv[])
{
    // LinkedList *test = buildPhoneBook();
    // Contact contacts[] = {
    //     {"John Doe", "1234567890", "0987654321", "john.doe@example.com", {1, 1}},
    //     {"John Doe", "1234567890", "0987654321", "john.doe@example.com", {1, 1}},
    //     {"John Doe", "1234567890", "0987654321", "john.doe@example.com", {1, 1}},
    //     {"John Doe", "1234567890", "0987654321", "john.doe@example.com", {1, 1}},
    //     {"John Doe", "1234567890", "0987654321", "john.doe@example.com", {1, 1}},
    //     {"John Doe", "1234567890", "0987654321", "john.doe@example.com", {1, 1}},
    //     {"John Doe", "1234567890", "0987654321", "john.doe@example.com", {1, 1}},
    //     {"John Doe", "1234567890", "0987654321", "john.doe@example.com", {1, 1}},
    //     {"John Doe", "1234567890", "0987654321", "john.doe@example.com", {1, 1}},
    //     {"Jane Smith", "2345678901", "1098765432", "jane.smith@example.com", {2, 2}},
    //     {"Jane Smith", "2345678901", "1098765432", "jane.smith@example.com", {2, 2}},
    //     {"Jane Smith", "2345678901", "1098765432", "jane.smith@example.com", {2, 2}},
    //     {"Jane Smith", "2345678901", "1098765432", "jane.smith@example.com", {2, 2}},
    //     {"Jane Smith", "2345678901", "1098765432", "jane.smith@example.com", {2, 2}},
    //     {"Jane Smith", "2345678901", "1098765432", "jane.smith@example.com", {2, 2}},
    //     {"Jane Smith", "2345678901", "1098765432", "jane.smith@example.com", {2, 2}},
    //     {"Bob Johnson", "3456789012", "2109876543", "bob.johnson@example.com", {3, 3}},
    //     {"Alice Williams", "4567890123", "3210987654", "alice.williams@example.com", {4, 4}},
    //     {"Charlie Brown", "5678901234", "4321098765", "charlie.brown@example.com", {5, 5}},
    //     {"Charlie Brown", "5678901234", "4321098765", "charlie.brown@example.com", {5, 5}},
    //     {"Charlie Brown", "5678901234", "4321098765", "charlie.brown@example.com", {5, 5}},
    //     {"Charlie Brown", "5678901234", "4321098765", "charlie.brown@example.com", {5, 5}},
    //     {"Charlie Brown", "5678901234", "4321098765", "charlie.brown@example.com", {5, 5}},
    //     {"Charlie Brown", "5678901234", "4321098765", "charlie.brown@example.com", {5, 5}},
    //     {"Charlie Brown", "5678901234", "4321098765", "charlie.brown@example.com", {5, 5}},
    //     {"Charlie Brown", "5678901234", "4321098765", "charlie.brown@example.com", {5, 5}},
    //     {"Diane Davis", "6789012345", "5432109876", "diane.davis@example.com", {6, 6}},
    //     {"Diane Davis", "6789012345", "5432109876", "diane.davis@example.com", {6, 6}},
    //     {"Diane Davis", "6789012345", "5432109876", "diane.davis@example.com", {6, 6}},
    //     {"Diane Davis", "6789012345", "5432109876", "diane.davis@example.com", {6, 6}},
    //     {"Diane Davis", "6789012345", "5432109876", "diane.davis@example.com", {6, 6}},
    //     {"Diane Davis", "6789012345", "5432109876", "diane.davis@example.com", {6, 6}},
    //     {"Ethan Miller", "7890123456", "6543210987", "ethan.miller@example.com", {7, 7}},
    //     {"Ethan Miller", "7890123456", "6543210987", "ethan.miller@example.com", {7, 7}},
    //     {"Ethan Miller", "7890123456", "6543210987", "ethan.miller@example.com", {7, 7}},
    //     {"Ethan Miller", "7890123456", "6543210987", "ethan.miller@example.com", {7, 7}},
    //     {"Fiona Wilson", "8901234567", "7654321098", "fiona.wilson@example.com", {8, 8}},
    //     {"Fiona Wilson", "8901234567", "7654321098", "fiona.wilson@example.com", {8, 8}},
    //     {"Fiona Wilson", "8901234567", "7654321098", "fiona.wilson@example.com", {8, 8}},
    //     {"Fiona Wilson", "8901234567", "7654321098", "fiona.wilson@example.com", {8, 8}},
    //     {"Fiona Wilson", "8901234567", "7654321098", "fiona.wilson@example.com", {8, 8}},
    //     {"Fiona Wilson", "8901234567", "7654321098", "fiona.wilson@example.com", {8, 8}},
    //     {"George Moore", "9012345678", "8765432109", "george.moore@example.com", {9, 9}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}},
    //     {"Hannah Taylor", "0123456789", "9876543210", "hannah.taylor@example.com", {10, 10}}
    // };

    // for (int i = 0; i < sizeof(contacts) / sizeof(contacts[0]); i++)
    //     insertContact(test, &contacts[i]);

    phoneBookInterface(NULL);
}