#pragma once

#ifndef IO_H
#define IO_H


#include <stdio.h>
#include <iostream>
#include "ext/json.hpp"
#include "Authenticator.h"
#ifdef _WIN32

#include <Windows.h>
#include <thread>
#include "Table.h"

#elif __linux__

#endif // _WIN32

#define MAX_RECVBUF_SIZE 512
#define MAX_CONNECTION_MESSAGE_SIZE 64
#define MAX_SEND_MESSAGE 64


#define EXIT_CODE_WSA_ERROR 001
#define EXIT_CODE_SOCKET_CREATION_ERROR 002
#define EXIT_CODE_BIND_ERROR 003
#define EXIT_CODE_LISTEN_ERROR 004

using json = nlohmann::json;
static Table TABLE;

class ClientSocket {

public:
	void processClient(
#ifdef _WIN32
		SOCKET passdata, SOCKADDR_IN sAddr,
#elif __linux__

#endif 
		int cnum);




	ClientSocket();

private:

	SOCKET _client;
	char recvbuf[MAX_RECVBUF_SIZE];
	char connectionMSG[MAX_CONNECTION_MESSAGE_SIZE];
	char sendmsg[MAX_SEND_MESSAGE];

	int sret;
	int iResult;
};

class IO
{

private:
#ifdef _WIN32

	SOCKADDR_IN sAddr;
	sockaddr_in server, client;
	WSADATA wData;
	SOCKET tmpSocket, serverSocket;
	//struct sockaddr_in server, client;

	ClientSocket _cs;
	Authenticator _at;
	int cnum;
	int myport;
	int addrLen;
	int tmpRet;

#elif __linux__


#endif

public:

	void errorBox(char *text);
	void loop();
	IO(int _port);
	~IO();
};



#endif

