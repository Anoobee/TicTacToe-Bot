// This is our backend/defination file

#include"../inc/head.hpp"
static int  one_move = 0;
template <class T>
void display(std::vector<T> &v) // this is display function, this displays the 9 element of
// vector in TicTacToe structure
{

    int a = 0, b = 0, c = 0;

    std::cout 
         << "  " << v[1] << "  "
         << "|"
         << " " << v[2] << "  "
         << "|"
         << "  " << v[3] << " " << std:: endl;
    std::cout << "----------------" << std:: endl;
    std::cout << "  " << v[4] << "  "
         << "|"
         << " " << v[5] << "  "
         << "|"
         << "  " << v[6] << " " <<std:: endl;
    std:: cout << "----------------" << std::endl;
    std::cout << "  " << v[7] << "  "
         << "|"
         << " " << v[8] << "  "
         << "|"
         << "  " << v[9] << " " << std::endl;

    std::cout << std::endl;
}
bool win(std::vector<int> &v)
{

    // row check

    if ((v[1] == v[2] && v[3] == v[2] && v[2] != 0) || (v[5] == v[4] && v[5] == v[6] && v[6] != 0) || (v[7] == v[8] && v[8] == v[9] && v[9] != 0))
        return true;

    // column check
    if ((v[1] == v[4] && v[4] == v[7] && v[1] != 0) || (v[2] == v[5] && v[5] == v[8] && v[8] != 0) || (v[3] == v[6] && v[6] == v[9] && v[9] != 0))
        return true;

    // 1st diagonal check
    if ((v[1] == v[5] && v[5] == v[9] && v[9] != 0))
        return true;

    // 2nd diagonal check
    if ((v[7] == v[5] && v[5] == v[3] && v[3] != 0))
        return true;
    else
        return false;
}

// checking the draw condition
bool draw(std::vector<int> &v)
{
    int i;
    for (i = 1; i < 10; i++)
    {
        if (v[i] == 0)
        {
            return false;
        }
    }
    return true;
}

int MoveGenerator(std::vector<int> vec)
{

    for (int i = 1; i < 10; i++)
    { // last move generator
        if (vec[i] == 0)
        {
            vec[i] = 1;
            if (win(vec) == true)
            {

                return i;
            }
            vec[i] = 2;
            if (win(vec) == true)
            {

                return i;
            }
            vec[i] = 0;
        }
    }
    // first move generator
    if (vec[5] == 0 and one_move == 0)
    {
        one_move++;
        return 5;
    }
    // generating the priority
    return vec[1] == 0 ? 1 : (vec[9] == 0 ? 9 : (vec[7] == 0 ? 7 : (vec[3] == 0 ? 3 : (vec[5] == 0 ? 5 : (vec[2] == 0 ? 2 : (vec[4] == 0 ? 4 : 6))))));
};
int play()
{
     int position_X; // store the poision for X
    int position_O; // store the poision for O

    std::vector<char> vec1(10, ' '); // creating vector of size 10 with every elememnt ' '
    // here we have created vector with 10 element but we will no use 0th element
    std:: vector<int> vec2(10); // this vector will store the data for occupied poisiton
    // vector<char>::iterator iter = vec1.begin();

    while (1)
    {
        system("CLS"); // clear screen

        display(vec1);
    entry_X:
        std::cout << "Enter any position (1-9) to set X" <<std:: endl;
        std::cin >> position_X;

        // invalid check

        if (position_X > 9 || position_X < 1)
        {
            std::cout 
                 << "Invalid entry "
                 <<std:: endl;
            goto entry_X;
        }
        // available poistion check
        if (vec2[position_X] != 0)
        {
           std:: cout << "Occupied" << std::endl;

            goto entry_X;
        }
        vec2[position_X] = 1;

        vec1[position_X] = 'X';
        display(vec1);
        // win check

        if (win(vec2) == true)
        {
           std:: cout 
                 << "X is the winner"
               
                 << std::endl;
            break;
        }
        // draw check
        if (draw(vec2) == true)
        {
            std::cout << "The game is draw" << std::endl;
            break;
        }

    entry_O:
        // cin >> position_O;
        position_O = MoveGenerator(vec2);

        // invalid check
        if (position_O > 9 || position_O < 1)
        {
            std::cout 
                 << "Invalid entry "
                 << std::endl;
            goto entry_O;
        }
        // available poistion check
        if (vec2[position_O] != 0)
        {
            std::cout << "Occupied" << std::endl;
            display(vec1);
            goto entry_O;
        }

        vec2[position_O] = 2;

        vec1[position_O] = 'O';
        // win check
        if (win(vec2) == true)
        {
            std::cout 
                 << "O is the winner"
                 << std::endl;
            break;
        }
        // draw check
        if (draw(vec2) == true)
        {
            std::cout 
                 << "The game is draw"
                 << std::endl;

            break;
        }
    }

    std::cout << "end";
    system("pause>nul"); // same as getch
    // getch();
}