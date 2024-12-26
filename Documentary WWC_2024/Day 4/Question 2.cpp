#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

struct Trade {
    std::string timestamp; 
    std::string stockSymbol;
    double tradePrice;
    int tradeVolume;
};

// Comparator for sorting trades by timestamp
bool compareByTimestamp(const Trade &a, const Trade &b) {
    return a.timestamp < b.timestamp;
}


void processTrades(std::vector<Trade> &trades) {
    // Step 1: Sort trades by timestamp
    std::sort(trades.begin(), trades.end(), compareByTimestamp);

    // Step 2: Group trades by stock symbol and calculate total volume
    std::unordered_map<std::string, int> volumeTrends;
    for (const auto &trade : trades) {
        volumeTrends[trade.stockSymbol] += trade.tradeVolume;
    }

    // Output sorted trades
    std::cout << "Sorted Trades by Timestamp:\n";
    for (const auto &trade : trades) {
        std::cout << trade.timestamp << " | " << trade.stockSymbol 
                  << " | Price: " << trade.tradePrice 
                  << " | Volume: " << trade.tradeVolume << "\n";
    }

    // Output trading volume trends
    std::cout << "\nTrading Volume Trends:\n";
    for (const auto &entry : volumeTrends) {
        std::cout << "Stock: " << entry.first << " | Total Volume: " << entry.second << "\n";
    }
}

int main() {
    // Example trade data
    std::vector<Trade> trades = {
        {"2023-10-01T12:00:00Z", "AAPL", 150.0, 100},
        {"2023-10-01T12:00:01Z", "GOOGL", 2800.0, 50},
        {"2023-10-01T12:00:00Z", "AAPL", 151.0, 200},
        {"2023-10-01T12:00:02Z", "MSFT", 300.0, 150},
        {"2023-10-01T12:00:01Z", "GOOGL", 2795.0, 75}
    };

    // Process the trades
    processTrades(trades);

    return 0;
}
