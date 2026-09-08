#include <iostream>
#include <vector>

using namespace std;

class Node {
private:    
    int id;
    bool leader;
public:
    Node(int id) : id(id), leader(false) {}
    int getId() const {
        return id;
    }
    bool isLeader() const {
        return leader;
    }
    void becomeLeader() {
        leader = true;
    }
};

class LCR {
private:
    vector<Node> nodes;
    int n;
public:
    LCR(const vector<int>& ids) {
        for(int id : ids) {
            nodes.emplace_back(id);
        }
        n = nodes.size();
    }

    void electLeader(int initiator) {
        int curr = initiator;
        int msg = nodes[initiator].getId();

        cout<<"Node "<<nodes[curr].getId()<<" starts election with ID "<<msg<<endl;

        while(true) {
            int nxt = (curr + 1) % n;
            cout<<"Node "<<nodes[curr].getId()<<" -> Node "<<nodes[nxt].getId()<<" : "<<msg<<endl;

            if(msg == nodes[nxt].getId()) {
                nodes[nxt].becomeLeader();
                cout<<"\nLeader elected: Node "<<nodes[nxt].getId()<<endl;
                break;
            }

            if(msg > nodes[nxt].getId()) {
                curr = nxt;
            }
            else {
                msg = nodes[nxt].getId();
                curr = nxt;
            }
        }
    }

    void printNodes() const {
        cout<<"\nFinal State: "<<endl;
        for(const auto& node:nodes) {
            cout<<"Node "<<node.getId();
            if(node.isLeader()) {
                cout<<" -> LEADER";
            }
            cout<<endl;
        }
    }
};

int main() {
    vector<int> ids = {10, 25, 7, 30, 15};
    LCR election(ids);
    election.electLeader(2);
    election.printNodes();
}