/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:23:31 by aggrigor          #+#    #+#             */
/*   Updated: 2024/10/06 14:35:53 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < MAX_MATERIAS_CNT; i++)
		known_materias[i] = NULL;
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < MAX_MATERIAS_CNT; i++)
	{
		if (other.known_materias[i] != NULL)
			known_materias[i] = other.known_materias[i]->clone();
		else
			known_materias[i] = NULL;
	}
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

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this == &other)
		return (*this);
	for (int i = 0; i < MAX_MATERIAS_CNT; i++)
	{
		if (known_materias[i] != NULL)
			delete known_materias[i];
		if (other.known_materias[i] != NULL)
			known_materias[i] = other.known_materias[i]->clone();
		else
			known_materias[i] = NULL;
	}
	std::cout << "MateriaSource constructor called" << std::endl;
	return (*this);
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
