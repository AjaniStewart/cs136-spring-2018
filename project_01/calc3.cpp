#include <iostream> // for cin

int main()
{
    int result, num;    //declare result, num
    char cur_op, last_op = '+'; //math operators, first num is positive
    result = 0;
    std::cin >> num; //stream first one
   
    //stream into cur_op
    while (std::cin >> cur_op)
    {
        //add if op is ^
        if (cur_op == '^')
        {
            //square num
            num = num * num;
            //get next op
            std::cin >> cur_op;
        }
        //if the previous op is +
        if (last_op == '+')
            result += num;
        //if the previous op is -
        else if (last_op == '-')
            result -= num;
        //the current opertor is now the previous one
        last_op = cur_op;
        //read the next number
        std::cin >>num;
        //if the op is ;
        if (last_op == ';')
        {
            //print out the result
            std::cout << result << '\n';
            //reinitialize result
            result = 0;
            //reset last_op
            last_op = '+';
        }   
    }
    return 0;
}