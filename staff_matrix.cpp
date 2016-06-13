#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

class RealMatrix
{
	int N = 0;
	int M = 0;
	double** arr = nullptr;
public:
	RealMatrix() = default;

	RealMatrix(int N_, int M_) : N(N_), M(M_), arr(new double*[N_])
	{
		for (int i = 0; i < N_; ++i)
			arr[i] = new double[M_];
	}

	RealMatrix(const RealMatrix& obj) : RealMatrix(obj.N, obj.M)
	{
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				arr[i][j] = obj.arr[i][j];
	}

	int get_N()
	{
		return N;
	}

	int get_M()
	{
		return M;
	}

	double& index(int i, int j)
	{
		return arr[i][j];
	}

	double** get_arr()
	{
		return arr;
	}

	RealMatrix operator+(RealMatrix& obj)
	{
		int hei, len;
		if (N > obj.N) hei = N;
		else hei = obj.N;
		if (M > obj.M) len = M;
		else len = obj.M;
		RealMatrix new_obj(hei, len);
		for (int i = 0; i < hei; ++i)
			for (int j = 0; j < len; ++j)
				new_obj.arr[i][j] = arr[i][j] + obj.arr[i][j];
		return new_obj;
	}

	RealMatrix operator+=(const RealMatrix& obj)
	{
		int hei, len;
		if (N > obj.N) hei = N;
		else hei = obj.N;
		if (M > obj.M) len = M;
		else len = obj.M;
		double** new_arr = new double*[hei];
		for (int i = 0; i < hei; ++i)
			new_arr[i] = new double[len];
		for (int i = 0; i < hei; ++i)
			for (int j = 0; j < len; ++j)
				new_arr[i][j] = arr[i][j] + obj.arr[i][j];
		for (int i = 0; i < N; ++i)
			delete[] arr[i];
		delete[] arr;
		arr = new_arr;
		return *this;
	}

	RealMatrix operator-(RealMatrix& obj)
	{
		int hei, len;
		if (N > obj.N) hei = N;
		else hei = obj.N;
		if (M > obj.M) len = M;
		else len = obj.M;
		RealMatrix new_obj(hei, len);
		for (int i = 0; i < hei; ++i)
			for (int j = 0; j < len; ++j)
				new_obj.arr[i][j] = arr[i][j] - obj.arr[i][j];
		return new_obj;
	}

	RealMatrix operator-=(const RealMatrix& obj)
	{
		int hei, len;
		if (N > obj.N) hei = N;
		else hei = obj.N;
		if (M > obj.M) len = M;
		else len = obj.M;
		double** new_arr = new double*[hei];
		for (int i = 0; i < hei; ++i)
			new_arr[i] = new double[len];
		for (int i = 0; i < hei; ++i)
			for (int j = 0; j < len; ++j)
				new_arr[i][j] = arr[i][j] - obj.arr[i][j];
		for (int i = 0; i < N; ++i)
			delete[] arr[i];
		delete[] arr;
		arr = new_arr;
		return *this;
	}

	RealMatrix operator/(RealMatrix& obj)
	{
		int hei, len;
		if (N > obj.N) hei = N;
		else hei = obj.N;
		if (M > obj.M) len = M;
		else len = obj.M;
		RealMatrix new_obj(hei, len);
		for (int i = 0; i < hei; ++i)
			for (int j = 0; j < len; ++j)
				new_obj.arr[i][j] = arr[i][j] / obj.arr[i][j];
		return new_obj;
	}

	RealMatrix operator/(const double a)
	{
		RealMatrix new_obj(N, M);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				new_obj.arr[i][j] = arr[i][j] / a;
		return new_obj;
	}

	RealMatrix operator/=(const RealMatrix& obj)
	{
		int hei, len;
		if (N > obj.N) hei = N;
		else hei = obj.N;
		if (M > obj.M) len = M;
		else len = obj.M;
		double** new_arr = new double*[hei];
		for (int i = 0; i < hei; ++i)
			new_arr[i] = new double[len];
		for (int i = 0; i < hei; ++i)
			for (int j = 0; j < len; ++j)
				new_arr[i][j] = arr[i][j] / obj.arr[i][j];
		for (int i = 0; i < N; ++i)
			delete[] arr[i];
		delete[] arr;
		arr = new_arr;
		return *this;
	}

	RealMatrix operator*(RealMatrix& obj)
	{
		int hei, len;
		if (N > obj.N) hei = N;
		else hei = obj.N;
		if (M > obj.M) len = M;
		else len = obj.M;
		RealMatrix new_obj(hei, len);
		for (int i = 0; i < hei; ++i)
			for (int j = 0; j < len; ++j)
				new_obj.arr[i][j] = arr[i][j] * obj.arr[i][j];
		return new_obj;
	}

	RealMatrix operator*(const double a)
	{
		RealMatrix new_obj(N, M);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				new_obj.arr[i][j] = arr[i][j] * a;
		return new_obj;
	}

