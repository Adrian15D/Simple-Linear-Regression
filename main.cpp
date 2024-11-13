#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

class Dataset{

private:
    vector<int> advertising = {23, 26, 30, 34, 43, 48, 52, 57, 58};
    vector<int> sales = {651, 762, 856, 1063, 1190, 1298, 1421, 1440, 1518};

public:
    Dataset();
    vector<int> getDataAdv ();
    vector<int> getDataSal ();

};

Dataset::Dataset(){

}


vector<int> Dataset::getDataAdv(){
return advertising;
}

vector<int> Dataset::getDataSal(){
return sales;
}

double predict(double b1, double b0, double aAd);

int main(){

    int vAd;
    int rest = 1;
    double solucion;

    Dataset Datos;
    vector<int> advData = Datos.getDataAdv();
    vector<int> salData = Datos.getDataSal();
    //sacar el n

    size_t n = advData.size();

    //sacar sumatorias

    //X
    int sum_x = accumulate(advData.begin(), advData.end(),0);
    int sum_y = accumulate(salData.begin(), salData.end(),0);
    int sum_x_squ = accumulate(advData.begin(), advData.end(), 0, [](int acc, int val) { return acc + val * val; });
    int sum_xy = inner_product(advData.begin(), advData.end(), salData.begin(), 0);

    double beta_1 = static_cast<double>(n * sum_xy - sum_x * sum_y) / (n * sum_x_squ- sum_x * sum_x);
    double beta_0 = static_cast<double>(sum_y - beta_1 * sum_x) / n;

cout << "Ecuacion de regresion: Sales = " << beta_1 << " * Advertising + " << beta_0 << endl;


    do {
        cout << "Deseas ingresar un valor a predecir? 1 = yes, 2 = no:" << endl;
        cin >> rest;

        if (rest == 1) {
            cout << "Ingrese el valor de Advertising para predecir las ventas: " << endl;
            cin >> vAd;

            solucion = predict(beta_1, beta_0, vAd);

            cout << "Prediccion de Sales para Advertising de " << vAd << " millones: " << solucion << " millones" << endl;
        }
    } while (rest != 2);

    return 0;
}

double predict (double b1, double b0 , double aAd){

    double result = b1 * aAd + b0;

    return result;

}
