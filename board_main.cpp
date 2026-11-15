// Vjezba 6, zadatak 4: napisite klasu Board iznad main.

#include <iostream>

// ovdje napisite klasu Board
class Board
{
    int nrows;
    int ncols;
    char* elem;
public:
    Board(int rows, int cols, char rub)
        : nrows(rows), ncols(cols), elem(new char[nrows * cols])
    {
        for (int i = 0; i < nrows; i++)
        {
            for (int j = 0; j < ncols; j++)
            {
                if (i == 0 || i == nrows - 1 || j == 0 || j == ncols - 1)
                {
                    elem[i * ncols + j] = rub;
                }
                else
                {
                    elem[i * ncols + j] = ' ';
                }
            }
        }
    }
    Board(const Board& other)
        : nrows(other.nrows), ncols(other.ncols), elem(new char[other.nrows * other.ncols])
    {
        for (int i = 0; i < nrows * ncols; i++)
        {
            elem[i] = other.elem[i];
        }
    }
    ~Board()
    {
        delete[] elem;
    }

    void set(int i, int j, char ch)
    {
        if (i > 0 && i < nrows - 1 && j > 0 && j < ncols - 1)
        {
            elem[i * ncols + j] = ch;
        }
    }

    char get(int i, int j) const { return elem[i * ncols + j]; }
    int rows() const { return nrows; }
    int cols() const { return ncols; }

    void print() const
    {
        for (int i = 0; i < nrows; i++)
        {
            for (int j = 0; j < ncols; j++)
            {
                std::cout << elem[i * ncols + j];
            }
            std::cout << "\n";
        }
    }
};

int main()
{
    Board b(4, 8, '#');
    b.set(1, 2, '@');
    Board copy = b;          // copy konstruktor
    copy.set(2, 5, '*');
    copy.set(0, 0, '!');     // rub se ne mijenja
    b.print();
    copy.print();
    std::cout << copy.rows() << ' ' << copy.cols() << ' '
              << copy.get(2, 5) << '\n';
    return 0;
}

/*
Ocekivani ispis:

    ########
    # @    #
    #      #
    ########
    ########
    # @    #
    #    * #
    ########
    4 8 *
*/
