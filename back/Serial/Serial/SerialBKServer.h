#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include"MVGevSource.h"

#include<Winsock2.h>
#include<vector>
#include<thread>
#include<mutex>
#include<iostream>


using namespace std;

#pragma comment(lib,"ws2_32.lib")

#define DATA_LEN 16

class SerialBKServer
{
public:
	SerialBKServer(shared_ptr<CMvGevSource> camera, shared_ptr<mutex> mtx);
	~SerialBKServer();
	const int port = 986;

	void start();
private:
	SOCKET listen_socket;
	SOCKET communicate_socket;
	thread *listen_thread = nullptr;
	thread *communicate_thread = nullptr;

	shared_ptr<mutex> _mtx;
	//shared_ptr<int> _x, _y;
	shared_ptr<CMvGevSource> _camera;

	void ListenThread();
	void CommunicateThread(LPVOID lparam);

	//Ll Lm Ml MM
	void  intToByte(int i, char *bytes);
	//Ll Lm Ml MM
	unsigned int  ByteToint(char *bytes);

};


