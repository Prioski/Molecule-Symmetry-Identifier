res[1] = (mat[1][0] * obj[0]) + (mat[1][1] * obj[1]);
return res;
	}

	std::array<int, 2> operator[](int obj) const
	{
		return mat[obj];
	}
	std::array<int, 2>& operator[](int obj)
	{
		return mat[obj];
	}

	void print()
	{
		std::cout << mat[0][0] << " " << mat[1][0] << '\n' << mat[0][1] << " " << mat[1][1];
	}
};



int main()
{
	Vector2D vect(1, 2);
	Matrix2D matrix(1, 0, 0, 1);
	Vector2D result = matrix * vect;
	if (vect == result)
		std::cout << "Equivallent" << '\n';
	else
		std::cout << "Different" << '\n';
	result.print();
	return 0;
}