#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main() {
	try {
		boost::asio::io_service io_service;

		tcp::endpoint endpoint(tcp::v4(), 13);			// 매개변수는 각각 버전, 포트 넘버
		tcp::acceptor acceptor(io_service, endpoint);

		std::cout << "Server started" << std::endl;

		for (;;) {		// 클라이언트가 제대로 접속할 때까지 계속 반복
			const std::string message_to_send = "Hello From Server";
			
			boost::asio::ip::tcp::iostream stream;

			std::cout << "check 1" << std::endl;

			boost::system::error_code ec;
			acceptor.accept(*stream.rdbuf(), ec);

			std::cout << "check 2" << std::endl;

			if (!ec) {	// TODO : How to take care of multiple clients? Multi-threading?
				// receive message from client
				std::string line;
				std::getline(stream, line);
				std::cout << line << std::endl;

				// send message to client
				stream << message_to_send;
				stream << std::endl;			// send std::endl to end getline of client
			}
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}