#include "pch.h"
#include "Client.h"


namespace Net
{
	Client::Client(std::string ipAddress, unsigned int port)
		:m_ipAddress(ipAddress), m_port(port)
	{


	}
	Client::~Client()
	{
		// Close the socket
		closesocket(m_Socket);

		// Cleanup winsock
		WSACleanup();
	}
	void Client::Connect()
	{
		m_wsResult = WSAStartup(m_ver, &m_Data);
		if (m_wsResult != 0) { LOG_CRITICAL("Can't Initialize winsock! Quitting value : {0}", m_wsResult) };



		// Client SOCKET
		m_Socket = socket(AF_INET, SOCK_STREAM, 0);
		if (m_Socket == INVALID_SOCKET) LOG_CRITICAL("Can't create a socket! Quitting ; \n Value Socket {0}", m_Socket);

		m_SocketHint.sin_family = AF_INET;
		m_SocketHint.sin_port = htons(m_port);
		inet_pton(AF_INET, m_ipAddress.c_str(), &m_SocketHint.sin_addr);

		

		//conect to server
		int connResult = connect(m_Socket, (sockaddr*)&m_SocketHint, sizeof(m_SocketHint));
		if (connResult == SOCKET_ERROR) {LOG_CRITICAL("Can't connect to server") }
		

	}
	std::string Client::Recive()
	{
		char buf[4096];
		memset(buf, 0, sizeof(buf));

		int RecivedBytes = 0;
		RecivedBytes = recv(m_Socket, buf, sizeof(buf), 0);

		std::string data = std::string(buf, 0, RecivedBytes);
		return data;
	}
	bool Client::Sent(std::string msg)
	{
		int size = msg.size();

		send(m_Socket, msg.c_str(), sizeof(msg), 0);
		return true;
	}
}