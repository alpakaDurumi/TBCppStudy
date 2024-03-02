// https://www.boost.org/doc/libs/1_84_0/doc/html/boost_asio/tutorial/tutdaytime1.html

#include <iostream>
#include <string>
#include <array>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

// argument로 서버의 주소 입력받기
int main(int argc, char* argv[]) {
	try {
		if (argc != 2) {
			std::cerr << "Usage : client <host>" << std::endl;
			return 1;
		}
		// All programs that use asio need to have at least one I/O execution context, such as an io_context object.
		boost::asio::io_context io_context;

		// We need to turn the server name that was specified as a parameter to the application, into a TCP endpoint. To do this we use an ip::tcp::resolver object.
		tcp::resolver resolver(io_context);

		// A resolver takes a host name and service name and turns them into a list of endpoints. We perform a resolve call using the name of the server, specified in argv[1], and the name of the service, in this case "daytime".
		tcp::resolver::results_type endpoints = resolver.resolve(argv[1], "daytime");

		// 소켓을 생성하고 연결한다.
		tcp::socket socket(io_context);
		boost::asio::connect(socket, endpoints);

		for (;;) {
			std::array<char, 128> buf;
			boost::system::error_code error;

			size_t len = socket.read_some(boost::asio::buffer(buf), error);

			// 서버가 닫힌 경우, 루프를 빠져나온다.
			if (error == boost::asio::error::eof) {
				break;	// Connection closed cleanly by peer.
			}
			else if (error) {
				throw boost::system::system_error(error);	// some other error.
			}
			std::cout.write(buf.data(), len);
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}