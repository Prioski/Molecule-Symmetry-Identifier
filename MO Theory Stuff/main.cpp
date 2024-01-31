#include <iostream>
#include <string>
#include <array>
#include "Vector.h"
#include "Matrix.h"
#include "Header.h"
#include "Window.h"

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

const std::wstring wGroupName(Group pointGroup)
{
	switch (pointGroup)
	{
	case C_infinityv: return L"C_infinityv";
	case D_infinityh:   return L"D_infinityh";
	case O_h:  return L"O_h";
	case T_d: return L"T_d";
	case D_2h: return L"D_2h";
	case D_3h: return L"D_3h";
	case D_4h: return L"D_4h";
	case D_2d: return L"D_2d";
	case D_3d: return L"D_3d";
	case D_4d: return L"D_4d";
	case D_2: return L"D_2";
	case D_3: return L"D_3";
	case D_4: return L"D_4";
	case C_1: return L"C_1";
	case C_2: return L"C_2";
	case C_3: return L"C_3";
	case C_4: return L"C_4";
	case S_2: return L"S_2";
	case S_4: return L"S_4";
	case C_2h: return L"C_2h";
	case C_3h: return L"C_3h";
	case C_4h: return L"C_4h";
	case C_2v: return L"C_2v";
	case C_3v: return L"C_3v";
	case C_4v: return L"C_4v";
	case C_s: return L"C_s";
	case C_i: return L"C_i";
	}
}



std::ostream& operator<<(std::ostream& out, Group group_type)
{
	switch (group_type)
	{
	case C_infinityv: return out << "C_infinityv";
	case D_infinityh:   return out << "D_infinityh";
	case O_h:  return out << "O_h";
	case T_d: return out << "T_d";
	case D_2h: return out << "D_2h";
	case D_3h: return out << "D_3h";
	case D_4h: return out << "D_4h";
	case D_2d: return out << "D_2d";
	case D_3d: return out << "D_3d";
	case D_4d: return out << "D_4d";
	case D_2: return out << "D_2";
	case D_3: return out << "D_3";
	case D_4: return out << "D_4";
	case C_1: return out << "C_1";
	case C_2: return out << "C_2";
	case C_3: return out << "C_3";
	case C_4: return out << "C_4";
	case S_2: return out << "S_2";
	case S_4: return out << "S_4";
	case C_2h: return out << "C_2h";
	case C_3h: return out << "C_3h";
	case C_4h: return out << "C_4h";
	case C_2v: return out << "C_2v";
	case C_3v: return out << "C_3v";
	case C_4v: return out << "C_4v";
	case C_s: return out << "C_s";
	case C_i: return out << "C_i";
	default:    return out << "???";
	}
}

std::ostream& operator<<(std::ostream& out, Structure structure_type)
{
	switch (structure_type)
	{
	case Linear: return out << "Linear";
	case Trigonal_planar:   return out << "Trigonal planar";
	case Tetrahedral:  return out << "Tetrahedral";
	case Trigonal_bipyramidal: return out << "Trigonal Bipyramidal";
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
	case Trigonal_planar: return trigonal_planar_group_identify();
	case Tetrahedral: return tetrahedral_group_identify();
	case Trigonal_bipyrimidal: return trigonal_bipyrimidal_group_identify();
	case Octahedral: return octahedral_group_identify();
	default: return Error;
	}
}
*/

