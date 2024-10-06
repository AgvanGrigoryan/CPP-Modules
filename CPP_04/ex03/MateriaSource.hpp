#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define MAX_MATERIAS_CNT 4

class MateriaSource : public IMateriaSource {
private:
	AMateria* known_materias[MAX_MATERIAS_CNT];

public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	virtual ~MateriaSource();

	MateriaSource& operator=(const MateriaSource& other);
	virtual void learnMateria(AMateria* new_materia);
	virtual AMateria* createMateria(std::string const & type);
};

#endif