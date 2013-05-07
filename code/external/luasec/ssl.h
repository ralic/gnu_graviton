#ifndef __SSL_H__
#define __SSL_H__

/*--------------------------------------------------------------------------
 * LuaSec 0.4.1
 * Copyright (C) 2006-2011 Bruno Silvestre
 *
 *--------------------------------------------------------------------------*/

#include <openssl/ssl.h>
#include <lua.h>

// Using luasocket headers
/*
#include "io.h"
#include "buffer.h"
#include "timeout.h"
#include "context.h"
#include "socket.h"
*/
#include "../luasocket/io.h"
#include "../luasocket/buffer.h"
#include "../luasocket/timeout.h"
#include "context.h"
#include "../luasocket/socket.h"

#define ST_SSL_NEW       1
#define ST_SSL_CONNECTED 2
#define ST_SSL_CLOSED    3

typedef struct t_ssl_ {
  t_socket sock;
  t_io io;
  t_buffer buf;
  t_timeout tm;
  SSL *ssl;
  char state;
  int error;
} t_ssl;
typedef t_ssl* p_ssl;

LUASEC_API int luaopen_ssl_core(lua_State *L);

#endif
