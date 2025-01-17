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



void fileCopy(std::string path, std::string destination)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
	int col = 9;
	std::ifstream firstFile(path.c_str(), std::ios::binary);
	if (firstFile)
	{
		std::ifstream isDestination(destination.c_str());
		if (isDestination)
		{
			std::cout << "file already exist, Do you want to replace ? [Yes / No] : ";
			std::string choice;
			std::cin >> choice;
			if (choice == "Y" || choice == "yes" || choice == "Yes" || choice == "YES" || choice == "y")
			{
				isDestination.close();
				std::ofstream destinationFile(destination.c_str(), std::ios::binary);
				std::string line;
				while (getline(firstFile, line))
				{
					destinationFile << line << std::endl;
				}
				destinationFile.flush();
				destinationFile.close();
				
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				printf("done!!!\n");
				col = 11;
				SetConsoleTextAttribute(hConsole, col);
			}
			else
			{
				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("ERROR ==> 944\n");
				col = 11;
				SetConsoleTextAttribute(hConsole, col);
				isDestination.close();
			}
		}
		else
		{
			isDestination.close();
			std::ofstream destinationFile(destination.c_str(), std::ios::binary);
			std::string line;
			while (getline(firstFile, line))
			{
				destinationFile << line << std::endl;
			}
			destinationFile.flush();
			destinationFile.close();
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
		}
		firstFile.close();
	}
	else
	{
		col = 4;
		SetConsoleTextAttribute(hConsole, col);
		printf("ERROR ==> 327\n");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
	}
}

void Build()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
	int col = 9;
	std::string something = "";
	bool openPort = false;

	std::cout << "\n\n";


	col = 8;
	SetConsoleTextAttribute(hConsole, col);
	printf("Host: ");
	col = 11;
	SetConsoleTextAttribute(hConsole, col);
	std::cin >> something;
	col = 8;
	SetConsoleTextAttribute(hConsole, col);
	printf("Port: ");
	col = 11;
	SetConsoleTextAttribute(hConsole, col);
	std::cin >> something;
	std::ifstream file(Modules::prefrences);
	if (file.is_open())
	{
		std::string line;
		while (getline(file, line))
		{
			if (line == something)
			{
				openPort = true;
			}
		}
	}
	else
	{

		col = 4;
		SetConsoleTextAttribute(hConsole, col);
		printf("Fatal ERROR!!!");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
	}
	file.close();
	if (openPort)
	{
		col = 8;
		SetConsoleTextAttribute(hConsole, col);
		printf("size KayLogs: ");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
		std::cin >> something;
		col = 8;
		SetConsoleTextAttribute(hConsole, col);
		printf("Name: ");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
		std::cin >> something;
		col = 8;
		SetConsoleTextAttribute(hConsole, col);
		printf("hide? (y/n) ");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
		std::cin >> something;
		col = 8;
		std::cout << "\n";
		SetConsoleTextAttribute(hConsole, col);
		printf("building...\n");
		printf("[");
		for (int i = 0; i <= 60; i++) 
		{
			printf("=");
			Sleep(500*(i/10));
		}
		printf("]\n\n");
		printf("checking...\n");
		printf("[");
		for (int i = 0; i <= 60; i++)
		{
			printf("=");
			Sleep(100);
		}
		printf("]\n\n");

		fileCopy("resources/stub.exe", "built/HeatRAT.exe");
		std::string version = "4.0.0";
		std::string log = "built\\log.txt";
		srand(time(0));
		std::ofstream file(log, std::ios::app);
		if (file.is_open())
		{
			file << "HeatRAT v"<< version << " builded\nBuild num: "<< 10000000 +  rand() % (99999999 - 10000000 - 1)<< "\nbuild status: success\n===============================" << std::endl;
		}
		else
		{

			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("Error with logging!!!\n");
		}
		file.close();


	}
	else
	{

		col = 4;
		SetConsoleTextAttribute(hConsole, col);
		printf("port %s is not open!!!", something.c_str());
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
	}


	std::cout << "\n\n";

}

