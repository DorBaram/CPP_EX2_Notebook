/**
 * Notebook Exercise
 *
 * Author: Dor Baram
 * Since : 2022-03
 */
#include <iostream>
#include <string>
using namespace std;

#include "Notebook.hpp"
using namespace ariel;

ariel::Notebook::Notebook()
{
}

void ariel::Notebook::write(int page, int row, int col, Direction dire, string const &str)
{
    int strl = str.length();
    validator(page, row, col, dire, strl, strl);
    for (unsigned int i = 0; i < strl; i++)
    {
        if (str[i] < MIN_C || str[i] > MAX_C)
        {
            throw invalid_argument("invalid input");
        }
    }
    if (strl == 0)
    {
        return;
    }

    if (dire == Direction::Horizontal)
    {
        for (int i = col, j = 0; i < col + strl; i++, j++)
        {
            char tmp = notebook[page][row][i].d;
            if (tmp == '~')
            {
                throw invalid_argument("cant write on an erased word");
            }
            if (MIN_C < tmp && tmp < MAX_C)
            {
                if (tmp == '_')
                {
                    notebook[page][row][i].d = str[(unsigned int)j];
                }
                else
                {
                    throw invalid_argument("cant write on this word");
                }
            }
            else
            {
                notebook[page][row][i].d = str[(unsigned int)j];
            }
        }
    }
    else
    {
        for (int i = row, j = 0; i < row + strl; i++, j++)
        {
            char tmp = notebook[page][i][col].d;
            if (tmp == '~')
            {
                throw invalid_argument("cant write on an erased word");
            }
            if (MIN_C < tmp && tmp < MAX_C)
            {
                if (tmp == '_')
                {
                    notebook[page][i][col].d = str[(unsigned int)j];
                }
                else
                {
                    throw invalid_argument("cant write on this word");
                }
            }
            else
            {
                notebook[page][i][col].d = str[(unsigned int)j];
            }
        }
    }
}

string ariel::Notebook::read(int page, int row, int col, Direction dire, int amount)
{
    validator(page, row, col, dire, amount, amount);
    string str;
    if (dire == Direction::Horizontal)
    {
        for (int i = col; i < amount + col; i++)
        {
            char tmp = notebook[page][row][i].d;
            str += tmp;
        }
    }
    else
    {
        for (int i = row; i < amount + row; i++)
        {
            char tmp = notebook[page][i][col].d;
            str += tmp;
        }
    }
    return str;
}

void ariel::Notebook::erase(int page, int row, int col, Direction dire, int amount)
{
    validator(page, row, col, dire, amount, amount);
    if (dire == Direction::Horizontal)
    {
        for (int i = col; i < amount + col; i++)
        {
            notebook[page][row][i].d = '~';
        }
    }
    else
    {
        for (int i = row; i < amount + row; i++)
        {
            notebook[page][i][col].d = '~';
        }
    }
}

void ariel::Notebook::show(int page)
{
    validator(page, 0, 0, Direction::Horizontal, 0, 0);
    cout << notebook[page][0][0].d << endl;
}

void ariel::validator(int page, int row, int col, Direction dire, int strl, int pos)
{
    if (page < 0 || row < 0 || col < 0 || pos < 0)
    {
        throw invalid_argument("numbers must be positive or zero");
    }
    if (col >= MAX_ROW)
    {
        throw invalid_argument("invalid coloum");
    }

    if ((dire == Direction::Horizontal) && (col + strl > MAX_ROW))
    {
        throw invalid_argument("invalid string or coloum");
    }
}