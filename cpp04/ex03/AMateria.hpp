/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:01:39 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/07/12 17:16:05 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using std::cout;
using std::endl;

class ICharacter;
class AMateria;

class AMateria
{
    protected:
    std::string type;

    public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria &cpy);
    AMateria &operator=(const AMateria &eq);
    ~AMateria();
    std::string const & getType() const; //Returns the materia type
    
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

class Ice:public AMateria
{
    public:
    Ice();
    ~Ice();
    virtual void use(ICharacter& target);
    virtual Ice* clone() const; //check this line
};

class Cure:public AMateria
{
    public:
    Cure();
    ~Cure();
    virtual void use(ICharacter& target);
    virtual Cure* clone() const;
};

class ICharacter
{
    public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
    private:
    std::string Name;
    AMateria *slots[4];

    public:
    Character();
    Character(std::string Name);
    ~Character();
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};

class IMateriaSource
{
    public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
    private:
    AMateria *slots_bk[4];

    public:
    MateriaSource();
    virtual void learnMateria(AMateria*);
    virtual AMateria* createMateria(std::string const & type);
};