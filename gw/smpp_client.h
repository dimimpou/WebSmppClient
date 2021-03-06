/* ==================================================================== 
 * The Kannel Software License, Version 1.0 
 * 
 * Copyright (c) 2001-2013 Kannel Group  
 * Copyright (c) 1998-2001 WapIT Ltd.   
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 * 
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 * 
 * 2. Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in 
 *    the documentation and/or other materials provided with the 
 *    distribution. 
 * 
 * 3. The end-user documentation included with the redistribution, 
 *    if any, must include the following acknowledgment: 
 *       "This product includes software developed by the 
 *        Kannel Group (http://www.kannel.org/)." 
 *    Alternately, this acknowledgment may appear in the software itself, 
 *    if and wherever such third-party acknowledgments normally appear. 
 * 
 * 4. The names "Kannel" and "Kannel Group" must not be used to 
 *    endorse or promote products derived from this software without 
 *    prior written permission. For written permission, please  
 *    contact org@kannel.org. 
 * 
 * 5. Products derived from this software may not be called "Kannel", 
 *    nor may "Kannel" appear in their name, without prior written 
 *    permission of the Kannel Group. 
 * 
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
 * DISCLAIMED.  IN NO EVENT SHALL THE KANNEL GROUP OR ITS CONTRIBUTORS 
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 * ==================================================================== 
 * 
 * This software consists of voluntary contributions made by many 
 * individuals on behalf of the Kannel Group.  For more information on  
 * the Kannel Group, please see <http://www.kannel.org/>. 
 * 
 * Portions of this software are based upon software originally written at  
 * WapIT Ltd., Helsinki, Finland for the Kannel project.  
 */ 

/*
 * bearerbox.h
 *
 * General typedefs and functions for bearerbox
 */

#include "gwlib/gwlib.h"
#include "msg.h"
#include "smscconn.h"

/* Default outgoing queue length */
#define DEFAULT_OUTGOING_SMS_QLENGTH    1000000

/* general bearerbox state */

enum {
    RUNNING = 0,
    SHUTDOWN = 1,
    DEAD = 2
};


/* type of output given by various status functions */
enum {
    STATUS_HTML = 0,
    STATUS_TEXT = 1,
    STATUS_WML  = 2,
    STATUS_XML  = 3,
	STATUS_JSON = 4
};

typedef struct {
	Octstr *smpp_id;
	Octstr *smpp_host;
	Octstr *sys_type;
	Octstr *system_id;
	Octstr *passwd;
	long transmit_port;
	int receiver_port;
	int transportation_type;
} SmppConn;

typedef struct {
	Octstr *sender;
	Octstr *receiver;
	Octstr *data_coding;
	Octstr *message;
} MsgBody;

/*---------------
 * smpp_http.c (HTTP Admin)
 */
int httpadmin_start(Cfg *config);
void httpadmin_stop(void);

Octstr *print_status(List *cgivars, int status_type);
Octstr *print_homepage(List *cgivars, int status_type);
Octstr *smpp_connect(SmppConn *smpp_conn);

void smpp_smscconn_failed(Octstr *error);
void smpp_smscconn_connected(Octstr *stat);
int smpp_smscconn_stop(void);
int smpp_smscconn_status(void);
void send_message(MsgBody *msg_vars);

