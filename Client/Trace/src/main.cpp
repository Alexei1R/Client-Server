#include "pch.h"
#include "Client.h"

void main()
{
	Log::Log::Init();
	Net::Client client("127.0.0.1", 1234);
	//Net::Client client("86.107.67.159", 1234);
	client.Connect();

	std::string val;
	std::string userInput;

	while (true)
	{
		do
		{
			getline(std::cin, userInput);


			client.Sent(userInput);
			val.clear();
			val = client.Recive();
			LOG_INFO("{0}", val)
		} while (userInput.size() > 0);

	}
}