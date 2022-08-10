#include <string>


namespace Net
{
	class Server
	{
	public:

		Server(unsigned int port);
		~Server();
		void Start();
		std::string Recive();
		bool Sent(std::string msg);


	private:

		WSADATA m_wsData;
		WORD m_ver = MAKEWORD(2, 2);
		int m_wsOk;


		SOCKET m_ServerSocket;
		sockaddr_in m_ServerHint;

		SOCKET m_ClientSocket;
		sockaddr_in m_ClientHint;



	private:
		unsigned int m_port;
	};

}