#include<iostream>
#include <fstream>
#include<vector>
#include<cmath>

using namespace std;

struct node{
    int vertex;
    double x;
    double y;
};

int main(){
    fstream p1,p2;
    int size = 2392;
    string outName = "pr2392.txt";
    int skipLines = 6;
    string line;
    vector<node> list;
    vector<vector<int>> matrix(size,vector<int>(size,0));
    p1.open("pr2392.tsp",ios::in);
    if(p1.good()){
        int i = 0;
        while(!p1.eof()){
            if(i < skipLines) {
                getline(p1, line);
                i++;
            }
            else{
                node newNode{};
                p1>>newNode.vertex;
                p1>>newNode.x;
                p1>>newNode.y;
                newNode.vertex--;
                if(newNode.vertex>=0 && newNode.vertex<size)
                    list.push_back(newNode);
            }
        }
    }
    p1.close();
    double d;
    for(int i = 0;i<size;i++)
        for(int j = 0;j < size;j++){
            if(i != j){
                d = sqrt(pow(list[j].x-list[i].x,2)+pow(list[j].y-list[i].y,2));
                matrix[i][j] = (int) d;
            }
        }
    p2.open(outName,ios::out);
    p2<<size<<endl;
    for(int i = 0;i<size;i++) {
        for (int j = 0; j < size; j++) {
            p2 << matrix[i][j] << " ";
        }
        if(i!=size-1)
            p2<<endl;
    }
    p2.close();
}