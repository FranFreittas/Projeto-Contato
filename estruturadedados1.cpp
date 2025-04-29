#include <iostream>
#include <string>
#include <ctime> 
using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;
public:
    Data() : dia(1), mes(1), ano(1900) {} 

    Data(int d, int m, int a) : dia(d), mes(m), ano(a) {} 

    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAno() const { return ano; }

    void setDia(int d) { dia = d; }
    void setMes(int m) { mes = m; }
    void setAno(int a) { ano = a; }

    static int getAnoAtual() {
        time_t tempo = time(0);
        tm* agora = localtime(&tempo);
        return agora->tm_year + 1900;
    }
};

class Contato {
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;
public:
    Contato() : email(""), nome(""), telefone(""), dtnasc() {} // Construtor padrão

    Contato(string e, string n, string t, Data d) 
        : email(e), nome(n), telefone(t), dtnasc(d) {} // Construtor com parâmetros

    string getEmail() const { return email; }
    string getNome() const { return nome; }
    string getTelefone() const { return telefone; }
    Data getDataNascimento() const { return dtnasc; }

    void setEmail(const string& e) { email = e; }
    void setNome(const string& n) { nome = n; }
    void setTelefone(const string& t) { telefone = t; }
    void setDataNascimento(const Data& d) { dtnasc = d; }

    int idade() const {
        int anoAtual = Data::getAnoAtual();
        return anoAtual - dtnasc.getAno();
    }
};

int main() {
    Contato contatos[5];

    cout << "Cadastro de 5 contatos\n";

    for (int i = 0; i < 5; ++i) {
        string nome, email, telefone;
        int dia, mes, ano;

        cout << "\nContato " << i + 1 << ":\n";
        cout << "Nome: ";
        getline(cin, nome);

        cout << "Email: ";
        getline(cin, email);

        cout << "Telefone: ";
        getline(cin, telefone);

        cout << "Data de Nascimento (dia mes ano): ";
        cin >> dia >> mes >> ano;
        cin.ignore(); 

        Data dataNasc(dia, mes, ano);
        contatos[i] = Contato(email, nome, telefone, dataNasc);
    }

    cout << "\nExibindo contatos cadastrados:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "\nContato " << i + 1 << ":\n";
        cout << "Nome: " << contatos[i].getNome() << endl;
        cout << "Email: " << contatos[i].getEmail() << endl;
        cout << "Telefone: " << contatos[i].getTelefone() << endl;
        cout << "Idade: " << contatos[i].idade() << " anos\n";
    }

    return 0;
}