	RealMatrix operator*=(const RealMatrix& obj)
	{
		int hei, len;
		if (N > obj.N) hei = N;
		else hei = obj.N;
		if (M > obj.M) len = M;
		else len = obj.M;
		double** new_arr = new double*[hei];
		for (int i = 0; i < hei; ++i)
			new_arr[i] = new double[len];
		for (int i = 0; i < hei; ++i)
			for (int j = 0; j < len; ++j)
				new_arr[i][j] = arr[i][j] * obj.arr[i][j];
		for (int i = 0; i < N; ++i)
			delete[] arr[i];
		delete[] arr;
		arr = new_arr;
		return *this;
	}

	RealMatrix operator=(const RealMatrix& obj)
	{
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				arr[i][j] = obj.arr[i][j];
		return *this;
	}

	bool operator==(const RealMatrix obj)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
				if (arr[i][j] != obj.arr[i][j]) return 0;
				else continue;
		}
		return 1;
	}

	bool operator!=(const RealMatrix obj)
	{
		return !operator==(obj);
	}

	RealMatrix& in_pow(const int a)
	{
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				arr[i][j] = pow(arr[i][j], a);
		return *this;
	}

	RealMatrix& transp()
	{
		double** ar_;
		int n_ = M;
		int m_ = N;
		ar_ = new double*[n_];
		for (int i = 0; i < n_; ++i)
			ar_[i] = new double[m_];
		for (int i = 0; i < n_; ++i)
		{
			for (int j = 0; j < m_; ++j)
			{
				ar_[i][j] = arr[j][i];
			}
		}
		for (int i = 0; i < N; ++i)
			delete[] arr[i];
		delete[] arr;
		arr = ar_;
		M = n_;
		N = m_;
		return (*this);
	}

	double determinant()
	{
		double det = 0;
		if (N == 2 && M == 2)
		{
			det = arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
			cout << "Determinant = " << det << endl;
			return det;
		}

		if (N == 3 && M == 3)
		{
			det = arr[0][0] * arr[1][1] * arr[2][2] - arr[0][0] * arr[1][2] * arr[2][1]
				- arr[0][1] * arr[1][0] * arr[2][2] + arr[0][1] * arr[1][2] * arr[2][0]
				+ arr[0][2] * arr[1][0] * arr[2][1] - arr[0][2] * arr[1][1] * arr[2][0];
			cout << "Determinant = " << det << endl;
			return det;
		}
		cerr << "wrong matrix" << endl;
		return -1;
	}

	void norm_matrix()
	{
		double counter, norm = 0;
		for (int i = 0; i < N; i++)
		{
			counter = 0;
			for (int j = 0; j < M; j++)
				counter += abs(arr[j][i]);
			if (counter > norm)
				norm = counter;
		}
		cout << " Norma = " << norm << endl;
	}

	friend ostream& operator<<(ostream& out, const RealMatrix& obj);

	friend istream& operator>>(istream& in, RealMatrix& obj);

	int is_square()
	{
		if (N == M) return 1;
		else return 0;
	}

	int is_null()
	{
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				if (arr[i][j] != 0) return 0;
			}
		return 1;
	}

	int is_diagonal()
	{
		if (is_square() && is_null()) return 1;
		if (!is_square()) return 0;
		if (is_square())
		{
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j)
				{
					if (arr[i][j] == 0) continue;
					if (i != j) return 0;
				}
			return 1;
		}
	}

	int is_unit()
	{
		if (!is_square()) return 0;
		if (is_square())
		{
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j)
				{
					if (i != j) continue;
					if (i == j && arr[i][j] == 1) continue;
					else return 0;
				}
			return 1;
		}
	}

	int is_symmetrical()
	{
		if (is_null()) return 1;
		if (!is_square()) return 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (arr[i][j] != arr[j][i]) return 0;
		return 1;
	}

	int is_top_triangular()
	{
		if (!is_square()) return 0;
		if (M == 2, N == 2)
		{
			if (arr[1][0] == 0) return 1;
			else return 0;
		}
		if (M == 3, N == 3)
		{
			if (arr[1][0] == 0 && arr[2][0] == 0 && arr[2][1] == 0) return 1;
			else return 0;
		}
		cerr << "Wrong matrix" << endl;
		return -1;
	}

	int is_bottom_triangular()
	{
		if (!is_square()) return 0;
		if (M == 2, N == 2)
		{
			if (arr[0][1] == 0) return 1;
			else return 0;
		}
		if (M == 3, N == 3)
		{
			if (arr[0][1] == 0 && arr[0][2] == 0 && arr[1][2] == 0) return 1;
			else return 0;
		}
		cerr << "Wrong matrix" << endl;
		return -1;
	}

	RealMatrix back_matrix()
	{
		double det = 0;
		if (M == 2 && N == 2)
		{
			det = determinant();
			swap(arr[0][1], arr[1][0]);
			arr[0][1] *= (-1);
			arr[1][0] *= (-1);
			transp();
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j)
					arr[i][j] /= det;
			return *this;
		}
		if (M == 3 && N == 3)
		{
			det = determinant();
			double** new_arr = new double*[N];
			for (int i = 0; i < N; ++i)
				new_arr[i] = new double[M];
			new_arr[0][0] = arr[2][2] * arr[1][1] - arr[1][2] * arr[2][1];
			new_arr[0][1] = arr[1][0] * arr[2][2] - arr[2][0] * arr[1][2];
			new_arr[0][2] = arr[1][0] * arr[2][1] - arr[2][0] * arr[1][1];
			new_arr[1][0] = arr[0][1] * arr[2][2] - arr[0][2] * arr[2][1];
			new_arr[1][1] = arr[0][0] * arr[2][2] - arr[0][2] * arr[2][0];
			new_arr[1][2] = arr[0][0] * arr[2][1] - arr[2][0] * arr[0][1];
			new_arr[2][0] = arr[0][1] * arr[1][2] - arr[0][2] * arr[1][2];
			new_arr[2][1] = arr[0][0] * arr[1][2] - arr[1][0] * arr[2][2];
			new_arr[2][2] = arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
			for (int i = 0; i < N; ++i)
				delete[] arr[i];
			delete[] arr;
			arr = new_arr;
			arr[1][0] *= (-1);
			arr[1][2] *= (-1);
			arr[0][1] *= (-1);
			arr[2][1] *= (-1);
			transp();
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j)
					arr[i][j] /= det;
			return *this;
		}
		cerr << "Wrong matrix" << endl;
		return RealMatrix();
	}

	~RealMatrix()
	{
		for (int i = 0; i < N; ++i)
			delete[] arr[i];
		delete[] arr;
	}

};

