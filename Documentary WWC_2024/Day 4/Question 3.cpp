#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

struct Video {
    std::string title;
    int totalViews;
    double userRating;
    int releaseYear;
    std::vector<std::string> genres;
};


double calculateScore(const Video &video, int currentYear) {
    return (video.totalViews * video.userRating) / (currentYear - video.releaseYear + 1);
}

std::vector<Video> generateRecommendations(const std::vector<Video> &videos, const std::vector<std::string> &userGenres) {
    std::vector<Video> recommendations;

    for (const auto &video : videos) {
        // Check if the video matches the user's preferred genres
        for (const auto &genre : video.genres) {
            if (std::find(userGenres.begin(), userGenres.end(), genre) != userGenres.end()) {
                recommendations.push_back(video);
                break; // No need to check other genres for this video
            }
        }
    }

    return recommendations;
}

int main() {
    std::vector<Video> videos = {
        {"Movie A", 1000, 4.5, 2021, {"Action", "Adventure"}},
        {"Movie B", 5000, 4.8, 2020, {"Drama"}},
        {"Movie C", 2000, 4.0, 2022, {"Comedy"}},
        {"Movie D", 3000, 3.5, 2019, {"Action", "Thriller"}},
        {"Movie E", 1500, 4.2, 2023, {"Drama", "Romance"}}
    };

    int currentYear = 2023;

    // Step 1: Sort videos by popularity and recency
    std::sort(videos.begin(), videos.end(), [currentYear](const Video &a, const Video &b) {
        return calculateScore(a, currentYear) > calculateScore(b, currentYear);
    });

    // Output sorted videos
    std::cout << "Trending Videos:\n";
    for (const auto &video : videos) {
        std::cout << video.title << " | Score: " << calculateScore(video, currentYear) << "\n";
    }

    // Step 2: Generate personalized recommendations
    std::vector<std::string> userGenres = {"Action", "Drama"}; // Example user preferences
    std::vector<Video> recommendations = generateRecommendations(videos, userGenres);

    // Output personalized recommendations
    std::cout << "\nPersonalized Recommendations:\n";
    for (const auto &video : recommendations) {
        std::cout << video.title << "\n";
    }

    return 0;
}