Group octahedral_identifier(Vector<6> vec)
{
	Matrix<6> mat_c4_1{ {1, 0, 0, 0, 0, 0,
					     0, 0, 1, 0, 0, 0,
					     0, 0, 0, 1, 0, 0,
					     0, 0, 0, 0, 1, 0,
					     0, 1, 0, 0, 0, 0,
					     0, 0, 0, 0, 0, 1} };
	Matrix<6> mat_c4_2{ {0, 0, 0, 0, 1, 0,
						 0, 1, 0, 0, 0, 0,
						 1, 0, 0, 0, 0, 0,
						 0, 0, 0, 1, 0, 0,
						 0, 0, 0, 0, 0, 1,
						 0, 0, 1, 0, 0, 0} };
	Matrix<6> mat_c4_3{ {0, 1, 0, 0, 0, 0,
						 0, 0, 0, 0, 0, 1,
						 0, 0, 1, 0, 0, 0,
						 1, 0, 0, 0, 0, 0,
						 0, 0, 0, 0, 1, 0,
						 0, 0, 0, 1, 0, 0} };
	Matrix<6> mat_c3_134{ {0, 0, 1, 0, 0, 0,
						   0, 0, 0, 0, 0, 1,
						   0, 0, 0, 1, 0, 0,
						   1, 0, 0, 0, 0, 0,
						   0, 1, 0, 0, 0, 0,
		                   0, 0, 0, 0, 1, 0} };
	Matrix<6> mat_c3_123{ {0, 1, 0, 0, 0, 0,
						   0, 0, 1, 0, 0, 0,
						   1, 0, 0, 0, 0, 0,
						   0, 0, 0, 0, 1, 0,
						   0, 0, 0, 0, 0, 1,
						   0, 0, 0, 1, 0, 0} };
	Matrix<6> mat_c3_125{ {0, 1, 0, 0, 0, 0,
						   0, 0, 0, 0, 1, 0,
						   0, 0, 0, 0, 0, 1,
						   0, 0, 1, 0, 0, 0,
						   1, 0, 0, 0, 0, 0,
						   0, 0, 0, 1, 0, 0} };
	Matrix<6> mat_c2_1{ {1, 0, 0, 0, 0, 0,
						 0, 0, 0, 1, 0, 0,
						 0, 0, 0, 0, 1, 0,
						 0, 1, 0, 0, 0, 0,
						 0, 0, 1, 0, 0, 0,
						 0, 0, 0, 0, 0, 1} };
	Matrix<6> mat_c2_2{ {0, 0, 0, 0, 0, 1,
						 0, 1, 0, 0, 0, 0,
						 0, 0, 0, 0, 1, 0,
						 0, 0, 0, 1, 0, 0,
						 0, 0, 1, 0, 0, 0,
						 1, 0, 0, 0, 0, 0} };
	Matrix<6> mat_c2_3{ {0, 0, 0, 0, 0, 1,
						 0, 0, 0, 1, 0, 0,
						 0, 0, 1, 0, 0, 0,
						 0, 1, 0, 0, 0, 0,
						 0, 0, 0, 0, 1, 0,
						 1, 0, 0, 0, 0, 0} };
	Matrix<6> mat_c2_12{ {0, 1, 0, 0, 0, 0,
						  1, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 1, 0,
						  0, 0, 0, 0, 0, 1,
						  0, 0, 1, 0, 0, 0,
						  0, 0, 0, 1, 0, 0} };
	Matrix<6> mat_c2_13{ {0, 0, 1, 0, 0, 0,
						  0, 0, 0, 1, 0, 0,
						  1, 0, 0, 0, 0, 0,
						  0, 1, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 1,
						  0, 0, 0, 0, 1, 0} };
	Matrix<6> mat_c2_14{ {0, 0, 0, 1, 0, 0,
						  0, 0, 0, 0, 0, 1,
						  0, 0, 0, 0, 1, 0,
						  1, 0, 0, 0, 0, 0,
						  0, 0, 1, 0, 0, 0,
						  0, 1, 0, 0, 0, 0} };
	Matrix<6> mat_c2_23{ {0, 0, 0, 0, 0, 1,
						  0, 0, 1, 0, 0, 0,
						  0, 1, 0, 0, 0, 0,
						  0, 0, 0, 0, 1, 0,
						  0, 0, 0, 1, 0, 0,
						  1, 0, 0, 0, 0, 0} };
	Matrix<6> mat_c2_25{ {0, 0, 0, 0, 0, 1,
						  0, 0, 0, 0, 1, 0,
						  0, 0, 0, 1, 0, 0,
						  0, 0, 1, 0, 0, 0,
						  0, 1, 0, 0, 0, 0,
						  1, 0, 0, 0, 0, 0} };
	Matrix<6> mat_i{ {0, 0, 0, 0, 0, 1,
					  0, 0, 0, 1, 0, 0,
					  0, 0, 0, 0, 1, 0,
					  0, 1, 0, 0, 0, 0,
					  0, 0, 1, 0, 0, 0,
					  1, 0, 0, 0, 0, 0} };
	if (mat_c4_1 * vec == vec and mat_c4_2 * vec == vec)
		return O_h;
	else if (mat_c4_1 * vec == vec or mat_c4_2 * vec == vec or mat_c4_3 * vec == vec)
	{
		if (mat_i * vec == vec)
			return D_4h;
		else
			return C_4v;
	}
	else if (mat_c3_123 * vec == vec or mat_c3_125 * vec == vec or mat_c3_134 * vec == vec)
		return C_3v;
	else if (mat_c2_12 * vec == vec or mat_c2_13 * vec == vec or mat_c2_14 * vec == vec or mat_c2_23 * vec == vec or mat_c2_25 * vec == vec)
		return C_2v;
	else if (mat_c2_1 * vec == vec or mat_c2_2 * vec == vec or mat_c2_3 * vec == vec)
	{
		if (mat_i * vec == vec)
			return C_2h;
		else
			return C_2v;
	}
	else
		return C_1;

	/*
	if (mat_c4_1 * vec == vec and mat_c4_2 * vec == vec)
		return O_h;
	else
	{
		if (mat_c4_1 * vec == vec or mat_c4_2 * vec == vec or mat_c4_3 * vec == vec)
		{
			if (mat_i * vec == vec)
				return D_4h;
			else
				return C_4v;
		}
		else
		{
			if (mat_c3_123 * vec == vec or mat_c3_125 * vec == vec or mat_c3_134 * vec == vec)
				return C_3v;
			else
			{
				if (mat_c2_12 * vec == vec or mat_c2_13 * vec == vec or mat_c2_14 * vec == vec or mat_c2_23 * vec == vec or mat_c2_25 * vec == vec)
					return C_2v;
				else
				{
					if (mat_c2_1 * vec == vec or mat_c2_2 * vec == vec or mat_c2_3 * vec == vec)
					{
						if (mat_i * vec == vec)
							return C_2h;
						else
							return C_2v;
					}
					else
						return C_1;
				}
			}
		}
	}
	*/
}

