#include <iostream>

int	main(int argc, char *argv[])
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < argc; i++)
        {
            int j = 0;
            while (argv[i][j] != '\0')
            {
                std::cout << (char)std::toupper(argv[i][j]);
                j++;
            }
            if (i < argc - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}
