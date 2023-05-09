#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<string, int> inventory;
    string item;
    string line;

    while (getline(cin, line) && line != "#")
    {
        inventory[line]++;
    }

    int N;
    cin >> N;
    // cin.ignore(); // Menambahkan baris ini

    for (int i = 0; i < N; i++)
    {
        int X, M;
        cin >> X >> M;
        map<string, int> recipe;

        cin.ignore();
        for (int j = 0; j < M; j++)
        {
            string material;
            int Y;
            getline(cin, material);
            cin >> Y;
            cin.ignore();
            recipe[material] = Y;
        }

        int max_possible = X;
        for (auto it = recipe.begin(); it != recipe.end(); ++it)
        {
            max_possible = min(max_possible, inventory[it->first] / it->second);
        }

        if (max_possible == X)
        {
            for (auto it = recipe.begin(); it != recipe.end(); ++it)
            {
                inventory[it->first] -= max_possible * it->second; // inven = inven - banyak yg bisa di buat * resep
            }
            cout << "Material Fulfilled, Crafting " << X << "!" << endl;
        }
        else
        {
            cout << "Insufficient Material, Can only craft " << max_possible << "." << endl;
        }
    }

    return 0;
}
