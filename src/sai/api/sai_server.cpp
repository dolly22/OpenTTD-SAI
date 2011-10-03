/** @file sa_server.cpp SA API implementation of SAIServer */

#include "sai_server.hpp"
#include "sai_client.hpp"
#include "../../string_func.h"
#include "../../core/alloc_func.hpp"
#include "../../network/network_base.h"
#include "../../network/network_func.h"
#include "../../console_func.h"
#include "../../company_func.h"
#include "../../company_base.h"
#include "../../command_type.h"
#include "../../command_func.h"


/* static */ void SAIServer::Say(const char* msg)
{
	if (!StrEmpty(msg))
		NetworkServerSendChat(NETWORK_ACTION_CHAT, DESTTYPE_BROADCAST, NULL, msg, CLIENT_ID_SERVER, NULL);
}

/* static */ void SAIServer::SayClient(SAIClient::ClientID client, const char* msg)
{
	if (!SAIClient::IsValid(client))
		return;

	if (!StrEmpty(msg))
		NetworkServerSendChat(NETWORK_ACTION_CHAT_CLIENT, DESTTYPE_CLIENT, client, msg, CLIENT_ID_SERVER, NULL);
}

/* static */ void SAIServer::SayCompany(SAICompany::CompanyID company, const char* msg)
{
	if (!SAICompany::IsValid(company))
		return;

	if (!StrEmpty(msg))
		NetworkServerSendChat(NETWORK_ACTION_CHAT_COMPANY, DESTTYPE_TEAM, company, msg, CLIENT_ID_SERVER, NULL);
}

/* static */ void SAIServer::ConsoleCmd(const char* command)
{
	::IConsoleCmdExec(command);
}

/* static */ void SAIServer::ExecuteCommand(TileIndex tile, uint32 p1, uint32 p2, uint32 cmd, const char* text) {
	SAIServer::ExecuteCommandEx(tile, p1, p2, cmd, text, _current_company);
}


/* static */ void SAIServer::ExecuteCommandEx(TileIndex tile, uint32 p1, uint32 p2, uint32 cmd, const char* text, CompanyID company) {
	/* NetworkSendCommand needs _local_company to be set correctly, so
	 * adjust it, and put it back right after the function */
	::NetworkSendCommand(tile, p1, p2, cmd, NULL, text, company);
}