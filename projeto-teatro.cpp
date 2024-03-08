#include <iostream>
#include <iomanip>

using namespace std;

const int TOTAL_FILEIRAS = 15;
const int POLTRONAS_POR_FILEIRA = 40;

char teatro[TOTAL_FILEIRAS][POLTRONAS_POR_FILEIRA];
double precos[TOTAL_FILEIRAS];

void inicializarTeatro() {
    for (int i = 0; i < TOTAL_FILEIRAS; ++i) {
        for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
            teatro[i][j] = '.';
        }
    }

    for (int i = 0; i < TOTAL_FILEIRAS; ++i) {
        if (i < 5) {
            precos[i] = 50.0;
        } else if (i < 10) {
            precos[i] = 30.0;
        } else {
            precos[i] = 15.0;
        }
    }
}

void mostrarMapa() {
    cout << "Mapa de Ocupacao do Teatro:" << endl;
    for (int i = 0; i < TOTAL_FILEIRAS; ++i) {
        for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
            cout << teatro[i][j] << " ";
        }
        cout << endl;
    }
}

void realizarReserva() {
    int fileira, poltrona;

    cout << "Informe a fileira (1-" << TOTAL_FILEIRAS << "): ";
    cin >> fileira;

    cout << "Informe a poltrona (1-" << POLTRONAS_POR_FILEIRA << "): ";
    cin >> poltrona;

    if (fileira < 1 || fileira > TOTAL_FILEIRAS || poltrona < 1 || poltrona > POLTRONAS_POR_FILEIRA) {
        cout << "Valores de fileira ou poltrona inválidos." << endl;
        return;
    }

    fileira--;
    poltrona--;

    if (teatro[fileira][poltrona] == '.') {
        teatro[fileira][poltrona] = '#';
        cout << "Reserva realizada com sucesso!" << endl;
    } else {
        cout << "Lugar já ocupado. Escolha outro lugar." << endl;
    }
}

void calcularFaturamento() {
    int lugaresOcupados = 0;
    float valorBilheteria = 0.0;

    for (int i = 0; i < TOTAL_FILEIRAS; ++i) {
        for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
            if (teatro[i][j] == '#') {
                lugaresOcupados++;
                valorBilheteria += precos[i];
            }
        }
    }

    cout << "Quantidade de lugares ocupados: " << lugaresOcupados << endl;
    cout << fixed << setprecision(2);
    cout << "Valor da bilheteria: R$ " << valorBilheteria << endl;
}

int main() {
    inicializarTeatro();

    int opcao;

    do {
        cout << "\nSelecione uma opcao:" << endl;
        cout << "0. Finalizar" << endl;
        cout << "1. Reservar poltrona" << endl;
        cout << "2. Mapa de ocupacao" << endl;
        cout << "3. Faturamento" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Programa encerrado." << endl;
                break;
            case 1:
                realizarReserva();
                break;
            case 2:
                mostrarMapa();
                break;
            case 3:
                calcularFaturamento();
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
                break;
        }

    } while (opcao != 0);

    return 0;
}
