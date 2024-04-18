/* 
 * Description: This C++ program generates a list of competitors for different races based on predefined names, countries, and race types.
 * It uses a structure to represent each competitor and fills an array with randomly selected competitors for each race.
 * The program then prints out the list of competitors for each race.
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

const int NUM_PER_RACE = 8;
const int TOTAL_RACES = 4;
const int TOTAL_COMPETITORS = NUM_PER_RACE * TOTAL_RACES;

// Define structure for competitor
struct Competitor {
    string name;
    string country;
    string race;
};

// Define arrays for names, countries, and races
string male_names[16] = {"Adam Smith", "Benjamin Jones", "Charles Brown", "David Lee",
                        "Edward Davis", "Frank Wilson", "George Taylor", "Henry Jackson",
                        "Isaac Garcia", "James Martinez", "Kevin Hernandez", "Liam Nguyen",
                        "Mason Perez", "Noah Kim", "Oliver Lee", "William Chang"};
string female_names[16] = {"Abigail Johnson", "Bella Hernandez", "Charlotte Kim", "Emily Martinez",
                          "Fiona Lee", "Grace Perez", "Hannah Nguyen", "Isabella Kim",
                          "Jessica Rodriguez", "Katherine Kim", "Lila Lee", "Madison Lopez",
                          "Natalie Davis", "Olivia Lee", "Penelope Kim", "Quinn Rodriguez"};
string countries[8] = {"France", "Germany", "Italy", "Spain", "Netherlands", "Sweden", "Norway", "Denmark"};
string races[4] = {"Man-100m", "Woman-100m", "Man-400m", "Woman-400m"};

// Function to shuffle an array
void shuffleArray(string *array, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(array[i], array[j]);
    }
}

// Function to print competitors for a race
void printCompetitors(Competitor *competitors, string race) {
    cout << "Competitors for " << race << ":" << endl;
    for (int i = 0; i < NUM_PER_RACE; i++) {
        cout << competitors[i].name << " from " << competitors[i].country << endl;
    }
    cout << endl;
}

int main() {
    srand(time(NULL)); // Seed random number generator

    // Array of Competitor structures
    Competitor all_competitors[TOTAL_COMPETITORS];

    // Fill array with competitors
    int index = 0;
    for (int r = 0; r < TOTAL_RACES; r++) {
        shuffleArray(male_names, 16);
        shuffleArray(female_names, 16);
        shuffleArray(countries, 8);
        for (int i = 0; i < NUM_PER_RACE; i++) {
            all_competitors[index].name = (r % 2 == 0) ? male_names[i] : female_names[i];
            all_competitors[index].country = countries[i];
            all_competitors[index].race = races[r];
            index++;
        }
    }

    // Print competitors for each race
    for (int r = 0; r < TOTAL_RACES; r++) {
        printCompetitors(&all_competitors[r * NUM_PER_RACE], races[r]);
    }

    return 0;
}
