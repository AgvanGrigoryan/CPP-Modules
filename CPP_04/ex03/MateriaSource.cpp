#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < MAX_MATERIAS_CNT; i++)
		known_materias[i] = NULL;
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < MAX_MATERIAS_CNT; i++)
	{
		if (known_materias[i] != NULL)
			delete known_materias[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* new_materia) {
	for (int i = 0; i < MAX_MATERIAS_CNT; i++)
	{
		if (known_materias[i] == NULL)
		{
			known_materias[i] = new_materia;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < MAX_MATERIAS_CNT; i++)
	{
		if (known_materias[i] != NULL
			&& known_materias[i]->getType() == type)
			return (known_materias[i]->clone());
	}
	return (NULL);
}
