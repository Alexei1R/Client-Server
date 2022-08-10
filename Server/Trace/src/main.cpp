#include "pch.h"
#include "Server.h"

void main()
{
	Log::Log::Init();
	Net::Server server(1234);
	server.Start();

	std::string data;
	while (true)
	{
		data.clear();
		data = server.Recive();
		LOG_INFO("{0}",data)
		server.Sent(data);
	}


}