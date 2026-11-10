#include <iostream>

int main()
{
    const double PI = 3.14159;
    int choice;

    std::cout << "Geometry Calculator\n"
              << "1. Calculate the Area of a Circle\n"
              << "2. Calculate the Area of a Rectangle\n"
              << "3. Calculate the Area of a Triangle\n"
              << "4. Quit\n"
              << "Enter your choice (1-4): ";
    std::cin >> choice;

    switch (choice)
    {
        case 1:
        {
            double radius;
            std::cout << "Enter the radius: ";
            std::cin >> radius;

            // Zero is allowed; only a negative radius is invalid.
            if (radius < 0.0)
            {
                std::cout << "Error: radius cannot be negative.\n";
            }
            else
            {
                double area = PI * radius * radius;
                std::cout << "Circle area: " << area << '\n';
            }
            break;
        }
        case 2:
        {
            double length;
            double width;
            std::cout << "Enter the length: ";
            std::cin >> length;
            std::cout << "Enter the width: ";
            std::cin >> width;

            // Reject the rectangle if either measurement is negative.
            if (length < 0.0 || width < 0.0)
            {
                std::cout << "Error: length and width cannot be negative.\n";
            }
            else
            {
                double area = length * width;
                std::cout << "Rectangle area: " << area << '\n';
            }
            break;
        }
        case 3:
        {
            double base;
            double height;
            std::cout << "Enter the base: ";
            std::cin >> base;
            std::cout << "Enter the height: ";
            std::cin >> height;

            // Reject the triangle if either measurement is negative.
            if (base < 0.0 || height < 0.0)
            {
                std::cout << "Error: base and height cannot be negative.\n";
            }
            else
            {
                double area = base * height * 0.5;
                std::cout << "Triangle area: " << area << '\n';
            }
            break;
        }
        case 4:
            std::cout << "Goodbye.\n";
            break;
        default:
            // Any other numeric menu choice is outside the valid range.
            std::cout << "Error: choice must be between 1 and 4.\n";
            break;
    }

    return 0;
}
