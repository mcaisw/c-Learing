// Timing Code Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <chrono>
#include <iostream>
#include <array>
#include <algorithm>
#include "Point2D.h"
#include <string>
class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

const int g_arrayElements = 10000;
void sortArray(std::array<int, g_arrayElements> &array)
{

	// Step through each element of the array
	// (except the last one, which will already be sorted by the time we get there)
	for (int startIndex = 0; startIndex < g_arrayElements - 1; ++startIndex)
	{
		// smallestIndex is the index of the smallest element we’ve encountered this iteration
		// Start by assuming the smallest element is the first element of this iteration
		int smallestIndex = startIndex;

		// Then look for a smaller element in the rest of the array
		for (int currentIndex = startIndex + 1; currentIndex < g_arrayElements; ++currentIndex)
		{
			// If we've found an element that is smaller than our previously found smallest
			if (array[currentIndex] < array[smallestIndex])
				// then keep track of it
				smallestIndex = currentIndex;
		}

		// smallestIndex is now the smallest element in the remaining array
		// swap our start element with our smallest element (this sorts it into the correct place)
		std::swap(array[startIndex], array[smallestIndex]);
	}
}


class HelloWorld
{
private:
	char *m_data;

public:
	HelloWorld()
	{
		m_data = new char[14];
		const char *init = "Hello, World!";
		for (int i = 0; i < 14; ++i)
			m_data[i] = init[i];
	}

	~HelloWorld()
	{
		// replace this comment with your destructor implementation
		delete[] m_data;
	}

	void print()
	{
		std::cout << m_data;
	}

};


class Monster {
public:
enum MonsterType {
	Dragon, 
	Goblin, 
	Ogre, 
	Orc, 
	Skeleton, 
	Troll, 
	Vampire, 
	Zombie,
	MAX_MONSTER_TYPES
};
Monster(MonsterType type,std::string name,std::string roar,int hitPoint) 
	:m_type(type), m_name(name), m_roar(roar), m_hitPoint(hitPoint)
{

}

private:
	MonsterType m_type;
	std::string m_name;
	std::string m_roar;
	int m_hitPoint;

	std::string getTypeString() {
		switch (m_type)
		{
		case Monster::Dragon:
			return "Dragon";
		case Monster::Goblin:
			return "Goblin";
		case Monster::Ogre:
			return "Ogre";
		case Monster::Orc:
			return "Orc";
		case Monster::Skeleton:
			return "Skeleton";
		case Monster::Troll:
			return "Troll";
		case Monster::Vampire:
			return "Vampire";
		case Monster::Zombie:
			return "Zombie";
		}
		return "???";
	}
public:
	void Print() {
		std::cout <<  m_name << " the " << getTypeString() << " has " << m_hitPoint << " hit points and says " << m_roar << '\n';
	}
};


int main()
{

	/*--------arrangement-----------*/
	/*std::array<int, g_arrayElements> array;
	for (int i = 0; i < g_arrayElements; ++i)
		array[i] = g_arrayElements - i;

	Timer t;

	std::sort(array.begin(), array.end());

	std::cout << "Time taken: " << t.elapsed() << '\n';*/

	/*----------Orient-Object Coding Test---------------*/
	/*Point2D first;
	Point2D second(3.0f, 4.0f);
	first.Print();
	second.Print();
	std::cout << "Distance Between Two Points:\n" << first.distanceTo(second)<<"\n";*/

	/*-----------destructor-------------*/
	/*HelloWorld hello;
	hello.print();
	return 0;*/
	 
	/*-------------Monster Class Test--------------------*/
	Monster skele(Monster::Skeleton, "Bones", "*rattle*", 4);
	skele.Print();
	return 0;
}


