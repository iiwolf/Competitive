#include <bits/stdc++.h>

using namespace std;

double pixelDistance(double x1, double y1, double x2, double y2){
	double xTerm = pow(x1 - x2,2);
	double yTerm = pow(y1 - y2,2);
	double d = sqrt(xTerm + yTerm);

	return d;
}

bool withinSquare(int x, int y, vector<double> bounds){
	
	if(x >= bounds[0] && x <= bounds[1]
		&& y >= bounds[2] && y <= bounds[3]){
			return true;
		}
		
	return false;
}

int lineEquation(int slope, int b, int x){
	return slope*x + b;
}
int main(){
    int w;
    int h;
    cin >> w >> h;
    int circleX;
    int circleY;
    int r;
    cin >> circleX >> circleY >> r;
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
	
    cin >> x1 >> y1 >> x3 >> y3;
    // your code goes here
	
	//make first point always farthest left
	if(x1 > x3){
		int tempx = x3;
		int tempy = y3;
		x3 = x1;
		y3 = y1;
		x1 = tempx;
		y1 = tempy;
	}
	double ydif = y3 - y1;
	double xdif = x3 - x1;
	
	double theta = -atan(ydif/xdif);
	double alpha1 = theta - 45*(3.14159/180);
	double alpha2 = 45*(3.14159/180) + theta;
	
	double crossDistance = pixelDistance(x1,y1,x3,y3);
	double sideDistance = crossDistance/sqrt(2);
	cout << "Side Distance: " << sideDistance << endl;
	cout << "Square theta: " << theta << endl;
	cout << "Corresponding alpha1: " << alpha1*180/3.14159 << endl;
    cout << "Corresponding alpha2: " << alpha2*180/3.14159 << endl;
	
	x2 = (int)ceil(x1 + sideDistance*cos(alpha1));
	y2 = (int)ceil(y1 + sideDistance*sin(alpha1));
	x4 = (int)ceil(x1 + sideDistance*cos(alpha2));
	y4 = (int)ceil(y1 + sideDistance*sin(alpha2));
	
    cout << "Point 1: " << x1 << "," << y1 << endl; 
	cout << "Point 2: " << x2 << "," << y2 << endl;
    cout << "Point 3: " << x3 << "," << y3 << endl;
	cout << "Point 4: " << x4 << "," << y4 << endl;
	
    cout << y4 << " - " << y1 << " = " << (y4-y1) << endl;
    cout << x4 << " - " << x1 << " = " << (x4-x1) << endl;
    cout << "So that the slope is...";
	double slope12 = (y2 - y1)/(x2 - x1);
	double slope14 = (double)(y4 - y1)/(x4 - x1);
	double slope23 = (y3 - y2)/(x3 - x2);
	double slope43 = (y3 - y4)/(x3 - x4);
	
	cout << "slope14: " << slope14 << endl;
	
	vector<int> xPoints = {x1,x2,x3,x4};
	vector<int> yPoints = {y1,y2,y3,y4};

cout << "slope12: " << slope12 << endl;
	vector<string> postPrint;
	

	
	for(int my = 0; my < h + 10; my++){
		for(int mx = 0; mx < w + 10; mx++){
			
			double x = (double)mx;
			double y = (double)my;
			double top = slope12*(x - x1) + y1;
			double bottom = slope14*(x - x1) + y1;
			
            if(mx == 12 && my == 17){
			string str = "Top barrier is " + to_string(top) + "\t" + "and lower " + to_string(bottom);
			postPrint.push_back(str);
            }
			if(x == x2 && y == y2){
				cout << "2";
			}
			else if(x == x4 && y == y4){
				cout << "4";
			}
			else if(y == circleY && x == circleX){
                cout << "C";
            }
			else if(pixelDistance(x, y, circleX, circleY) <= r){
				cout << "C"; 
			}
            else if((x == x1 && y == y1)
					|| (x == x3 && y == y3)){
				cout << "S";
            }
			else if(y >= slope12*(x - x1) + y1
					&& y <= slope14*(x - x1) + y1){
				cout << "X";
			}
            else{
            cout << ".";
            }
			
        }
		cout << endl;
	}
	
	for(int i = 0; i < postPrint.size(); i++){
		cout << postPrint[i] << endl;
	}
    return 0;
}
