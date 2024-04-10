// Завдання 13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

class GeometricProgression {
private:
    int initialElement; //початковий елемент
    int progressionRatio;//знаменник прогресії
    int position;

public:

    GeometricProgression() : initialElement(), progressionRatio(), position() {}
    GeometricProgression(int b, int q) : initialElement(b), progressionRatio(q) {}

    GeometricProgression(const GeometricProgression& other) { 
        initialElement = other.initialElement;
        progressionRatio = other.progressionRatio;
    }


    void printElements(int n) {
        for (int i = 1; i <= n; ++i) {
            cout << (*this)[i] << endl;
        }
    }

    void setPosition(int p) {
        position = p;
 }
    
    GeometricProgression operator+ (const GeometricProgression& other) {
        if (progressionRatio == other.progressionRatio) {
            int newElement = (*this)[position] + other[position];
            return GeometricProgression(newElement, progressionRatio);
        }
        else {
            cout << "Progressions have different ratios!" << endl;
        }
    }

    
    GeometricProgression operator-(const GeometricProgression& other) {
        if (progressionRatio == other.progressionRatio) {
            int newElement = initialElement - other.initialElement;
            return GeometricProgression(newElement, progressionRatio);
        }
        else {
            cout << "Progressions have different ratios!" << endl;
        }
    }

    
    GeometricProgression operator*(double number) {
        double newElement = initialElement * number;
        return GeometricProgression(newElement, progressionRatio);
    }


   // отримання елемента прогресії за заданим номером
   int operator[](int n) const { 
      return initialElement * pow(progressionRatio, n - 1);
   }


    // сума перших n елементів прогресії
    int operator()(int n) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += (*this)[i];
        }
        return sum;
    }


    friend ostream& operator<<(ostream& out, const GeometricProgression& gp) {
        out << "Initial element: " << gp.initialElement << endl;
        out << "Progression ratio: " << gp.progressionRatio << endl;
        return out;
    }

    friend istream& operator>>(istream& in, GeometricProgression& gp) {
        cout << "Initial element: ";
        in >> gp.initialElement;
        cout << "Progression ratio: ";
        in >> gp.progressionRatio;
        return in;
    }

    bool operator==(GeometricProgression other) {
        if (initialElement == other.initialElement)
            return true;
        else
            return false;
    }

    bool operator!=(GeometricProgression other) {
        return !this->operator==(other);
    }

    bool operator>(GeometricProgression other) {
        return initialElement > other.initialElement;
    }

    bool operator<(GeometricProgression other) {
        return initialElement < other.initialElement;
    }

    GeometricProgression& operator=(const GeometricProgression& other) {
        if (this == &other) return *this;

        initialElement = other.initialElement;
        progressionRatio = other.progressionRatio;

        return *this;
    }
};

int main() {
    
    GeometricProgression progression1(2, 2); 
    cout << "Elements of progression 1: " << endl;
    progression1.printElements(10);
    cout << endl;

    GeometricProgression progression2(3, 2); 
    cout << "Elements of progression 2: " << endl;
    progression2.printElements(10);
    cout << endl;

    if (progression1 == progression2) {
        cout << "Progressions are equal." << endl;
    }
    else {
        cout << "Progressions are not equal." << endl;
    }

    if (progression1 > progression2) {
        cout << "Progression 1 > progression 2." << endl;
    }
    else if (progression1 < progression2) {
        cout << "Progression 1 < progression 2." << endl;
    }
    else {
        cout << "Progressions are equal." << endl;
    }
    cout << endl;

    progression1.setPosition(1); // позиція елемента для додавання
    progression2.setPosition(1);
    GeometricProgression s = progression1 + progression2;
    cout << "Sum of progressions: ";
    s.printElements(1);

    GeometricProgression difference = progression2 - progression1;
    cout << "Difference of progressions: ";
    difference.printElements(1);


    cout << "Element at position 5 in progression 1: " << progression1[5] << endl;
    cout << "Sum of first 5 elements in progression 2: " << progression2(5) << endl << endl;


    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << endl;
    GeometricProgression multiplication1 = progression1 * n;
    cout << "Multiplied progression 1: " << multiplication1[2] << endl;

    GeometricProgression multiplication2 = progression2 * n;
    cout << "Multiplied progression 2: " << multiplication2[2] << endl << endl;


    GeometricProgression gp;
    cout << "Enter initial element and progression ratio." << endl;
    cin >> gp;
    cout << "Progression: " << endl << gp << endl;


    progression1 = progression2;
    cout << "Assign the value of progression 2 to progression 1:" << endl;
    progression1.printElements(10);
    cout << endl;

    return 0;
}
