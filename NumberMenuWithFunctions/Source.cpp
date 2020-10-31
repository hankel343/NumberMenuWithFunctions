#include <iostream>
#include <cctype>
#include <vector>

using namespace std;

char menu();
void printNumbers(vector<int>& numbers);
void addNumbers(vector<int>& numbers);
void printMean(vector<int>& numbers);
void printSmallest(vector<int>& numbers);
void printLargest(vector<int>& numbers);

int main()
{
    vector <int> numbers{};
    char selection;

    do
    {
        selection = menu();

        switch (selection)
        {
        case 'P':
        {
            printNumbers(numbers);
            break;
        }

        case 'A':
        {
            addNumbers(numbers);
            break;
        }

        case 'M':
        {
            printMean(numbers);
            break;
        }

        case 'S':
        {
            printSmallest(numbers);
            break;
        }

        case 'L':
        {
            printLargest(numbers);
            break;
        }

        case 'Q':
        {
            continue;
            break;
        }

        default:
            cout << "Invalid choice - try again\n\n";

        }

    } while (selection != 'Q');

    cout << "\nGoodbye..." << endl;
    cout << "\n";


    return 0;
}

char menu() {
    char choice;

    cout << "Please select an option from the menu below: \n";
    cout << "P - Print numbers\n";
    cout << "A - Add a number\n";
    cout << "M - Display the mean of the numbers\n";
    cout << "S - Display the smallest number\n";
    cout << "L - Display the largest number\n";
    cout << "Q - Quit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return toupper(choice);
}

void printNumbers(vector<int>& numbers)
{
    if (numbers.empty())
        cout << "You have not entered any numbers yet.\n\n";
    else {
        for (auto value : numbers) {
            cout << value << " ";
        }
        cout << "\n\n";
    }
}

void addNumbers(vector<int>& numbers)
{
    int input = 0;
    cout << "Enter the number that you would like to add: ";
    cin >> input;

    numbers.push_back(input);

    cout << "\n\n";
}

void printMean(vector<int>& numbers)
{
    float sum = 0;
    float numOfItems = 0;
    for (auto value : numbers)
    {
        sum += value;
        ++numOfItems;
    }

    cout << sum / numOfItems << "\n\n";
}

void printSmallest(vector<int>& numbers)
{
    if (numbers.empty())
        cout << "You have not entered any numbers yet.\n\n";
    else {
        int smallest = 100;

        for (auto value : numbers) {
            if (value < smallest)
                smallest = value;
        }

        cout << "The smallest value is: " << smallest;
        cout << "\n\n";
    }

}

void printLargest(vector<int>& numbers)
{
    int largest = 0;
    if (numbers.empty())
        cout << "You have not entered any numbers yet.\n\n";
    else
    {

        for (auto value : numbers)
        {
            if (value > largest)
                largest = value;
        }
        cout << "The largest number in the list is: " << largest;
        cout << "\n\n";
    }
}