/*
Copyright (c) 2012-2013, Politecnico di Milano. All rights reserved.

Andrea Zoppi <texzk@email.it>
Martino Migliavacca <martino.migliavacca@gmail.com>

http://airlab.elet.polimi.it/
http://www.openrobots.com/

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
 * @file    urosHandlers.h
 * @author  Yukihiro Saito<yukky@ubi.cs.ritsumei.ac.jp>
 *
 * @brief   TCPROS topic and service handlers.
 */

#ifndef _UROSHANDLERS_H_
#define _UROSHANDLERS_H_

/*===========================================================================*/
/* HEADER FILES                                                              */
/*===========================================================================*/

#include "urosMsgTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/*===========================================================================*/
/* PUBLISHED TOPIC PROTOTYPES                                                */
/*===========================================================================*/

/*~~~ PUBLISHED TOPIC: /rosout ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

uros_err_t pub_tpc__rosout(UrosTcpRosStatus *tcpstp);

/*~~~ PUBLISHED TOPIC: /vlp_16 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

uros_err_t pub_tpc__vlp_16(UrosTcpRosStatus *tcpstp);

/*===========================================================================*/
/* SUBSCRIBED TOPIC PROTOTYPES                                               */
/*===========================================================================*/

/* There are no subscribed topics.*/

/*===========================================================================*/
/* PUBLISHED SERVICE PROTOTYPES                                              */
/*===========================================================================*/

/* There are no published services.*/

/*===========================================================================*/
/* CALLED SERVICE PROTOTYPES                                                 */
/*===========================================================================*/

/* There are no called services.*/

/*===========================================================================*/
/* GLOBAL PROTOTYPES                                                         */
/*===========================================================================*/

void urosHandlersPublishTopics(void);
void urosHandlersUnpublishTopics(void);

void urosHandlersSubscribeTopics(void);
void urosHandlersUnsubscribeTopics(void);

void urosHandlersPublishServices(void);
void urosHandlersUnpublishServices(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _UROSHANDLERS_H_ */

