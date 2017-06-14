//WoC 33: transform to palindrom

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class node{
public:
	int val;
	vector<int> replacements;

	void initIT(int x){
        cout << "Created node " << x << endl;
		val = x;
	}

	void addNode(node n){
        cout << "Adding " << n.val << " to node " << val << endl;
		//if this number isn't already included in this node's replacements, add it
		if(find(replacements.begin(),replacements.end(),n.val) == replacements.end()){
			replacements.push_back(n.val);
			cout << "\tAdding " << n.val << " to above node...\n";
			//then, if the node added has replacement, by transititive property, try to add them
			if(!n.replacements.empty()){
				for(int i = 0; i < n.replacements.size(); i++){
					if(n.replacements[i] != val){
                        cout << "\t\tAdding " << n.val << " to above node...\n";
						this->replacements.push_back(n.replacements[i]);
					}
				}
			}
		}
	}

	void printInfo(){
		cout << val + "--> ";
		for(int i = 0; i < replacements.size(); i++){
			cout << replacements[i] << " ";
		}
		cout << endl;
	}
};

int main() {
    int n;
    int k;
    int m;

    vector<node> myNodes;
    vector<int> myVals;

    cin >> n >> k >> m;
    for(int a0 = 0; a0 < k; a0++){
        int x;
        int y;
        cin >> x >> y;

        // if(a0 == 0){
        // 	myVals.push_back(x);
        // 	myVals.push_back(x);

        // }

        node xNode, yNode;
        xNode.initIT(x);
        yNode.initIT(y);
        
        if(find(myVals.begin(), myVals.end(), x) == myVals.end()){
        	myVals.push_back(x);
        	myNodes.push_back(xNode);
        	myNodes[a0].addNode(yNode);
        }
        
        if(find(myVals.begin(), myVals.end(), y) == myVals.end()){
            myVals.push_back(y);
        	myNodes.push_back(yNode);
        	myNodes[a0 + 1].addNode(xNode);
        }

    }
    vector<int> a(m);
    for(int a_i = 0; a_i < m; a_i++){
       cin >> a[a_i];
    }
    for(int a_i = 0; a_i < m; a_i++){
       myNodes[a_i].printInfo();
    }


    return 0;
}