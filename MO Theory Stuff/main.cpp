#include <iostream>
#include <string>
#include <array>
#include "Vector.h"
#include "Matrix.h"

enum Group
{
	C_infinityv,
	D_infinityh,
	O_h,
	T_d,
	D_2h,
	D_3h,
	D_4h,
	D_2d,
	D_3d,
	D_4d,
	D_2,
	D_3,
	D_4,
	C_2,
	C_3,
	C_4,
	S_2,
	S_4,
	C_2h,
	C_3h,
	C_4h,
	C_2v,
	C_3v,
	C_4v,
	C_s,
	C_1,
	C_i,
};

enum Structure
{
	Linear = 2,
	Trigonal_planar,
	Tetrahedral,
	Trigonal_bipyrimidal,
	Octahedral,
};

/*
Structure obtain_structure()
{
	std::cout << "What structure do you want to use? Insert number for number of bonds: " << '\n';
	int structure_input{};
	while (true)
	{
		std::cin >> structure_input;
		if (structure_input <= 6 and structure_input >= 2)
			return static_cast<Structure>(structure_input);
		else
			std::cout << "Invalid input. Select a number from 2 to 6" << '\n';
	}
}
*/
std::ostream& operator<<(std::ostream& out, Structure structure_type)
{
	switch (structure_type)
	{
	case Linear: return out << "Linear";
	case Trigonal_planar:   return out << "Trigonal planar";
	case Tetrahedral:  return out << "Tetrahedral";
	case Trigonal_bipyrimidal: return out << "Trigonal Bipyramidal";
	case Octahedral: return out << "Octahedral";
	default:    return out << "???";
	}
}
/*
Group linear_group_identify()
{
	int a_1{ 1 }, a_2{ 1 };
	std::vector<int> vect{ a_1, a_2 };

	std::cout << "Are the atoms the same?" << '\n';
	std::string input{};
	std::cin >> input;
	if (input == "yes")
		return D_infinityh;
	else
		return C_infinityv;
}


Group trigonal_planar_group_identify(){}
Group tetrahedral_group_identify(){}
Group trigonal_bipyrimidal_group_identify(){}
Group octahedral_group_identify(){}


Group identify_group(Structure structure_type)
{
	switch (structure_type)
	{
	case Linear: return linear_group_identify();
		//case Trigonal_planar: return trigonal_planar_group_identify();
		//case Tetrahedral: return tetrahedral_group_identify();
		//case Trigonal_bipyrimidal: return trigonal_bipyrimidal_group_identify();
		//case Octahedral: return octahedral_group_identify();
	default: return Error;
	}
}
*/

Group linear(int a_1, int a_2)
{
	//Vector<2> vec{ {a_1, a_2} };
	//vec.print();
	//vec.print();
	//Matrix<2> mat{ {0, 1, 1, 0} };
	//if (mat * vec == vec)
	//	return D_infinityh;
	//else
	//	return C_infinityv;
	return C_infinityv;
}

int main()
{
	Vector<2> vec{ {1, 0} };
	vec.print();
	return 0;
}