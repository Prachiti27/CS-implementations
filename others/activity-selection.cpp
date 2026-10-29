#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish;
};

vector<Activity> selectActivities(vector<Activity> activities) {
    sort(activities.begin(), activities.end(),
         [](const Activity& a, const Activity& b) {
             return a.finish < b.finish;
         });

    vector<Activity> selected;
    int lastFinish = -1;

    for (const Activity& a : activities) {
        if (selected.empty() || a.start >= lastFinish) {
            selected.push_back(a);
            lastFinish = a.finish;
        }
    }

    return selected;
}

int main() {
    vector<Activity> activities = {
        {1, 3}, {2, 5}, {4, 6},
        {6, 7}, {5, 8}, {8, 9}
    };

    auto selected = selectActivities(activities);

    cout << "Selected activities:\n";
    for (const auto& a : selected)
        cout << "(" << a.start << ", "
             << a.finish << ")\n";

    cout << "Maximum count: " << selected.size() << '\n';
    return 0;
}