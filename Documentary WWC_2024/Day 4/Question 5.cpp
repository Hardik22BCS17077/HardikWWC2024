
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Ad {
public:
    std::string id;            // Ad identifier
    double bidAmount;          // Bid amount for the ad
    double engagementRate;     // Engagement rate of the ad
    double remainingBudget;    // Remaining budget for the ad campaign
    double score;              // Calculated score for sorting

  
    Ad(std::string adId, double bid, double engagement, double budget)
        : id(adId), bidAmount(bid), engagementRate(engagement), remainingBudget(budget), score(0) {}
};

void calculateScore(Ad &ad, double weight1, double weight2, double weight3) {
    ad.score = (ad.bidAmount * weight1) + (ad.engagementRate * weight2) + (ad.remainingBudget * weight3);
}


bool compareAds(const Ad &a, const Ad &b) {
    return a.score > b.score; // Sort in descending order
}

void sortAds(std::vector<Ad> &ads, double weight1, double weight2, double weight3) {
    for (auto &ad : ads) {
        calculateScore(ad, weight1, weight2, weight3);
    }
    std::sort(ads.begin(), ads.end(), compareAds);
}

void printAds(const std::vector<Ad> &ads) {
    std::cout << "Sorted Ads by Score:\n";
    for (const auto &ad : ads) {
        std::cout << "Ad ID: " << ad.id 
                  << ", Bid Amount: " << ad.bidAmount 
                  << ", Engagement Rate: " << ad.engagementRate 
                  << ", Remaining Budget: " << ad.remainingBudget 
                  << ", Score: " << ad.score << "\n";
    }
}

int main() {
 
    std::vector<Ad> ads = {
        Ad("Ad1", 5.00, 0.10, 100),
        Ad("Ad2", 3.00, 0.15, 50),
        Ad("Ad3", 4.00, 0.20, 75),
        Ad("Ad4", 6.00, 0.25, 80),
        Ad("Ad5", 2.00, 0.30, 60)
    };

    double weight1 = 0.5; // Weight for bid amount
    double weight2 = 0.3; // Weight for engagement rate
    double weight3 = 0.2; // Weight for remaining budget


    sortAds(ads, weight1, weight2, weight3);

    printAds(ads);

    return 0;
}
