#include <iostream>
#include <string>
#include <vector>
#include <thread>

void playFizzBuzz(const std::vector<std::string>& playerNames, const int& numPlayers, const int& maxValue)
{
    for (int n = 1; n <= maxValue; ++n)
    {
        std::cout << "Player " << playerNames[(n-1)%numPlayers] << " says ";
        
        if (n % 3 == 0 && n % 5 == 0)  // Fixed the condition here
        {
            std::cout << "FizzBuzz." << std::endl;
            continue;
        }

        if (n % 3 == 0)
        {
            std::cout << "Fizz" << std::endl;
            continue;
        }

        if (n % 5 == 0)
        {
            std::cout << "Buzz" << std::endl;
            continue;
        }

        std::cout << n << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);  // Disable synchronization with C-style I/O

    int numPlayers;
    std::cout << "Enter number of Players: ";
    std::cin >> numPlayers;

    std::vector<std::string> playerNames;
    playerNames.reserve(numPlayers);
    
    for (int it = 0; it < numPlayers; ++it) {
        std::cout << "Enter player name: ";
        std::string playerName;
        std::cin >> playerName;
        playerNames.emplace_back(playerName);  
    };

    int maxValue;
    std::cout << "Enter Max Value: ";
    std::cin >> maxValue;
    
    std::thread playFizzBuzzThr(playFizzBuzz, std::ref(playerNames), std::ref(numPlayers), std::ref(maxValue));  
    playFizzBuzzThr.join();
    
    return 0;
}
