#ifndef _0416329_HASHTABLE_H
#define _0416329_HASHTABLE_H

#include <vector>
#include <string>

using namespace std;

class Paciente
{
    public:
        Paciente()
        {
            this->gender = "";
            this->height = 0;
            this->weight = 0;
        };
        Paciente(string g, int h, int w)
        {
            this->gender = g;
            this->height = h;
            this->weight = w;
        };
        string getGender() {
            return this->gender;
        };
        int getHeight() {
            return this->height;
        };
        int getWeight() {
            return this->weight;
        };

        string gender;
        int height;
        int weight;
};

class HashTable
{
    public:
        HashTable();
        virtual ~HashTable();

        int getKey(double);
        void addItem(string, string, int, int);
        Paciente operator[](const string);
        int dup_count = 0;
    private:
        float max_tablesize;
        const double hashconst=0.618033987;
        vector<Paciente>* table;

};

#endif // HASHTABLE_H
