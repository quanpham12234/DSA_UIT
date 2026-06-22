#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

struct Pokemon {
    string name;
    string type;
    int hp;
    int attack; 
};

class Pokedex {
    private:
    int capacity;
    vector<list<Pokemon>> table;  
 
    int hashFunction(string key) {
        long long hash_val = 0;
        long long p_pow = 1;
        long long p = 31;

        for (char c : key) {
            hash_val = (hash_val + c * p_pow) % capacity;
            p_pow = (p_pow * p) % capacity;
        }

        return (hash_val % capacity + capacity) % capacity;
    }

    public:
    Pokedex(int c) {
        capacity = c;
        table.resize(capacity);
    }

    void insert(string name, string type, int hp, int attack) {
        int index = hashFunction(name);

        for (auto& pkm : table[index]) {
            if (pkm.name == name) {
                pkm.type = type;
                pkm.hp = hp;
                pkm.attack = attack;

                cout << "Da cap nhat thong tin cho " << pkm.name << "! \n";
                return;
            }
        }

        table[index].push_front({name,type,hp,attack});
        cout << "Da them Pokemon " << name << "! \n";
    }

    void search(string name) {
        int index = hashFunction(name); 

        for (auto& pkm : table[index]) {
            if (pkm.name == name) {
                cout << "\n--- THONG TIN POKEMON ---\n";
                cout << "Ten: " << pkm.name << "\n";
                cout << "He: " << pkm.type << "\n";
                cout << "HP: " << pkm.hp << " | ATK: " << pkm.attack << "\n";
                cout << "-------------------------\n";
                return;
            }
        }

        cout << "Error: Khong tim thay Pokemon " << name << "!\n";
    }

    // Hiển thị toàn bộ Pokedex để xem dữ liệu được phân bố ra sao
    void display() {
        cout << "\n=== TRANG THAI BO NHO POKEDEX ===\n";
        for (int i = 0; i < capacity; i++) {
            cout << "Khu vuc [" << i << "]: ";
            if (table[i].empty()) {
                cout << "Trong\n";
            } else {
                for (auto& pkm : table[i]) {
                    cout << "(" << pkm.name << ") -> ";
                }
                cout << "NIL\n";
            }
        }
        cout << "=================================\n\n";
    }

    void remove(string name) {
        int index = hashFunction(name);

        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (it->name == name) {
                table[index].erase(it);
                cout << "Da tha " << it->name << " ve tu nhien! \n";
                return;
            }

            cout << "Khong tim thay Pokemon " << name << "!\n";
        }
    }
};

int main() {
    Pokedex myPokedex(5);

    myPokedex.insert("Pikachu", "Electric", 35, 55);
    myPokedex.insert("Bulbasaur", "Grass/Poison", 45, 49);
    myPokedex.insert("Charmander", "Fire", 39, 52);
    myPokedex.insert("Squirtle", "Water", 44, 48);
    myPokedex.insert("Eevee", "Normal", 55, 55);

    myPokedex.display();

    myPokedex.search("Charmander");
    myPokedex.search("Mewtwo");

    myPokedex.remove("Bulbasaur");
    myPokedex.remove("Mew");

    myPokedex.display();

    return 0;
}