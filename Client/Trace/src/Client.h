#include <string>


namespace Net
{
	class Client
	{
	public:

		Client(std::string ipAddress, unsigned int port);
		~Client();
		void Connect();
		std::string Recive();
		bool Sent(std::string msg);


	private:

		WSADATA m_Data;
		WORD m_ver = MAKEWORD(2, 2);
		int m_wsResult;


		SOCKET m_Socket;
		sockaddr_in m_SocketHint;




	private:
		unsigned int m_port;
		std::string m_ipAddress;
	};

}