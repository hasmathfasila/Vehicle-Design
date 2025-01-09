#include <iostream>
#include <vector>
#include <string>

// Base class for vehicle parts
class Part {
public:
    virtual void display() const = 0; // Pure virtual function for polymorphism
};

// Derived class for Engine
class Engine : public Part {
protected:
    std::string type;
public:
    Engine(const std::string& type) : type(type) {}
    virtual void display() const override {
        std::cout << "Engine Type: " << type << std::endl;
    }
};

// Derived class for DieselEngine
class DieselEngine : public Engine {
public:
    DieselEngine() : Engine("Diesel") {}
    void display() const override {
        std::cout << "Diesel Engine" << std::endl;
    }
};

// Derived class for ElectricEngine
class ElectricEngine : public Engine {
public:
    ElectricEngine() : Engine("Electric") {}
    void display() const override {
        std::cout << "Electric Engine" << std::endl;
    }
};

// Class for Chassis
class Chassis : public Part {
public:
    void display() const override {
        std::cout << "Chassis" << std::endl;
    }
};

// Base class for Vehicle
class Vehicle {
protected:
    std::vector<Part*> parts;
    double durabilityScore;
    double efficiencyScore;
public:
    Vehicle() : durabilityScore(0), efficiencyScore(0) {}
    virtual void addPart(Part* part) {
        parts.push_back(part);
    }
    virtual void display() const {
        std::cout << "Vehicle Configuration:" << std::endl;
        for (const auto& part : parts) {
            part->display();
        }
    }
    virtual void simulatePerformance() const {
        std::cout << "Simulating performance under various conditions..." << std::endl;
        // Placeholder for simulation logic
    }
    virtual void generateReport() const {
        std::cout << "Generating detailed report on durability and efficiency..." << std::endl;
        std::cout << "Durability Score: " << durabilityScore << std::endl;
        std::cout << "Efficiency Score: " << efficiencyScore << std::endl;
    }
    void setDurabilityScore(double score) {
        durabilityScore = score;
    }
    void setEfficiencyScore(double score) {
        efficiencyScore = score;
    }
    const std::vector<Part*>& getParts() const {
        return parts;
    }
};

// Derived class for Car
class Car : public Vehicle {
public:
    void display() const override {
        std::cout << "Car Configuration:" << std::endl;
        Vehicle::display();
    }
};

// Derived class for Truck
class Truck : public Vehicle {
public:
    void display() const override {
        std::cout << "Truck Configuration:" << std::endl;
        Vehicle::display();
    }
};

// Derived class for Motorcycle
class Motorcycle : public Vehicle {
public:
    void display() const override {
        std::cout << "Motorcycle Configuration:" << std::endl;
        Vehicle::display();
    }
};

// Class for StressTest
class StressTest {
public:
    void loadTest(Vehicle& vehicle) const {
        std::cout << "Performing load test on vehicle..." << std::endl;
        // Placeholder for load test logic
        double durability = calculateDurability(vehicle);
        vehicle.setDurabilityScore(durability);
    }
    void durabilityTest(Vehicle& vehicle) const {
        std::cout << "Performing durability test on vehicle..." << std::endl;
        // Placeholder for durability test logic
        double durability = calculateDurability(vehicle);
        vehicle.setDurabilityScore(durability);
    }
    void efficiencyTest(Vehicle& vehicle) const {
        std::cout << "Performing efficiency test on vehicle..." << std::endl;
        // Placeholder for efficiency test logic
        double efficiency = calculateEfficiency(vehicle);
        vehicle.setEfficiencyScore(efficiency);
    }
private:
    double calculateDurability(const Vehicle& vehicle) const {
        // Placeholder for actual durability calculation logic
        // Example: Calculate based on number of parts and type of parts
        double durability = 100.0; // Example base value
        for (const auto& part : vehicle.getParts()) {
            // Adjust durability based on part type
            if (dynamic_cast<const DieselEngine*>(part)) {
                durability -= 5.0;
            } else if (dynamic_cast<const ElectricEngine*>(part)) {
                durability += 5.0;
            }
        }
        return durability;
    }
    double calculateEfficiency(const Vehicle& vehicle) const {
        // Placeholder for actual efficiency calculation logic
        // Example: Calculate based on type of engine and number of parts
        double efficiency = 100.0; // Example base value
        for (const auto& part : vehicle.getParts()) {
            // Adjust efficiency based on part type
            if (dynamic_cast<const DieselEngine*>(part)) {
                efficiency -= 10.0;
            } else if (dynamic_cast<const ElectricEngine*>(part)) {
                efficiency += 10.0;
            }
        }
        return efficiency;
    }
};

// Function to display the main menu
void displayMenu() {
    std::cout << "Vehicle Prototype System" << std::endl;
    std::cout << "1. Create Car" << std::endl;
    std::cout << "2. Create Truck" << std::endl;
    std::cout << "3. Create Motorcycle" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

// Function to add parts to a vehicle
void addParts(Vehicle& vehicle) {
    int choice;
    do {
        std::cout << "Add Parts" << std::endl;
        std::cout << "1. Add Diesel Engine" << std::endl;
        std::cout << "2. Add Electric Engine" << std::endl;
        std::cout << "3. Add Chassis" << std::endl;
        std::cout << "4. Done" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                vehicle.addPart(new DieselEngine());
                break;
            case 2:
                vehicle.addPart(new ElectricEngine());
                break;
            case 3:
                vehicle.addPart(new Chassis());
                break;
            case 4:
                std::cout << "Finished adding parts." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);
}

int main() {
    int choice;
    StressTest stressTest;

    do {
        displayMenu();
        std::cin >> choice;

        Vehicle* vehicle = nullptr;
        switch (choice) {
            case 1:
                vehicle = new Car();
                break;
            case 2:
                vehicle = new Truck();
                break;
            case 3:
                vehicle = new Motorcycle();
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        if (vehicle) {
            addParts(*vehicle);
            vehicle->display();
            vehicle->simulatePerformance();
            stressTest.loadTest(*vehicle);
            stressTest.durabilityTest(*vehicle);
            stressTest.efficiencyTest(*vehicle);
            vehicle->generateReport();
            delete vehicle;
        }
    } while (choice != 4);

    return 0;
}