ostream& operator<<(ostream& out, const RealMatrix& obj)
{
	for (int i = 0; i < obj.N; ++i)
	{
		for (int j = 0; j < obj.M; ++j)
			out << obj.arr[i][j] << " ";
		out << endl;
	}

	return out;
}

istream& operator>>(istream& in, RealMatrix& obj)
{

	for (int i = 0; i < obj.N; ++i)
		for (int j = 0; j < obj.M; ++j)
			in >> obj.arr[i][j];

	return in;
}

void init(RealMatrix& obj)
{
	for (int i = 0; i < obj.get_N(); ++i)
		for (int j = 0; j < obj.get_M(); ++j)
		{
			if (i != j) obj.get_arr()[i][j] = rand() % 30 - 15;
			else obj.get_arr()[i][j] = 1;
		}
}

int main()
{
	int val = 0;
	char key;
	srand(unsigned(time(NULL)));
	RealMatrix obj0(3, 3);
	RealMatrix obj1(3, 3);
	RealMatrix obj2(3, 3);
	init(obj0);
	init(obj1);
	init(obj2);
	cout << "Menu: \n"
		<< "a.Addition\n"
		<< "b.Subtraction\n"
		<< "s.Multiplication\n"
		<< "d.Degree\n"
		<< "e.Add on\n"
		<< "f.Multiply\n"
		<< "h.Divide\n"
		<< "i.Take away\n"
		<< "n.Compare\n"
		<< "g.Involution\n"
		<< "k.Transpose\n"
		<< "l.Invert\n"
		<< "m.Show the determinant\n"
		<< "j.Show the norm\n"
		<< "o.Check type\n"
		<< "p.Show the matrix\n" << endl;
	cin >> key;
	switch (key)
	{
	case 'a':
		obj0 = obj1 + obj2;
		break;
	case 'b':
		obj0 = obj1 - obj2;
		break;
	case 's':
		obj0 = obj1 * obj2;
		break;
	case 'd':
		obj0 = obj1 / obj2;
		break;
	case 'e':
		obj0 += obj1;
		break;
	case 'f':
		obj0 *= obj1;
		break;
	case 'h':
		obj0 /= obj1;
		break;
	case 'i':
		obj0 -= obj1;
		break;
	case 'n':
		if (obj0 == obj1) cout << "Matrix are equal." << endl;
		else cout << "Matrix are not equal." << endl;
		break;
	case 'g':
		cout << "Enter value: " << endl;
		cin >> val;
		obj0.in_pow(val);
		break;
	case 'k':
		obj0.transp();
		break;
	case 'l':
		obj0.back_matrix();
		break;
	case 'm':
		obj0.determinant();
		break;
	case 'j':
		obj0.norm_matrix();
		break;
	case 'o':
		if (obj0.is_square()) cout << "Is square." << endl;
		else cout << "Is not square." << endl;
		if (obj0.is_null()) cout << "Is null." << endl;
		else cout << "Is not null." << endl;
		if (obj0.is_diagonal()) cout << "Is diagonal." << endl;
		else cout << "Is not diagonal." << endl;
		if (obj0.is_unit()) cout << "Is unit." << endl;
		else cout << "Is not unit." << endl;
		if (obj0.is_symmetrical()) cout << "Is symmetrical." << endl;
		else cout << "Is not symmetrical." << endl;
		if (obj0.is_top_triangular()) cout << "Is top triangular." << endl;
		else cout << "Is not top triangular." << endl;
		if (obj0.is_bottom_triangular()) cout << "Is bottom triangular." << endl;
		else cout << "Is not bottom triangular." << endl;
		break;
	case 'p':
		cout << obj0;
		break;

	default: cout << "Wrong operation!" << endl;
	}


	return 0;
}