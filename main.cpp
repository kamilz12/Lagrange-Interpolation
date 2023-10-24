#include <iostream>

using namespace std;

double LagrangeInterpolation(int nodes, double x[], double y[], double interpolated_x);
void enterLagrangeInterpolation ();

int main() {
    return 0;
}
void enterLagrangeInterpolation (){
    int interpolation_nodes;

    cout<<"Enter nodes: ";
    cin >> interpolation_nodes;

    double x[interpolation_nodes],y[interpolation_nodes],interpolation_point;
    bool ascending = true;

    for(int i = 0; i < interpolation_nodes; i++){
        cout<<"Enter x["<<i<<"]: ";
        cin>>x[i];
        if(i>0 && x[i]<x[i-1]) ascending = false;
    }
    for(int j = 0; j < interpolation_nodes; j++){
        cout<<"Enter y["<<j<<"]: ";
        cin>>y[j];
    }
    cout<<"Set interpolation point: ";
    cin >> interpolation_point;

    if(ascending == true && interpolation_point <= x[interpolation_nodes - 1] && interpolation_point >= x[0]){
        double result = LagrangeInterpolation(interpolation_nodes, x, y, interpolation_point);
        cout << "For interpolation point: x = " << interpolation_point << "result is " << result;
    }
    else{
        cout<<"Something went wrong, wrong data";
    }

}
double LagrangeInterpolation(int nodes, double x[], double y[], double interpolated_x){
    double interpolated_y=0,term;
    for(int i=0; i < nodes; i++){
        term=1;
        for(int j=0; j < nodes; j++)
        {
            if(i!=j)
            {
                term = term * (interpolated_x - x[j]) / (x[i] - x[j]); // (x-x_0)(x-x_1)/(x_i-x_i-1) * next interpolation ingredients
            }
        }
        interpolated_y = interpolated_y + term * y[i];
    }
    return interpolated_y;
}
