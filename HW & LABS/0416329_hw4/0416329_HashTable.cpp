#include "0516250_HashTable.h"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>

HashTable::HashTable()
{
    this->max_tablesize=49999999;
    this->table = new vector<Paciente>(this->max_tablesize);
}

HashTable::~HashTable()
{
    //dtor
}

int HashTable::getKey(double x)
{
    return floor(max_tablesize * fmod((x*hashconst), 1));
}

void HashTable::addItem(string key, string gender, int height, int weight)
{
    int k = getKey(atoi(key.c_str()));

    this->table->at(k) = Paciente(gender, height, weight);
}

Paciente HashTable::operator[](const string key)
{
    int k = getKey(atoi(key.c_str()));
    return this->table->at(k);
}
