#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : count(0)
{
    for (int i = 0; i < 4; ++i)
        storage[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) : count(other.count)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.storage[i])
            storage[i] = other.storage[i]->clone();
        else
            storage[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            delete storage[i];
            if (other.storage[i])
                storage[i] = other.storage[i]->clone();
            else
                storage[i] = NULL;
        }
        count = other.count;
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        delete storage[i];
    }
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (count < 4 && m)
    {
        storage[count] = m;
        count++;
    }
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
    for (int i = 0; i < count; ++i)
    {
        if (storage[i] && storage[i]->getType() == type)
        {
            return storage[i]->clone();
        }
    }
    return NULL;
}
