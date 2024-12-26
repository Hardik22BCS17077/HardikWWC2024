#include <iostream>
#include <limits> 
using namespace std;

int main() {
    string ads[4] = {"Shampoo", "Oil", "Energy drink", "Mobile"};
    string final_ad[4];
    int remaining_amount, bid_amount, paid, engagement;
    int priority[4];

    for (int i = 0; i < 4; i++) {
        cout << "Enter for ad " << ads[i] << ":\n";
        cout << "1. Remaining Amount: ";
        cin >> remaining_amount;
        cout << "2. Bid Amount: ";
        cin >> bid_amount;
        cout << "3. Engagement: ";
        cin >> engagement;

        if (bid_amount > 0) {
            paid = bid_amount - remaining_amount;
            priority[i] = (paid * engagement) 
        } else {
            priority[i] = 0; 
        }
    }

    
    for (int i = 0; i < 4; i++) {
        int max_priority = -1;
        int index = -1;

        for (int j = 0; j < 4; j++) {
            if (priority[j] > max_priority) {
                max_priority = priority[j];
                index = j;
            }
        }

        if (index != -1) {
            final_ad[i] = ads[index];
            priority[index] = -1; 
        }
    }

    cout << "Final ad order:\n";
    for (int i = 0; i < 4; i++) {
        cout << final_ad[i] << endl; 
    }

    return 0;
}
