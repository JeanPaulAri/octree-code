#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

struct Point {
    int x,y,z;

    Point(int x, int y, int z) : x(x), y(y), z(z) {}
};

class Octree {

    private:
        Octree *children[8];
        bitset<1000> existences;
        Point *points;
        Point bottomLeft;
        double h;
        int nPoints;
    
    public:

        Octree(Point bl, double height) : bottomLeft(bl), h(height), nPoints(0){

            for(int i = 0; i < 8; i++){
                children[i] = nullptr;
            }
            points = nullptr;
        }

        bool exist(const Point &p){
            int index = p.x * 100 + p.y * 10 + p.z;
            return existences.test(index);
        }

        void insert(const Point &p){
            //caso base
            if (p.x < bottomLeft.x || p.x >= bottomLeft.x + h ||
                p.y < bottomLeft.y || p.y >= bottomLeft.y + h ||
                p.z < bottomLeft.z || p.z >= bottomLeft.z + h) {
                cout << "El punto está fuera del espacio del octree.\n";
                return;
            }   

            if(!exist(p)){
                existences.set(p.x * 100 + p.y * 10 + p.z);

                if( h<= 1.0){
                    if(points == nullptr){
                        points = new Point[1]{Point(p.x, p.y, p.z)};   
                    }else{
                        Point *newPoints = new Point[nPoints + 1];
                        for(int i = 0; i < nPoints; i++){
                            newPoints[i] = points[i];
                        }
                        newPoints[nPoints] = Point(p.x, p.y, p.z);
                        //nPoints++;
                        delete[] points;
                        points = newPoints;
                    }
                    nPoints++;
                }

            }
        }

        Point find_closest( const Point &, int radius);

}

int main(){




    return 0;
}