Group trigonal_bipyramidal_identifier(Vector<5> vec)
{
	Matrix<5> mat_c3_1{ {1, 0, 0, 0, 0,
						 0, 0, 1, 0, 0,
						 0, 0, 0, 1, 0,
						 0, 1, 0, 0, 0,
						 0, 0, 0, 0, 1} };
	Matrix<5> mat_c2_2{ {0, 0, 0, 0, 1,
						 0, 1, 0, 0, 0,
						 0, 0, 0, 1, 0,
						 0, 0, 1, 0, 0,
						 1, 0, 0, 0, 0} };
	Matrix<5> mat_c2_3{ {0, 0, 0, 0, 1,
						 0, 0, 0, 1, 0,
						 0, 0, 1, 0, 0,
						 0, 1, 0, 0, 0,
						 1, 0, 0, 0, 0} };
	Matrix<5> mat_c2_4{ {0, 0, 0, 0, 1,
						 0, 0, 1, 0, 0,
						 0, 1, 0, 0, 0,
						 0, 0, 0, 1, 0,
						 1, 0, 0, 0, 0} };
	Matrix<5> mat_s_125{ {1, 0, 0, 0, 0,
						  0, 1, 0, 0, 0,
						  0, 0, 0, 1, 0,
						  0, 0, 1, 0, 0,
						  0, 0, 0, 0, 1} };
	Matrix<5> mat_s_135{ {1, 0, 0, 0, 0,
						  0, 0, 0, 1, 0,
						  0, 0, 1, 0, 0,
						  0, 1, 0, 0, 0,
						  0, 0, 0, 0, 1} };
	Matrix<5> mat_s_145{ {1, 0, 0, 0, 0,
						  0, 0, 1, 0, 0,
						  0, 1, 0, 0, 0,
						  0, 0, 0, 1, 0,
						  0, 0, 0, 0, 1} };
	Matrix<5> mat_s_234{ {0, 0, 0, 0, 1,
						  0, 1, 0, 0, 0,
						  0, 0, 1, 0, 0,
						  0, 0, 0, 1, 0,
						  1, 0, 0, 0, 0} };
	if (mat_c3_1 * vec == vec and mat_c2_2 * vec == vec)
		return D_3h;
	else if (mat_c3_1 * vec == vec)
		return C_3v;
	else if (mat_c2_2 * vec == vec or mat_c2_3 * vec == vec or mat_c2_4 * vec == vec)
		return C_2v;
	else if (mat_s_125 * vec == vec or mat_s_135 * vec == vec or mat_s_145 * vec == vec or mat_s_234 * vec == vec)
		return C_s;
	else
		return C_1;
	/*
	if (mat_c3_1 * vec == vec and mat_c2_2 * vec == vec)
		return D_3h;
	else
	{
		if (mat_c3_1 * vec == vec)
			return C_3v;
		else
		{
			if (mat_c2_2 * vec == vec or mat_c2_3 * vec == vec or mat_c2_4 * vec == vec)
				return C_2v;
			else
			{
				if (mat_s_125 * vec == vec or mat_s_135 * vec == vec or mat_s_145 * vec == vec or mat_s_234 * vec == vec)
					return C_s;
				else
					return C_1;
			}

		}
	}
	*/
}


