#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class Vote {
    YES,
    NO
};

enum class Decision {
    COMMIT,
    ABORT
};

class Participant {
private:
    int id;
    bool canCommit;
    string state;
public:
    Participant(int id, bool canCommit) : id(id), canCommit(canCommit), state("INIT") {}
    Vote prepare() {
        cout << "Participant " << id << ": PREPARE received\n";
        if (canCommit) {
            state = "PREPARED";
            cout << "Participant " << id << ": YES\n";
            return Vote::YES;
        }
        state = "ABORTED";
        cout << "Participant " << id << ": NO\n";
        return Vote::NO;
    }
    void commit() {
        if (state == "PREPARED") {
            state = "COMMITTED";
            cout << "Participant " << id << ": COMMITTED\n";
        }
    }
    void abort() {
        state = "ABORTED";
        cout << "Participant " << id << ": ABORTED\n";
    }
    void printState() const {
        cout << "Participant " << id << " -> " << state << '\n';
    }
};

class Coordinator {
private:
    vector<Participant*> participants;
public:
    void addParticipant(Participant* participant) {
        participants.push_back(participant);
    }
    void executeTransaction() {
        cout << "\n========== PHASE 1 ==========\n";
        bool allPrepared = true;
        for (auto participant : participants) {
            Vote vote = participant->prepare();
            if (vote == Vote::NO) {
                allPrepared = false;
            }
        }
        cout << "\nPHASE 2\n";
        if (allPrepared) {
            cout << "Coordinator: GLOBAL COMMIT\n";
            for (auto participant : participants) {
                participant->commit();
            }
        } else {
            cout << "Coordinator: GLOBAL ABORT\n";
            for (auto participant : participants) {
                participant->abort();
            }
        }
        cout << "\nFINAL STATE\n";
        for (auto participant : participants) {
            participant->printState();
        }
    }
};

int main() {

    Coordinator coordinator;

    Participant p1(1, true);
    Participant p2(2, true);
    Participant p3(3, true);

    coordinator.addParticipant(&p1);
    coordinator.addParticipant(&p2);
    coordinator.addParticipant(&p3);

    coordinator.executeTransaction();

    return 0;
}