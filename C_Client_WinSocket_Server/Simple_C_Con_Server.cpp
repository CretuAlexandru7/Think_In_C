#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>     /* IP address conversions functionality */

#pragma comment(lib, "ws2_32.lib")   /* Link required library */

int main(int argc, char* argv[])
{
	WSADATA wsaData;
	SOCKET clientSocket;
	struct sockaddr_in serverAddress;
	const char* serverIpAddress = "127.0.0.1"; // Change this to the IP address of your Python server
	int serverPort = 6666; // Change this to the port number of your Python server

	// Initialize Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("WSAStartup failed. Error Code : %d", WSAGetLastError());
		return 1;
	}

	// Create a socket
	if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
		return 1;
	}

	// Set up the server address
	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(serverPort);
	inet_pton(AF_INET, serverIpAddress, &serverAddress.sin_addr);

	// Connect to the server
	if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
	{
		printf("connect failed. Error Code : %d", WSAGetLastError());
		return 1;
	}

	// Send a message to the server
	const char* message = "Hello!";
	if (send(clientSocket, message, strlen(message), 0) < 0)
	{
		printf("Send failed. Error Code : %d", WSAGetLastError());
		return 1;
	}

	// Close the socket and clean up Winsock
	closesocket(clientSocket);
	WSACleanup();

	return 0;
}