Group tetrahedral_identifier(Vector<4> vec)
{
	Matrix<4> mat_c3_1{ {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0} };
	Matrix<4> mat_c3_2{ {0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0} };
	Matrix<4> mat_c3_3{ {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0} };
	Matrix<4> mat_c3_4{ {0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1} };
	Matrix<4> mat_c2_12{ {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0} };
	Matrix<4> mat_c2_13{ {0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0} };
	Matrix<4> mat_c2_14{ {0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0} };

	if (mat_c3_1 * vec == vec and mat_c3_2 * vec == vec and mat_c3_3 * vec == vec and mat_c3_3 * vec == vec and mat_c3_4 * vec == vec)
		return T_d;
	else if (mat_c3_1 * vec == vec or mat_c3_2 * vec == vec or mat_c3_3 * vec == vec or mat_c3_3 * vec == vec or mat_c3_4 * vec == vec)
		return C_3v;
	else if (mat_c2_12 * vec == vec or mat_c2_13 * vec == vec or mat_c2_14 * vec == vec)
		return C_2v;
	else
		return C_1;
	/*
	if (mat_c3_1 * vec == vec and mat_c3_2 * vec == vec and mat_c3_3 * vec == vec and mat_c3_3 * vec == vec and mat_c3_4 * vec == vec)
		return T_d;
	else
	{
		if (mat_c3_1 * vec == vec or mat_c3_2 * vec == vec or mat_c3_3 * vec == vec or mat_c3_3 * vec == vec or mat_c3_4 * vec == vec)
			return C_3v;
		else
		{
			if (mat_c2_12 * vec == vec or mat_c2_13 * vec == vec or mat_c2_14 * vec == vec)
				return C_2v;
			else
				return C_1;
		}
	}
	*/
}

Group trigonal_planar_identifier(Vector<3> vec)
{
	//Matrix naming convention given by mat_cN_x where N is the order of the rotation that is equivallent to I and x is the axis of rotation.
	Matrix<3> mat_c3{ {0, 1, 0, 0, 0, 1, 1, 0, 0} };
	Matrix<3> mat_c2_1{ {1, 0, 0, 0, 0, 1, 0, 1, 0} };
	Matrix<3> mat_c2_2{ {0, 0, 1, 0, 1, 0, 1, 0, 0} };
	Matrix<3> mat_c2_3{ {0, 1, 0, 1, 0, 0, 0, 0, 1} };

	if (mat_c3 * vec == vec)
	{
		return D_3h;
	}
	else if (mat_c2_1 * vec == vec or mat_c2_2 * vec == vec or mat_c2_3 * vec == vec)
		return C_2h;
	else
		return C_s;
	/*
	else
	{
		if (mat_c2_1 * vec == vec or mat_c2_2 * vec == vec or mat_c2_3 * vec == vec)
			return C_2h;
		else
			return C_s;
	}
	*/
}

Group linear_identifier(Vector<2> vec)
{
	Matrix<2> mat{ {0, 1, 1, 0} };
	if (mat * vec == vec)
		return D_infinityh;
	else
		return C_infinityv;
}

int main()
{
	std::cout << "Creating Window\n";
	Window* pWindow = new Window();

	bool running = true;

	while (running)
	{
		if (!pWindow->ProcessMessages())
		{
			std::cout << "Closing Window\n";
			running = false;
		}

		Sleep(10);
	}

	delete pWindow;

	return 0;
}