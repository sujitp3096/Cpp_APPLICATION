#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class VotingSystem {
private:
    vector<string> candidates;
    unordered_map<string, bool> hasVoted;
    unordered_map<string, int> votes;

public:
    VotingSystem() {
        candidates = {"Candidate A", "Candidate B", "Candidate C"};
        for (auto &c : candidates) votes[c] = 0;
    }

    void adminPanel() {
        int choice;
        string newCandidate;

        cout << "\n----- ADMIN PANEL -----\n";
        cout << "1. View Candidates\n2. Add Candidate\n3. View Results\n4. Exit Admin\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nCurrent Candidates:\n";
            for (auto &c : candidates) cout << "- " << c << endl;
            break;

        case 2:
            cout << "Enter new candidate name: ";
            cin.ignore();
            getline(cin, newCandidate);
            candidates.push_back(newCandidate);
            votes[newCandidate] = 0;
            cout << "Candidate added successfully!\n";
            break;

        case 3:
            cout << "\n----- Current Vote Count -----\n";
            for (auto &c : candidates)
                cout << c << ": " << votes[c] << " votes\n";
            break;

        default:
            cout << "Returning...\n";
        }
    }

    void castVote() {
        string voterID;
        cout << "\nEnter your Voter ID: ";
        cin >> voterID;

        if (hasVoted[voterID]) {
            cout << "❌ You have already voted!\n";
            return;
        }

        cout << "\n----- Candidates -----\n";
        for (int i = 0; i < candidates.size(); i++)
            cout << i + 1 << ". " << candidates[i] << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice < 1 || choice > candidates.size()) {
            cout << "Invalid choice!\n";
            return;
        }

        votes[candidates[choice - 1]]++;
        hasVoted[voterID] = true;

        cout << "✔ Vote cast successfully!\n";
    }

    void showResults() {
        cout << "\n----- Final Results -----\n";
        for (auto &c : candidates)
            cout << c << ": " << votes[c] << " votes\n";
    }
};

int main() {
    VotingSystem vs;
    int choice;
    string adminPass;

    while (true) {
        cout << "\n\n===== ADVANCED VOTING SYSTEM =====\n";
        cout << "1. Admin Login\n2. Cast Vote\n3. View Results\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Admin Password: ";
            cin >> adminPass;
            if (adminPass == "admin123")
                vs.adminPanel();
            else
                cout << "❌ Wrong Password!\n";
            break;

        case 2:
            vs.castVote();
            break;

        case 3:
            vs.showResults();
            break;

        case 4:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
