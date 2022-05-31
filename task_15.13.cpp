#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Matrix {

public:
    vector<vector<double> > matrix;
    int n;
    int m;
    Matrix() {}
    Matrix(int n1,int m1) {
        n=n1;
        m=m1;
    }
    Matrix(const Matrix& matrix1) {
        n=matrix1.n;
        m=matrix1.m;
        vector<double> row;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                row.push_back(matrix1.matrix[i][j]);
            }
            matrix.push_back(row);
            row.clear();
        }
    }
    void input() {
        vector<double> row;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                double item;
                cin>>item;
                row.push_back(item);
            }
            matrix.push_back(row);
            row.clear();
        }
    }
    void print(ostream& out=cout) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                out<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    double det(){
        double det = 0;
        det=matrix[0][0]*matrix[1][1]*matrix[2][2]+matrix[0][1]*
                                                   matrix[1][2]*matrix[2][0]+matrix[1][0]*matrix[2][1]*matrix[0][2]-matrix[0][2]*matrix[1][1]*matrix[2][0]
            -matrix[0][0]*matrix[2][0]*matrix[1][2]-matrix[1][0]*matrix[0][1]*matrix[2][2];
        return det;
    }
    double absM(){
        double sum=0;
        double prev_sum=0;
        for (int i=0; i<3; i++){
            prev_sum=0;
            for(int j=0; j<3; j++){
                prev_sum+=matrix[i][j];
            }
            if (prev_sum>sum){
                sum=prev_sum;
            }
        }
        return sum;
    }
    double absV(){
        double sum=0;
        double prev_sum=0;
        for (int i=0; i<n; i++){
            sum+=pow(matrix[i][0],2);
        }
        return sqrt(sum);
    }
    Matrix operator+(const Matrix& other) {
        if (n!=other.n || m!=other.m) {
            throw logic_error("These matrices can`t be added!");
        }
        Matrix sum(n,m);
        vector<double> row;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                double item;
                item=matrix[i][j]+other.matrix[i][j];
                row.push_back(item);
            }
            sum.matrix.push_back(row);
            row.clear();
        }
        return sum;
    }
    Matrix operator*(const Matrix& other) {
        if (m!=other.n) {
            throw logic_error("These matrices can`t be multiplied!");
        }
        Matrix product(n,other.m);
        vector<double> row;
        for (int i=0; i<n; i++) {
            for (int j=0; j<other.m; j++) {
                double item;
                item=0;
                for (int k=0; k<m; k++) {
                    item+=matrix[i][k]*other.matrix[k][j];
                }
                row.push_back(item);
            }
            product.matrix.push_back(row);
            row.clear();
        }
        return product;
    }

};


int main() {
    Matrix Matrix3(3,3);
    Matrix Vector3(3,1);
    Matrix3.input();
    Vector3.input();
    cout<<Matrix3.det()<<endl;
    cout<<Matrix3.absM()<<endl;
    cout<<Vector3.absV()<<endl;
    Matrix Result;
    Result=Matrix3*Vector3;
    Result.print();
    return 0;
}
