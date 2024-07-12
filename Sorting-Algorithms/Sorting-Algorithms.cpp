#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <string>

const int delay = 100;

// Function to print bars representing elements
void printBars(const std::vector<int>& data) {
    int maxElement = *std::max_element(data.begin(), data.end());
    for (int i = maxElement; i > 0; --i) {
        for (int value : data) {
            if (value >= i)
                std::cout << "??";
            else
                std::cout << "  ";
        }
        std::cout << std::endl;
    }
}

// Function to visualize Bubble Sort
void visualizeBubbleSort(std::vector<int>& data) {

    std::cout << "Bubble Sort Sorting:" << std::endl;
    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl << std::endl;

    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data.size() - 1 - i; ++j) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                system("cls"); // Clear console
                std::cout << "Bubble Sort Sorting:" << std::endl;
                printBars(data);
                std::cout << std::endl;
            }
        }
    }

    std::cout << "Sorted!" << std::endl;
}

// Function to visualize Selection Sort
void visualizeSelectionSort(std::vector<int>& data) {

    std::cout << "Selection Sort Sorting:" << std::endl;
    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl << std::endl;

    for (int i = 0; i < data.size() - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < data.size(); ++j) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(data[i], data[minIndex]);
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        system("cls"); // Clear console
        std::cout << "Selection Sort Sorting:" << std::endl;
        printBars(data);
        std::cout << std::endl;
    }

    std::cout << "Sorted!" << std::endl;
}

// Function to visualize Insertion Sort
void visualizeInsertionSort(std::vector<int>& data) {

    std::cout << "Insertion Sort Sorting:" << std::endl;
    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl << std::endl;

    for (int i = 1; i < data.size(); ++i) {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            --j;
        }
        data[j + 1] = key;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        system("cls"); // Clear console
        std::cout << "Insertion Sort Sorting:" << std::endl;
        printBars(data);
        std::cout << std::endl;
    }

    std::cout << "Sorted!" << std::endl;
}

void Introduction() {

    std::vector<int> data = { 7, 4, 5, 2, 9, 1, 3, 8, 6 };

    std::cout << "Select a sorting algorithm:" << std::endl;
    std::cout << "1. Bubble Sort" << std::endl;
    std::cout << "2. Selection Sort" << std::endl;
    std::cout << "3. Insetion Sort" << std::endl;
    std::cout << "4. Exit" << std::endl;

    std::cout << "Enter your choice: ";

    int choice = 0;

    std::cin >> choice;

    switch (choice) {
    case 1:
        visualizeBubbleSort(data);
        break;
    case 2:
        visualizeSelectionSort(data);
        break;
    case 3:
        visualizeInsertionSort(data);
        break;
    case 4:
        break;
    default:
        std::cout << "\nInvalid selection. Try Again" << std::endl;
        Introduction();
    }
}

int main() {
    
    Introduction();

    return 0;
}
