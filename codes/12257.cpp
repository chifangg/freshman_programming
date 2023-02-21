#include<iostream>
#include"function.h"

Animal::Animal(Zoo *zoo, string name)//:belong(zoo), species(name)////////////
{
	belong = zoo;
	species = name;
	zoo -> born(name);
}
Dog::Dog(Zoo *zoo) :Animal(zoo , "Dog")////////////
{
	
}
Dog::~Dog()// TODO
{
	
}
Cat::Cat(Zoo *zoo) :Animal(zoo , "Cat")// TODO
{
	
}
Cat::~Cat() // TODO
{
	
}
Caog::Caog(Zoo *zoo):Animal(zoo , "Caog"), Dog(zoo), Cat(zoo) // TODO
{

}
void Caog::barking() // TODO
{
	cout << "woof!woof!meow!\n";
}
void Caog::carton()          // TODO
{
	cout << "it looks so happy!\n";
}
void Caog::throwBall()    // TODO
{
	cout << "it looks happy!\n"; 
}
Caog::~Caog()               // TODO
{
	
}
