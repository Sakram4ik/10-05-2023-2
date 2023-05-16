#include <iostream>
#include <string>

class IPAddress {
protected:
    std::string address;

public:
    IPAddress(const std::string& address) : address(address) {}

    IPAddress(const IPAddress& other) : address(other.address) {}

    void print() const {
        std::cout << "IPAddress: " << address << std::endl;
    }
};

class IPAddressChecked : public IPAddress {
private:
    bool is_correct;

public:
    IPAddressChecked(const std::string& address) : IPAddress(address) {
        is_correct = validateAddress();
    }

    IPAddressChecked(const IPAddressChecked& other) : IPAddress(other), is_correct(other.is_correct) {}

    void print() const {
        IPAddress::print();
        std::cout << "Is Correct: " << (is_correct ? "Correct" : "Not Correct") << std::endl;
    }

private:
    bool validateAddress() const {
        std::string remainingAddress = address;
        size_t pos = remainingAddress.find('.');
        std::string component;
        int value;

        while (pos != std::string::npos) {
            component = remainingAddress.substr(0, pos);
            value = std::stoi(component);
            if (value > 255 || value <0) {
                return false;
            }
          else if(pos < 3){
            return false;
          }
            remainingAddress.erase(0, pos + 1);
            pos = remainingAddress.find('.');
        }

        value = std::stoi(remainingAddress);
        if (value > 255) {
            return false;
        }

        return true;
    }
};

int main() {
    std::string address1, address2, address3;
    
    std::cout << "Enter the first IP address: ";
    std::cin >> address1;
    
    IPAddress ip_address(address1);
    ip_address.print();
    
    std::cout << "Enter the second IP address: ";
    std::cin >> address2;
    
    IPAddressChecked checked_address1(address2);
    checked_address1.print();
    
    std::cout << "Enter the third IP address: ";
    std::cin >> address3;
    
    IPAddressChecked checked_address2(address3);
    checked_address2.print();
    
    return 0;
}
