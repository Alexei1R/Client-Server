#include "pch.h"
#include "Server.h"


namespace Net
{
	Server::Server(unsigned int port)
		:m_port(port)
	{
	
	
	}
	Server::~Server()
	{
		// Close the socket
		closesocket(m_ClientSocket);

		// Cleanup winsock
		WSACleanup();
	}
	void Server::Start()
	{
		m_wsOk = WSAStartup(m_ver, &m_wsData);
		if (m_wsOk != 0) LOG_CRITICAL("Can't Initialize winsock! Quitting value : {0}",m_wsOk);
		


		// Server SOCKET
		m_ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
		if (m_ServerSocket == INVALID_SOCKET) LOG_CRITICAL("Can't create a socket! Quitting ; \n Value Socket {0}", m_ClientSocket);

		m_ServerHint.sin_family = AF_INET;
		m_ServerHint.sin_port = htons(m_port);
		m_ServerHint.sin_addr.S_un.S_addr = INADDR_ANY;

		bind(m_ServerSocket, (sockaddr*)&m_ServerHint, sizeof(m_ServerHint));
		listen(m_ServerSocket, SOMAXCONN);



		// Client SOCKET

		int clientSize = sizeof(m_ClientHint);
		m_ClientSocket = accept(m_ServerSocket, (sockaddr*)&m_ClientHint, &clientSize);

		char host[1024];
		char service[64];
		memset(host, 0, sizeof(host));
		memset(service, 0, sizeof(service));

		//close server socket;
		closesocket(m_ServerSocket);

	}
	std::string Server::Recive()
	{
		char buf[4096];
		memset(buf, 0, sizeof(buf));

		
		int RecivedBytes = 0;
		RecivedBytes = recv(m_ClientSocket,buf,sizeof(buf),0);

		std::string data = std::string(buf, 0, RecivedBytes);
		return data;
	}
	bool Server::Sent(std::string msg)
	{
		int size = msg.size();
		
		send(m_ClientSocket, msg.c_str(), sizeof(msg), 0);
		return true;
	}
}